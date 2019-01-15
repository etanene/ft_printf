/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:48:31 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/15 12:42:37 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_s(t_options options, int *str)
{
	int		len;
	char	*s;
	int		bytes;
	int		utf;

	len = 0;
	bytes = 0;
	utf = 0;
	while (options.width - options.prec > len)
	{
		ft_putchar(' ');
		len++;
	}
	if (options.spec == 's')
	{
		s = (char*)str;
		while (*s && options.prec--)
		{
			len++;
			ft_putchar(*s++);
		}
	}
	else
	{
		while (*str)
		{
			bytes = ft_convert_utf32_utf8(*str++, (char*)&utf);
			ft_print_unicode(utf, bytes);
		}
	}
	return (len);
}