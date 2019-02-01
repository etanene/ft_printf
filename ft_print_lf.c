/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:35:23 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/01 16:20:50 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_prec_lf(int prec, t_fnum_div fnum_div)
{
	int			len;
	t_bigint	fpart_bigint;

	len = 0;
	prec = 10;
	ft_putchar('.');
	// printf("\nfpartdo: %llu\n", fnum_div.fpart);
	// ft_printbits(fnum_div.fpart, 64);
	// ft_putchar('\n');
	// fnum_div.fpart >>= (fnum_div.exponent + 1);
	// printf("\nfpartposle: %llu\n", fnum_div.fpart);
	// ft_printbits(fnum_div.fpart, 64);
	// ft_putchar('\n');
	// while (prec--)
	// {
		// printf("\nfpart: %llu\n", fnum_div.fpart);
		// ft_printbits(fnum_div.fpart, 64);
		// ft_putchar('\n');
		// fnum_div.fpart *= 10;
		// printf("\nfpart*10: %llu\n", fnum_div.fpart);
		// ft_printbits(fnum_div.fpart, 64);
		// ft_putchar('\n');
		// ft_putchar((fnum_div.fpart >> (63 - fnum_div.exponent)) + '0');
		// fnum_div.fpart &= (~0UL >> (fnum_div.exponent + 1));
		// len++;
	// }
	fpart_bigint = ft_get_bigint(fnum_div.fpart, 0);
	while (prec--)
	{
		ft_bigint_multi_int(&fpart_bigint, 10);
	}
	return (len + 1);
}

int		ft_parse_lf(t_options opt, long double num)
{
	t_fnum_div	fnum_div;
	int			len;

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
	fnum_div.ipart = 0;
	fnum_div.fpart = 0;
	// if (fnum_div.exponent >= 64)
	// {

	// }
	// else if (fnum_div.exponent >= 0)
	// {
		fnum_div.ipart = fnum_div.mantissa >> (63 - fnum_div.exponent);
		fnum_div.fpart = fnum_div.mantissa << (fnum_div.exponent + 1);
		len = ft_print_ipart_fpart(opt, fnum_div, ft_print_prec_lf);
	// }
	// else if (fnum_div.exponent == 0)
	// {

	// }
	
	return (len);
}
