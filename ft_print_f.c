/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:21:14 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/29 20:25:38 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_options_f(t_options *opt, int *len, t_fnum_div fnum_div)
{
	if (fnum_div.fnum.f < 0)
		opt->flags[F_PLUS] = 1;
	*len = ft_unumlen(fnum_div.ipart, 10);
	if (opt->flags[F_PLUS])
		opt->flags[F_SP] = 0;
	if (opt->flags[F_PLUS] || opt->flags[F_SP])
		*len += 1;
	if (opt->flags[F_MINUS])
		opt->flags[F_NULL] = 0;
	if (opt->prec == -1)
		opt->prec = 6;
	opt->width -= *len + opt->prec;
}

int		ft_print_ipart_fpart(t_options opt, t_fnum_div fnum_div)
{
	int		len;

	ft_reset_options_f(&opt, &len, fnum_div);
	if (opt.flags[F_SP])
		ft_putchar(' ');
	else if (opt.flags[F_PLUS] && (opt.flags[F_NULL] || opt.flags[F_MINUS]))
		ft_putchar(fnum_div.fnum.f < 0 ? '-' : '+');       
	if (opt.flags[F_NULL])
		len += ft_print_width(opt.width, '0');
	else if (!opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	if (opt.flags[F_PLUS] && !(opt.flags[F_NULL] || opt.flags[F_MINUS]))
		ft_putchar(fnum_div.fnum.f < 0 ? '-' : '+');
	ft_printnum(fnum_div.ipart, 10);
	ft_putchar('.');
	while (opt.prec--)
	{
		fnum_div.fpart *= 10;
		if (opt.prec == 0 && (((fnum_div.fpart & 0x1FFFFFFFFFFFFF) * 10) >> 53) >= 5)
			ft_putchar((fnum_div.fpart >> 53) + 1 + '0');
		else
			ft_putchar((fnum_div.fpart >> 53) + '0');
		len++;
		fnum_div.fpart &= 0x1FFFFFFFFFFFFF;
	}
	if (opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	return (len + 1);
}

void	ft_reset_bigint(t_bigint *bigint)
{
	int		i;

	i = 0;
	while (i < MAX_INDEX)
		bigint->num[i++] = 0;
	bigint->size = 0;
}

void	ft_set_bigint(t_bigint *bigint, int power)
{
	int		num;
	int		count;
	int		last_pow;
	int		temp;

	count = 0;
	num = 1ULL << MAX_POWER;
	if (power >= MAX_POWER)
		count = power / MAX_POWER;
	last_pow = power % MAX_POWER;
	temp = count;
	if (count)
	{
		bigint->num[0] += num;
		count--;
	}
	else
		bigint->num[0] += 1ULL << last_pow;
	bigint->size = 1;
	while (count)
	{
		ft_bigint_multi_int(bigint, num);
		count--;
	}
	if (temp)
		ft_bigint_multi_int(bigint, 1ULL << last_pow);
}

int		ft_print_ipart_bigint(t_options opt, t_fnum_div fnum_div)
{
	t_bigint	res_bigint;
	t_bigint	temp_bigint;
	int			power;

	ft_reset_bigint(&res_bigint);
	ft_reset_bigint(&temp_bigint);
	power = 0;
	opt.prec = 0;
	while (power < COUNT_BITS)
	{
		if (ft_checkbit(fnum_div.mantissa, power))
		{
			ft_set_bigint(&temp_bigint, fnum_div.exponent - 52 + power);
			ft_bigint_sum_bigint(&res_bigint, &temp_bigint);
			ft_reset_bigint(&temp_bigint);
		}
		power++;
	}
	return (ft_print_bigint(&res_bigint));
}

int		ft_parse_f(t_options opt, double num)
{
	t_fnum_div			fnum_div;
	int					len;

	fnum_div.fnum.f = num;
	fnum_div.exponent = ((fnum_div.fnum.ll >> 52) & 0x7FF) - 1023;
	fnum_div.mantissa = (fnum_div.fnum.ll & 0x1FFFFFFFFFFFFF) | 0x10000000000000;
	fnum_div.ipart = 0;
	fnum_div.fpart = 0;
	len = 0;
	if (fnum_div.exponent >= 52)
	{
		len = ft_print_ipart_bigint(opt, fnum_div);
	}
	else if (fnum_div.exponent >= 0)
	{
		fnum_div.ipart = fnum_div.mantissa >> (52 - fnum_div.exponent);
		fnum_div.fpart = (fnum_div.mantissa << (fnum_div.exponent + 1)) & 0x1FFFFFFFFFFFFF;
		len = ft_print_ipart_fpart(opt, fnum_div);
	}
	else
	{
		fnum_div.fpart = (fnum_div.mantissa & 0x1FFFFFFFFFFFFF) >> -(fnum_div.exponent + 1);
		len = ft_print_ipart_fpart(opt, fnum_div);
	}
	return (len);
}
