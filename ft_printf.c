/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:43:01 by afalmer-          #+#    #+#             */
/*   Updated: 2018/12/30 20:41:41 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnum(long long num, int type)
{
	unsigned long long	unum;


	unum = num < 0 ? -num : num;
	if (num < 0)
		ft_putchar('-');
	if (unum >= 10)
		ft_printnum(unum / 10);
	ft_putchar(unum % 10 + '0');
}

int     ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
				ft_printnum(va_arg(ap, int), SIGNED);
			else if (*format == 'u')
				ft_printnum(va_arg(ap, unsigned int), UNSIGNED);
			else if (*format == 'c')
				ft_putchar(va_arg(ap, int));
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (1);
}
