/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 20:42:05 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/15 20:37:02 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
//#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

// int		ft_check_endian(void)
// {
// 	short int	x;

// 	x = 1;
// 	return (*((char*)&x) == 0 ? 0 : 1);
// }

// int		ft_swap_bytes(int n)
// {
// 	int		count;
// 	int		i;
// 	int		res;
// 	char	temp;
// 	char	*p;

// 	res = n;
// 	p = (char*)&res;
// 	i = 0;
// 	count = 0;
// 	while (i < 4)
// 	{
// 		if (*(p + i) != 0)
// 			count++;
// 		i++;
// 	}
// 	i = 0;
// 	while (--count > i)
// 	{
// 		temp = *(p + count);
// 		*(p + count) = *(p + i);
// 		*(p + i) = temp;
// 		i++;
// 	}
// 	return (res);
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

int		main(void)
{
	// int		c;
	// char	s[2] = {194, 162};
	// int		str[3] = {36817, 46790, 45773};
	// short int	x = 1;

	// printf("%s\n", *((char*)&x) == 0 ? "big-endian" : "little-endian");
	// setlocale(LC_ALL, "");
	// ft_printbits(27, 8);
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
	unsigned long r = 241241;
	printf("size: %zu\n", sizeof(long long));
	ft_printbits(r, 64);
	
	//printf("\nnum: %d\n", r);

	return (0);
}
