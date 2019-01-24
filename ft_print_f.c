/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:21:14 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/24 20:22:40 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkbit_double(double n, int pos)
{
	unsigned long	*f;

	f = (unsigned long*)&n;
	return ((*f & (1UL << pos)) != 0);
}

void	ft_printbits_double(double n)
{
	int		count;

	count = 64;
	while (count--)
	{
		ft_putchar(ft_checkbit_double(n, count) + '0');
		if ((count == 63 || count == 52 || (count < 52 && count % 8 == 0)) && count)
			ft_putchar(' ');
	}
}

int		ft_checkbit(long n, int pos)
{
	return ((n & (1UL << pos)) != 0);
}

void	ft_printbits(long n, int count)
{
	while (count--)
	{
		ft_putchar(ft_checkbit(n, count) + '0');
		if (!(count % 8) && count)
			ft_putchar(' ');
	}
}

unsigned long	ft_reversebits(unsigned long num)
{
	unsigned long	res;
	int				count;

	count = 64;
	res = 0UL;
	while (count--)
	{
		res <<= 1UL;
		res |= 1UL & num;
		num >>= 1UL;
	}
	return (res);
}

// int		ft_get_ipart(unsigned long num, int exp)
// {
// 	printf("bit1: \n");
// 	ft_printbits(num, 64);
// 	ft_putchar('\n');
// 	num <<= 12;
// 	printf("bit2: \n");
// 	ft_printbits(num, 64);
// 	ft_putchar('\n');
// 	num >>= 64 - exp;
// 	printf("bit3: \n");
// 	ft_printbits(num, 64);
// 	ft_putchar('\n');
// 	if (num)
// 		num |= 1UL << exp;
// 	printf("bit4: \n");
// 	ft_printbits(num, 64);
// 	ft_putchar('\n');
// 	return (num);
// }

// double	ft_pow(int num, int pow)
// {
// 	double	res;

// 	res = 1;
// 	while (pow--)
// 		res *= num;
// 	return (res);
// }

// unsigned long long	ft_get_fpart(unsigned long num, int exp)
// {
// 	int		order;
// 	double	res;
// 	int		temp;
// 	int		i;

// 	printf("bit5: \n");
// 	ft_printbits(num, 64);
// 	ft_putchar('\n');
// 	num <<= 12 + exp;
// 	printf("bit6: \n");
// 	ft_printbits(num, 64);
// 	ft_putchar('\n');
// 	num = ft_reversebits(num);
// 	printf("bit6: \n");
// 	ft_printbits(num, 64);
// 	ft_putchar('\n');
// 	order = 1;
// 	temp = num;
// 	while (temp /= 2)
// 		order++;
// 	res = 0;

// 	//order = 10;
// 	printf("order: %d\n", order);
// 	exp = order;
// 	i = 0;
// 	while (i < order)
// 	{
// 		i++;
// 		res += (1 / (ft_pow(2, i))) * ft_checkbit(num, i - 1) * 10000000000000000000000000000000000000000000000.0;
// 		printf("res: %f i: %d\n", res, i);
// 	}
// 	// while (exp--)
// 	// 	res *= 10;
// 	return (res);
// }

// int		ft_print_f(t_options opt, double num)
// {
// 	unsigned long	*pnum;
// 	int				sign;
// 	int				ipart;
// 	int				fpart;
// 	int				exp;
// 	int				len;

// 	printf("\nnum: %f\n", num);
// 	ft_printbits_double(num);
// 	ft_putchar('\n');
// 	pnum = (unsigned long*)&num;
// 	printf("bit: \n");
// 	ft_printbits(*pnum, 64);
// 	ft_putchar('\n');
// 	exp = ((*pnum >> 52) & 0x7FF) - 1023;
// 	sign = ft_reversebits(*pnum) & 1UL;
// 	ipart = ft_get_ipart(*pnum, exp);
// 	printf("\nipart: %d\n", ipart);
// 	ft_printnum(ipart, 10);
// 	ft_putchar('.');
// 	fpart = ft_get_fpart(*pnum, exp);
// 	ft_printnum(fpart, 10);
// 	len = 5;
// 	opt.width = 3;
// 	return (len);
// }


typedef union	u_fnum
{
	double				f;
	unsigned long long	ll;
	float				fl;
}				t_fnum;

int		ft_print_f(t_options opt, double num)
{
	unsigned long long	mantissa;
	unsigned long long	ipart;
	unsigned long long	fpart;
	int					exponent;
	t_fnum				fnum;

	fnum.f = num;
	exponent = ((fnum.ll >> 52) & 0x7FF) - 1023;
	mantissa = (fnum.ll & 0x1FFFFFFFFFFFFF) | 0x10000000000000;
	ipart = 0;
	fpart = 0;
	if (exponent >= 52)
		ipart = mantissa << (exponent - 23);
	else if (exponent >= 0)
	{
		ipart = mantissa >> (52 - exponent);
		fpart = (mantissa << (exponent + 1)) & 0x1FFFFFFFFFFFFF;
	}
	else
		fpart = (mantissa & 0x1FFFFFFFFFFFFF) >> -(exponent + 1);
	ft_printnum(ipart, 10);
	ft_putchar('.');
	opt.prec = 6;
	while (opt.prec--)
	{
		fpart *= 10;
		ft_putchar((fpart >> 53) + '0');
		fpart &= 0x1FFFFFFFFFFFFF;
	}
	return (1);
}
