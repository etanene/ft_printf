/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:15:20 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/15 16:09:54 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		ft_convert_utf32_utf8(int utf32, char *p)
{
	int		bytes;

	bytes = 0;
	if (utf32 <= 0x7F && ++bytes)
		*p = utf32;
	else if (utf32 <= 0x7FF && ++bytes)
	{
		*p = 0xC0 | (utf32 >> 6);
		*(p + 1) = 0x80 | (utf32 & 0x3F);
	}
	else if (utf32 <= 0xFFFF && ++bytes)
	{
		*p = 0xE0 | (utf32 >> 12);
		*(p + 1) = 0x80 | ((utf32 >> 6) & 0x3F);
		*(p + 2) = 0x80 | (utf32 & 0x3F);
	}
	else if (utf32 <= 0x10FFFF && ++bytes)
	{
		*p = 0xF0 | (utf32 >> 18);
		*(p + 1) = 0x80 | ((utf32 >> 12) & 0x3F);
		*(p + 2) = 0x80 | ((utf32 >> 6) & 0x3F);
		*(p + 3) = 0x80 | (utf32 & 0x3F);
	}
	return (bytes);
}

void	ft_print_unicode(int num, int bytes)
{
	if (!ft_check_endian())
		num = ft_swap_bytes(num);
	write(1, (char*)&num, bytes);
}

int		ft_print_c(t_options options, int c)
{
	int		bytes;
	int		utf;
	int		len;

	utf = 0;
	bytes = 0;
	len = 0;
	bytes = ft_convert_utf32_utf8(c, (char*)&utf);
	while (!options.flags[F_MINUS] && options.width - bytes > len)
	{
		ft_putchar(' ');
		len++;
	}
	if (options.spec == 'C')
		ft_print_unicode(utf, bytes);
	else
		ft_putchar(c);
	while (options.width - bytes > len)
	{
		ft_putchar(' ');
		len++;
	}
	return (options.spec == 'C' ? len + bytes : len + 1);
}
