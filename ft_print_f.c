/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:21:14 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/26 19:45:17 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_options_f(t_options *opt, int *len, unsigned long long unum)
{
	*len = ft_unumlen(unum, 10);
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

int		ft_print_f(t_options opt, double num)
{
	unsigned long long	mantissa;
	double				ipart;
	unsigned long long	fpart;
	int					exponent;
	t_fnum				fnum;
	int					len;

	fnum.f = num;
	
	exponent = ((fnum.ll >> 52) & 0x7FF) - 1023;
	mantissa = (fnum.ll & 0x1FFFFFFFFFFFFF) | 0x10000000000000;
	ipart = 0;
	fpart = 0;
	if (exponent >= 52)
	{
		// printf("HELLO\n");
		ipart = mantissa << (exponent - 23);
	}
	else if (exponent >= 0)
	{
		ipart = mantissa >> (52 - exponent);
		fpart = (mantissa << (exponent + 1)) & 0x1FFFFFFFFFFFFF;
	}
	else
		fpart = (mantissa & 0x1FFFFFFFFFFFFF) >> -(exponent + 1);
	if (num < 0)
		opt.flags[F_PLUS] = 1;
	ft_reset_options_f(&opt, &len, ipart);
	if (opt.flags[F_SP])
		ft_putchar(' ');
	else if (opt.flags[F_PLUS] && (opt.flags[F_NULL] || opt.flags[F_MINUS]))
		ft_putchar(num < 0 ? '-' : '+');
	if (opt.flags[F_NULL])
		len += ft_print_width(opt.width, '0');
	else if (!opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	if (opt.flags[F_PLUS] && !(opt.flags[F_NULL] || opt.flags[F_MINUS]))
		ft_putchar(num < 0 ? '-' : '+');
	ft_printnum_f(ipart);
	ft_putchar('.');
	while (opt.prec--)
	{
		fpart *= 10;
		if (opt.prec == 0 && (((fpart & 0x1FFFFFFFFFFFFF) * 10) >> 53) >= 5)
			ft_putchar((fpart >> 53) + 1 + '0');
		else
			ft_putchar((fpart >> 53) + '0');
		len++;
		fpart &= 0x1FFFFFFFFFFFFF;
	}
	if (opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	return (len + 1);
}
