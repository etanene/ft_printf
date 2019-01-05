/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:43:01 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/05 14:08:16 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


#include <stdio.h>

int			ft_set_spec(char c, t_options *options)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || \
		c == 'X' || c == 'f' || c == 'c' || c == 's' || c == 'p')
	{
		options->spec = c;
		return (1);
	}
	return (0);
}

void		ft_set_length(const char *format, t_options *options)
{
	if (*format == 'h' && *(format + 1) == 'h')
		options->length = HH;
	else if (*format == 'h' && options->length != HH)
		options->length = H;
	else if (*format == 'l' && *(format + 1) == 'l')
		options->length = LL;
	else if (*format == 'l' && options->length != LL)
		options->length = L;	
}

t_options	ft_set_options(const char **format)
{
	t_options	options;

	options.flags = 0;
	options.width = 0;
	options.precision = 0;
	options.length = 0;
	options.spec = 0;
	while (**format)
	{
		if (ft_set_spec(**format, &options))
			break;
		ft_set_length(*format, &options);
		(*format)++;
	}
	return (options);
}

void		ft_printnum(long long num, int type)
{
	unsigned long long	unum;

	if (type == SIGN)
		unum = num < 0 ? -num : num;
	else
		unum = num;
	if (type == SIGN && num < 0)
		ft_putchar('-');
	if (unum >= 10)
		ft_printnum(unum / 10, type);
	ft_putchar(unum % 10 + '0');
}

void		ft_parse_num(t_options options, long long num, int type)
{
	if (options.length == 0)
		ft_printnum((int)num, type);
	else if (options.length == HH)
		ft_printnum((char)num, type);
	else if (options.length == H)
		ft_printnum((short int)num, type);
	else if (options.length == L)
		ft_printnum((long int)num, type);
	else if (options.length == LL)
		ft_printnum((long long int)num, type);
}

void		ft_parse_unum(t_options options, long long num, int type)
{
	if (options.length == 0)
		ft_printnum((unsigned int)num, type);
	else if (options.length == HH)
		ft_printnum((unsigned char)num, type);
	else if (options.length == H)
		ft_printnum((unsigned short int)num, type);
	else if (options.length == L)
		ft_printnum((unsigned long int)num, type);
	else if (options.length == LL)
		ft_printnum((unsigned long long int)num, type);
}

void		ft_parse_format(t_options options, va_list ap)
{
	
	if (options.spec == 'd' || options.spec == 'i')
		ft_parse_num(options, va_arg(ap, long long int), SIGN);
	else if (options.spec == 'u')
		ft_parse_unum(options, va_arg(ap, long long int), UNSIGN);	
}

int			ft_printf(const char *format, ...)
{
	va_list 	ap;
	t_options	options;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			options = ft_set_options(&format);
			ft_parse_format(options, ap);
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (1);
}
