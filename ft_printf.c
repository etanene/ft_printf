/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:43:01 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/05 20:27:05 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


#include <stdio.h>

int			ft_numlen(unsigned long long int num)
{
	int		len;

	len = 0;
	while (num /= 10)
		len++;
	return (len + 1);
}

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

void		ft_set_flags(const char **format, t_options *options)
{
	while (**format)
	{
		if (**format == '-')
			options->flags[0] = FLAG_MINUS;
		else if (**format == '+')
			options->flags[1] = FLAG_PLUS;
		else if (**format == ' ')
			options->flags[2] = FLAG_SP;
		else if (**format == '#')
			options->flags[3] = FLAG_SHARP;
		else if (**format == '0')
			options->flags[4] = FLAG_NULL;
		else
			break;
		(*format)++;
	}
}

void		ft_set_width(const char **format, t_options *options)
{
	options->width = ft_atoi(*format);
	if (options->width)
		*format += ft_numlen(options->width);
}

void		ft_set_length(const char **format, t_options *options)
{
	while (**format)
	{
		if (**format == 'h' && *(*format + 1) == 'h')
		{
			options->length = LEN_HH;
			(*format)++;
		}
		else if (**format == 'h' && options->length != LEN_HH)
			options->length = LEN_H;
		else if (**format == 'l' && *(*format + 1) == 'l')
		{
			options->length = LEN_LL;
			(*format)++;
		}
		else if (**format == 'l' && options->length != LEN_LL)
			options->length = LEN_L;
		else
			break;
		(*format)++;
	}
}

t_options	ft_set_options(const char **format)
{
	t_options	options;
	int			i;

	i = 0;
	while (i < 5)
		options.flags[i++] = 0;
	options.width = 0;
	options.precision = 0;
	options.length = 0;
	options.spec = 0;
	while (**format)
	{
		if (ft_set_spec(**format, &options))
			break;
		ft_set_flags(format, &options);
		ft_set_width(format, &options);
		ft_set_length(format, &options);
		(*format)++;
	}
	return (options);
}

void		ft_printnum(long long int num, int type)
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

int			ft_sum_flags(char *flags)
{
	int		sum;
	int		i;

	sum = 0;
	i = 0;
	while (i < 5)
		sum += flags[i];
	return (sum);
}

void		ft_parse_options(t_options options, long long int num, int type)
{
	unsigned long long int	unum;
	int						len;
	int						flags_sum;

	unum = num;
	if (type == SIGN && num < 0)
	{
		unum = -num;
		options.flags[1] = FLAG_PLUS;
	}
	len = ft_numlen(unum);
	flags_sum = ft_sum_flags(options.flags);
	if (options.flags[1] == FLAG_PLUS)
	{
		len += 1;
		ft_putchar(num < 0 ? '-' : '+');
	}

}

void		ft_parse_num(t_options options, long long int num, int type)
{
	if (options.length == 0)
		ft_parse_options(options, (int)num, type);
	else if (options.length == LEN_HH)
		ft_parse_options(options, (char)num, type);
	else if (options.length == LEN_H)
		ft_parse_options(options, (short int)num, type);
	else if (options.length == LEN_L)
		ft_parse_options(options, (long int)num, type);
	else if (options.length == LEN_LL)
		ft_parse_options(options, (long long int)num, type);
}

void		ft_parse_unum(t_options options, long long int num, int type)
{
	if (options.length == 0)
		ft_parse_options(options, (unsigned int)num, type);
	else if (options.length == LEN_HH)
		ft_parse_options(options, (unsigned char)num, type);
	else if (options.length == LEN_H)
		ft_parse_options(options, (unsigned short int)num, type);
	else if (options.length == LEN_L)
		ft_parse_options(options, (unsigned long int)num, type);
	else if (options.length == LEN_LL)
		ft_parse_options(options, (unsigned long long int)num, type);
}

void		ft_parse_spec(t_options options, va_list ap)
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
			ft_parse_spec(options, ap);
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (1);
}
