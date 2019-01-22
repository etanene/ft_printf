/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 20:42:05 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/22 21:12:43 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <math.h>
#include <fcntl.h>
#include <float.h>
//#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

int		ft_check_endian(void)
{
	short int	x;

	x = 1;
	return (*((char*)&x) == 0 ? 0 : 1);
}

int		ft_swap_bytes(int n)
{
	int		count;
	int		i;
	int		res;
	char	temp;
	char	*p;

	res = n;
	p = (char*)&res;
	i = 0;
	count = 0;
	while (i < 4)
	{
		if (*(p + i) != 0)
			count++;
		i++;
	}
	i = 0;
	while (--count > i)
	{
		temp = *(p + count);
		*(p + count) = *(p + i);
		*(p + i) = temp;
		i++;
	}
	return (res);
}

// int		ft_get_fpart(unsigned long fpart)
// {
// 	int		res;

// 	res = 0;
// 	while ()
// }

// int		ft_convert_utf32_utf8(int utf32, char *p)
// {
// 	if (utf32 <= 0x7F)
// 	{
// 		*p = utf32;
// 		return (1);
// 	}
// 	else if (utf32 <= 0x7FF)
// 	{
// 		*p = 0xC0 | (utf32 >> 6);
// 		*(p + 1) = 0x80 | (utf32 & 0x3F);
// 		return (2);
// 	}
// 	else if (utf32 <= 0xFFFF)
// 	{
// 		*p = 0xE0 | (utf32 >> 12);
// 		*(p + 1) = 0x80 | ((utf32 >> 6) & 0x3F);
// 		*(p + 2) = 0x80 | (utf32 & 0x3F);
// 		return (3);
// 	}
// 	else if (utf32 <= 0x10FFFF)
// 	{
// 		*p = 0xF0 | (utf32 >> 18);
// 		*(p + 1) = 0x80 | ((utf32 >> 12) & 0x3F);
// 		*(p + 2) = 0x80 | ((utf32 >> 6) & 0x3F);
// 		*(p + 3) = 0x80 | (utf32 & 0x3F);
// 		return (4);
// 	}
// 	return (0);
// }

// void	ft_print_c(int c)
// {
// 	int		bytes;
// 	int		utf;

// 	utf = 0;
// 	bytes = 0;
// 	bytes = ft_convert_utf32_utf8(c, (char*)&utf);
// 	if (!ft_check_endian())
// 		utf = ft_swap_bytes(utf);
// 	write(1, (char*)&utf, bytes);
// }

int		ft_get_ipart(unsigned long num, int exp)
{
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

void	ft_print_f(double num)
{
	unsigned long	*pnum;
	int				sign;
	int				ipart;
	int				fpart;
	int				exp;

	pnum = (unsigned long*)&num;
	exp = ((*pnum >> 52) ^ 0x800) - 1023;
	sign = ft_reversebits(*pnum) & 1UL;
	ipart = ft_get_ipart(*pnum, exp);
	fpart = ft_get_fpart(*pnum, exp);
}

int		main(void)
{
	long double lf = LDBL_MIN;
	ft_printbits(*((unsigned long*)&lf + 1), 64);
	ft_putchar(' ');
	ft_printbits(*((unsigned long*)&lf), 64);
	ft_putchar('\n');
	lf = LDBL_MAX;
	ft_printbits(*((unsigned long*)&lf + 1), 64);
	ft_putchar(' ');
	ft_printbits(*((unsigned long*)&lf), 64);
	ft_putchar('\n');
	lf = -5.5;
	ft_printbits(*((unsigned long*)&lf + 1), 64);
	ft_putchar(' ');
	ft_printbits(*((unsigned long*)&lf), 64);
	ft_putchar('\n');
	lf = 5.5;
	ft_printbits(*((unsigned long*)&lf + 1), 64);
	ft_putchar(' ');
	ft_printbits(*((unsigned long*)&lf), 64);
	ft_putchar('\n');
//	printf("lf: %Lf\nmax: %Lf\n", lf, LDBL_MAX);
	printf("fe: %Lf\n", LDBL_MIN);
	printf("fe: %Lf\n", LDBL_MAX);
}
