/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:35:23 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/02 22:19:20 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_correct_fpart_bigint(t_bigint *bigint)
{
	int			i;
	t_bigint	max_bigint;
	t_bigint	temp_bigint;

	i = 1;
	max_bigint = ft_get_bigint(ULLONG_MAX, 0);
	temp_bigint = ft_get_bigint(1UL << 63, i++);
	while (ft_bigint_compare(bigint, &temp_bigint) > 0)
		temp_bigint = ft_get_bigint(1UL << 63, i++);
	while (ft_bigint_compare(bigint, &max_bigint) > 0)
	{
		if (ft_bigint_compare(bigint, &temp_bigint) > 0)
			ft_bigint_minus_bigint(bigint, &temp_bigint);
		ft_bigint_div_int(&temp_bigint, 2);
	}
}
int		ft_check_next_prec_lf(t_bigint bigint)
{
	int		shift;

	shift = 64;
	ft_correct_fpart_bigint(&bigint);
	ft_bigint_multi_int(&bigint, 10);
	while (shift--)
		ft_bigint_div_int(&bigint, 2);
	return (bigint.num[0]);
}

int		ft_print_prec_lf(int prec, t_fnum_div fnum_div)
{
	int			len;
	int			shift;
	t_bigint	fpart_bigint;
	t_bigint	temp_bigint;

	len = 0;
	ft_putchar('.');
	fpart_bigint = ft_get_bigint(fnum_div.fpart, 0);
	while (prec--)
	{
		shift = 64;
		ft_bigint_multi_int(&fpart_bigint, 10);
		temp_bigint = fpart_bigint;
		while (shift--)
			ft_bigint_div_int(&temp_bigint, 2);
		if (prec == 0 && ft_check_next_prec_lf(fpart_bigint) >= 5)
			ft_putchar(temp_bigint.num[0] + 1 + '0');
		else
			ft_putchar(temp_bigint.num[0] + '0');
		ft_correct_fpart_bigint(&fpart_bigint);
		len++;
	}
	return (len + 1);
}

int		ft_parse_lf(t_options opt, long double num)
{
	t_fnum_div	fnum_div;
	int			len;

	len = 0;
	fnum_div.fnum.lf = num;
	fnum_div.exponent = (*(&fnum_div.fnum.ll + 1) & 0x7FFF) - 16383;
	fnum_div.mantissa = fnum_div.fnum.ll;
	fnum_div.ipart = 0;
	fnum_div.fpart = 0;
	if (fnum_div.exponent >= 64)
	{
		len = ft_print_ipart_bigint(opt, fnum_div);
	}
	else if (fnum_div.exponent >= 0)
	{
		fnum_div.ipart = fnum_div.mantissa >> (63 - fnum_div.exponent);
		fnum_div.fpart = fnum_div.mantissa << (fnum_div.exponent + 1);
		len = ft_print_ipart_fpart(opt, fnum_div, ft_print_prec_lf);
	}
	// else if (fnum_div.exponent == 0)
	// {

	// }
	
	return (len);
}
