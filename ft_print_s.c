/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:48:31 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/07 20:29:36 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen_unicode(int *str, int prec)
{
	int		len;
	int		i;

	len = 0;
	while (*str && prec)
	{
		i = 0;
		if (*str <= 0x7F && prec >= 1)
			i = 1;
		else if (*str <= 0x7FF && prec >= 2)
			i = 2;
		else if (*str <= 0xFFFF && prec >= 3)
			i = 3;
		else if (*str <= 0x10FFFF && prec >= 4)
			i = 4;
		if (prec < i)
		{
			while (prec < i)
				i--;
			len += i;
			break;
		}
		len += i;
		prec -= i;
		str++;
	}
	return (len);
}

int		ft_strlen_s(int *str, int prec)
{
	char	*s;
	int		len;

	s = (char*)str;
	len = 0;
	while (*s && prec--)
	{
		len++;
		s++;
	}
	return (len);
}

void	ft_puts(int *str, int prec)
{
	char	*s;

	s = (char*)str;
	while (*s && prec--)
		ft_putchar(*s++);
}

void	ft_puts_unicode(int *str, int prec)
{
	int		bytes;
	int		utf;

	bytes = 0;
	while (*str && prec)
	{
		bytes = ft_convert_utf32_utf8(*str++, (char*)&utf);
		if (prec >= bytes)
		{
			ft_print_unicode(utf, bytes);
			prec -= bytes;
		}
		else
			break ;
	}
}

int		ft_print_s(t_options opt, int *str, int (*ft_len)(int*, int), void (*ft_print)(int*, int))
{
	int		len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if ((len = ft_len(str, opt.prec)))
	{
		len = (opt.prec < 0 || len < opt.prec) ? len : opt.prec;
		opt.width = (opt.prec < 0 || len < opt.prec) ? opt.width - len : opt.width - opt.prec;
	}
	if (opt.flags[F_MINUS])
		opt.flags[F_NULL] = 0;
	if (opt.flags[F_NULL])
		len += ft_print_width(opt.width, '0');
	else if (!opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	ft_print(str, opt.prec);
	if (opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	return (len);
}
