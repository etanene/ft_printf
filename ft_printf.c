/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:43:01 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/06 19:20:45 by afalmer-         ###   ########.fr       */
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

void		ft_set_prec(const char **format, t_options *options)
{
	if (**format == '.')
	{
		(*format)++;
		options->prec = ft_atoi(*format);
		if (options->prec)
			*format += ft_numlen(options->prec);
	}
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

void		ft_printnum(unsigned long long int num)
{
	if (num >= 10)
		ft_printnum(num / 10);
	ft_putchar(num % 10 + '0');
}

int			ft_sum_flags(char *flags)
{
	int		sum;
	int		i;

	sum = 0;
	i = 0;
	while (i < 5)
		sum += flags[i++];
	return (sum);
}

int			ft_parse_options(t_options options, long long int num, int type)
{
	unsigned long long int	unum;
	int						len;
	int						temp;	
	int						flags_sum;

	unum = num;
	if (type == SIGN && num < 0)
	{
		unum = -num;
		options.flags[1] = FLAG_PLUS;
	}
	len = ft_numlen(unum);
	if (options.flags[1] == FLAG_PLUS)
		options.flags[2] = 0;
	if (options.flags[0] == FLAG_MINUS)
		options.flags[4] = 0;
	flags_sum = ft_sum_flags(options.flags);
	if (options.flags[2] == FLAG_SP || options.flags[1] == FLAG_PLUS)
	{
		len++;
		if (options.flags[2] == FLAG_SP)
			ft_putchar(' ');
		else if (options.flags[4] == FLAG_NULL || options.flags[0] == FLAG_MINUS)
			ft_putchar(num < 0 ? '-' : '+');
	}
	temp = MAX(len, options.prec);
	while (options.flags[0] != FLAG_MINUS && options.width > temp)
	{
		if (options.flags[4] && !options.prec)
			ft_putchar('0');
		else
			ft_putchar(' ');
		temp++;
	}
	if (flags_sum == FLAG_PLUS)
		ft_putchar(num < 0 ? '-' : '+');
	while (options.prec > len - (options.flags[2] == FLAG_SP || options.flags[1] == FLAG_PLUS))
	{
		ft_putchar('0');
		len++;
	}
	ft_printnum(unum);
	len = temp;
	while (options.flags[0] == FLAG_MINUS && options.width > len)
	{
		ft_putchar(' ');
		len++;
	}
	return (len);
}

int			ft_parse_num(t_options options, long long int num, int type)
{
	int		len;

	len = 0;
	if (options.length == 0)
		len = ft_parse_options(options, (int)num, type);
	else if (options.length == LEN_HH)
		len = ft_parse_options(options, (char)num, type);
	else if (options.length == LEN_H)
		len = ft_parse_options(options, (short int)num, type);
	else if (options.length == LEN_L)
		len = ft_parse_options(options, (long int)num, type);
	else if (options.length == LEN_LL)
		len = ft_parse_options(options, (long long int)num, type);
	return (len);
}

int			ft_parse_unum(t_options options, long long int num, int type)
{
	int		len;

	len = 0;
	if (options.length == 0)
		len = ft_parse_options(options, (unsigned int)num, type);
	else if (options.length == LEN_HH)
		len = ft_parse_options(options, (unsigned char)num, type);
	else if (options.length == LEN_H)
		len = ft_parse_options(options, (unsigned short int)num, type);
	else if (options.length == LEN_L)
		len = ft_parse_options(options, (unsigned long int)num, type);
	else if (options.length == LEN_LL)
		len = ft_parse_options(options, (unsigned long long int)num, type);
	return (len);
}

int			ft_parse_spec(t_options options, va_list ap)
{
	int		len;

	len = 0;
	if (options.spec == 'd' || options.spec == 'i')
		len = ft_parse_num(options, va_arg(ap, long long int), SIGN);
	else if (options.spec == 'u')
		len = ft_parse_unum(options, va_arg(ap, long long int), UNSIGN);
	return (len);
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
			len += ft_parse_spec(options, ap);
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
