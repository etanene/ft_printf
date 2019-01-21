/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 20:42:05 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/21 20:36:52 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <math.h>
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
	{
		res *= num;
	}
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
	// int		c;
	// char	s[2] = {194, 162};
	// int		str[3] = {36817, 46790, 45773};
	// short int	x = 1;

	// printf("%s\n", *((char*)&x) == 0 ? "big-endian" : "little-endian");
	// setlocale(LC_ALL, "");
	// ft_printbits(-100, 8);
	// ft_putchar('\n');
	// c = 4036993206;
	// c = 14788256;
	// c = 51852;
	// c = 1421;
	// printf("%C\n", c);
	// printf("%C\n", L'ʌ');
	// ft_print_c(L'ʌ');
	// ft_print_c(c);
	// printf("hello: %-10.5C\n", L'ʌ');
	// unsigned long r = 241241;
	// printf("size: %zu\n", sizeof(long long));
	// ft_printbits(r, 64);
	
	//printf("\nnum: %d\n", r);

	// ssize_t byte;
	// char buf[255];

	// byte = read(43, buf, 10);
	// printf("byte: %z", byte);

	ft_print_f(-818.375);
	// printf("f: %zu Lf: %zu\n", sizeof(double), sizeof(long double));
	// printf("f: %zu Lf: %zu\n", sizeof(21.21), sizeof(21.21L));
	// printf("ll: %zu\n", sizeof(long long));

	// double			f = -818.375;
	// unsigned long	*ip;
	// unsigned long	*fp;
	// int				exp;
	// double			fres;
	// double			ipart;
	// double			fpart;
	// int				order;
	// unsigned long	temp;
	// int				sign;


	// ipart = f;
	// fpart = f;
	// ip = (unsigned long*)&ipart;
	// fp = (unsigned long*)&fpart;
	// ft_printbits(*fp, 64);
	// ft_putchar('\n');
	// ft_printbits(ft_reversebits(*fp), 64);
	// ft_putchar('\n');
	// ft_printbits(1UL, 64);
	// ft_putchar('\n');
	// sign = ft_reversebits(*fp) & 1UL;
	// printf("sign: %d\n", sign);
	// ft_printbits_double(ipart);
	// ft_putchar('\n');
	// exp = ((*ip >> 52) ^ 0x800) - 1023;
	// printf("exp: %d\n", exp);
	// *ip <<= 12;
	// ft_printbits_double(ipart);
	// ft_putchar('\n');
	// *ip >>= 64 - exp;
	// *ip |= 1UL << exp;
	// ft_printbits_double(ipart);
	// ft_putchar('\n');
	// printf("ipart: %d\n\n", *ip);
	
	// *fp <<= 12 + exp;
	// ft_printbits_double(fpart);
	// ft_putchar('\n');
	// ft_printbits(*fp, 64);
	// ft_putchar('\n');
	// *fp = ft_reversebits(*fp);
	// // while (!ft_checkbit(*fp, 0))
	// // {
	// // 	*fp >>= 1;
	// // }
	// ft_printbits_double(fpart);
	// ft_putchar('\n');
	// printf("fpart: %d\n", *fp);
	// order = 1;
	// temp = *fp;
	// while (*fp /= 2)
	// {
	// 	order++;
	// }
	// printf("order: %d\n", order);
	// exp = order;
	// while (order)
	// {
	// 	fres += (1 / (pow(2, order--))) * ft_checkbit(temp, order);
	// }
	// printf("fpart: %d\n", *fp);
	// printf("fres: %f\n", fres);
	// while (exp--)
	// {
	// 	fres *= 10;
	// }
	// printf("fres: %f\n", fres);
	// temp = fres;
	// printf("res: %d\n", temp);
	// return (0);
}
