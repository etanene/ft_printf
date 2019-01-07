/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:43:01 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/07 13:47:09 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


#include <stdio.h>

int			ft_handle_spec(t_options options, va_list ap)
{
	int		len;

	len = 0;
	if (options.spec == 'd' || options.spec == 'i')
		len = ft_parse_num(options, va_arg(ap, long long int), SIGN);
	else if (options.spec == 'u')
		len = ft_parse_unum(options, va_arg(ap, long long int), UNSIGN);
	return (len);
}

t_options	ft_set_options(const char **format)
{
	t_options	options;
	int			i;

	i = 0;
	while (i < 5)
		options.flags[i++] = 0;
	options.width = 0;
	options.prec = 0;
	options.length = 0;
	options.spec = 0;
	while (**format)
	{
		if (ft_set_spec(**format, &options))
			break;
		ft_set_flags(format, &options);
		ft_set_width(format, &options);
		ft_set_prec(format, &options);
		ft_set_length(format, &options);
	}
	return (options);
}

int			ft_printf(const char *format, ...)
{
	va_list 	ap;
	t_options	options;
	int			len;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			options = ft_set_options(&format);
			len += ft_handle_spec(options, ap);
		}
		else
		{
			ft_putchar(*format);
			len++;
		}
		format++;
	}
	va_end(ap);
	return (len);
}
