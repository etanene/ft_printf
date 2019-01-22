/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:21:14 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/22 21:35:56 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		ft_get_ipart(unsigned long num, int exp)
{
	ft_printbits(num, 64);
	printf("\nad\n");
	num <<= 12;
	num >>= 64 - exp;
	num |= 1UL << exp;
	return (num);
}

double	ft_pow(int num, int pow)
{
	double	res;

	res = 1;
	while (pow--)
		res *= num;
	return (res);
}

int		ft_get_fpart(unsigned long num, int exp)
{
	int		order;
	double	res;
	int		temp;

	num <<= 12 + exp;
	num = ft_reversebits(num);
	order = 1;
	temp = num;
	while (temp /= 2)
		order++;
	res = 0;
	exp = order;
	while (order)
	{
		res += (1 / (ft_pow(2, order))) * ft_checkbit(num, order - 1);
		order--;
	}
	while (exp--)
		res *= 10;
	return (res);
}

int		ft_print_f(t_options opt, double num)
{
	unsigned long	*pnum;
	int				sign;
	int				ipart;
	int				fpart;
	int				exp;
	int				len;

	printf("\nnum: %f\n", num);
	pnum = (unsigned long*)&num;
	exp = ((*pnum >> 52) & 0x7FF) - 1023;
	sign = ft_reversebits(*pnum) & 1UL;
	ipart = ft_get_ipart(*pnum, exp);
	printf("\nipart: %d\n", ipart);
	ft_printnum(ipart, 10);
	fpart = ft_get_fpart(*pnum, exp);
	ft_putchar('.');
	ft_printnum(fpart, 10);
	len = 5;
	opt.width = 3;
	return (len);
}
