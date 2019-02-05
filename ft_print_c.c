/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:15:20 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/05 19:29:02 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_convert_utf32_utf8(int utf32, char *p)
{
	int		bytes;

	bytes = 0;
	if (++bytes && utf32 <= 0x7F)
		*p = utf32;
	else if (++bytes && utf32 <= 0x7FF)
	{
		*p = 0xC0 | (utf32 >> 6);
		*(p + 1) = 0x80 | (utf32 & 0x3F);
	}
	else if (++bytes && utf32 <= 0xFFFF)
	{
		*p = 0xE0 | (utf32 >> 12);
		*(p + 1) = 0x80 | ((utf32 >> 6) & 0x3F);
		*(p + 2) = 0x80 | (utf32 & 0x3F);
	}
	else if (++bytes && utf32 <= 0x10FFFF)
	{
		*p = 0xF0 | (utf32 >> 18);
		*(p + 1) = 0x80 | ((utf32 >> 12) & 0x3F);
		*(p + 2) = 0x80 | ((utf32 >> 6) & 0x3F);
		*(p + 3) = 0x80 | (utf32 & 0x3F);
	}
	return (*((int*)p) == 0 ? 1 : bytes);
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
	if (!options.flags[F_MINUS])
		len += ft_print_width(options.width - bytes, ' ');
	if (options.spec == 'c')
		ft_putchar(c);
	else
		ft_print_unicode(utf, bytes);
	if (options.flags[F_MINUS])
		len += ft_print_width(options.width - bytes, ' ');
	return (options.spec == 'C' ? len + bytes : len + 1);
}
