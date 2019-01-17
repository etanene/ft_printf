/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:48:31 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/17 19:07:45 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen_unicode(int *str)
{
	int		len;
	int		utf;

	len = 0;
	utf = 0;
	while (*str)
	{
		len += ft_convert_utf32_utf8(*str++, (char*)&utf);
	}
	return (len);
}

int		ft_print_s(t_options options, int *str)
{
	int		len;
	char	*s;
	int		bytes;
	int		utf;

	s = (char*)str;
	bytes = 0;
	utf = 0;
	len = 0;
	printf("\nprec: %d\n", options.prec);
	if (options.spec == 's')
	{
		len = ft_strlen(s);
		if (!options.flags[F_MINUS])
			len += ft_print_width(options.width, ' ');
		while (*s && options.prec--)
			ft_putchar(*s++);
		if (options.flags[F_MINUS])
			len += ft_print_width(options.width, ' ');
	}
	else
	{
		bytes = ft_strlen_unicode(str);
		if (!options.flags[F_MINUS])
			len += ft_print_width(options.width, ' ');
		write(1, (char*)str, bytes);
		if (options.flags[F_MINUS])
			len += ft_print_width(options.width, ' ');
	}
	return (len + bytes);
}