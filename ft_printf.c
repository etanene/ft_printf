/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:43:01 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/07 18:55:32 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_handle_spec(t_options options, va_list ap)
{
	int		len;

	len = 0;
	if (options.flags[F_WIDTH_STAR])
		options.width = va_arg(ap, int);
	if (options.flags[F_PREC_STAR])
		options.prec = va_arg(ap, int);
	if (options.spec == 'd' || options.spec == 'i' || options.spec == 'D')
		len = ft_parse_num(options, va_arg(ap, long long int));
	else if (options.spec == 'u' || options.spec == 'U')
		len = ft_parse_unum(options, va_arg(ap, long long int), ft_print_u);
	else if (options.spec == 'o' || options.spec == 'O')
		len = ft_parse_unum(options, va_arg(ap, long long int), ft_print_o);
	else if (options.spec == 'x' || options.spec == 'X')
		len = ft_parse_unum(options, va_arg(ap, long long int), ft_print_x);
	else if (options.spec == 'c' || options.spec == 'C')
		len = ft_print_c(options, va_arg(ap, int));
	else if (options.spec == 's' && options.length != LEN_L)
		len = ft_print_s(options, va_arg(ap, int*), ft_strlen_s, ft_puts);
	else if (options.spec == 'S' || (options.spec == 's' && options.length == LEN_L))
		len = ft_print_s(options, va_arg(ap, int*), ft_strlen_unicode, ft_puts_unicode);
	else if (options.spec == 'f' && options.length == LEN_LL)
		len = ft_parse_lf(options, va_arg(ap, long double));
	else if (options.spec == 'f')
		len = ft_parse_f(options, va_arg(ap, double));
	else if (options.spec == 'p')
		len = ft_print_p(options, va_arg(ap, void*));
	else if (options.spec == 'b')
		len = ft_parse_unum(options, va_arg(ap, long long int), ft_print_b);
	else if (options.spec == 'k')
		len = ft_print_k(options, va_arg(ap, unsigned long long));
	else if (options.spec == 'r')
		len = ft_print_r(options, va_arg(ap , char*));
	else if (options.spec == '%')
		len = ft_print_perc(options, '%');
	else if (options.spec)
		len = ft_print_rand(options);
	return (len);
}

t_options	ft_set_options(const char **format)
{
	t_options	options;
	int			i;
	char		*temp;

	i = 0;
	while (i < 7)
		options.flags[i++] = 0;
	options.width = 0;
	options.prec = -1;
	options.length = 0;
	options.spec = 0;
	while (**format)
	{
		temp = (char*)*format;
		ft_set_flags(format, &options);
		ft_set_width(format, &options);
		ft_set_prec(format, &options);
		ft_set_length(format, &options);
		if (ft_set_spec(**format, &options))
			break;
		if (temp == *format)
			break;
		// if (**format)
		// 	(*format)++;
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
		if (*format)
			format++;
	}
	va_end(ap);
	return (len);
}
