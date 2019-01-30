/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:35:23 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/30 20:03:17 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_lf(t_options opt, long double num)
{
	t_fnum_div	fnum_div;
	int			len;
	int			powers[COUNT_BITS_LF];

	opt.prec = 6;
	powers[1] = 0;

	len = 0;
	fnum_div.fnum.lf = num;
	printf("\nnum: %Lf\n", fnum_div.fnum.lf);
	ft_printbits(*(&fnum_div.fnum.ll + 1), 64);
	ft_putchar(' ');
	ft_printbits(fnum_div.fnum.ll, 64);
	ft_putchar('\n');
	fnum_div.exponent = (*(&fnum_div.fnum.ll + 1) & 0x7FFF) - 16383;
	printf("\nexp: %d\n", fnum_div.exponent);
	ft_printbits(fnum_div.exponent, 64);
	ft_putchar('\n');
	fnum_div.mantissa = fnum_div.fnum.ll;
	printf("\nmantissa: %llu\n", fnum_div.mantissa);
	ft_printbits(fnum_div.mantissa, 64);
	ft_putchar('\n');
	// if (fnum_div.exponent >= 64)
	// {

	// }
	// else if (fnum_div.exponent > 0)
	// {
	// 	fnum_div.ipart = fnum_div.mantissa >> (64 - fnum_div.exponent);
	// }
	// else if (fnum_div.exponent == 0)
	// {

	// }
	fnum_div.ipart = 0;
	fnum_div.fpart = 0;
	return (len);
}
