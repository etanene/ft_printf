/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:43:01 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/04 20:25:30 by afalmer-         ###   ########.fr       */
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
	if (options.spec == 'd' || options.spec == 'i')
		len = ft_parse_num(options, va_arg(ap, long long int));
	else if (options.spec == 'u')
		len = ft_parse_unum(options, va_arg(ap, long long int), ft_print_u);
	else if (options.spec == 'o')
		len = ft_parse_unum(options, va_arg(ap, long long int), ft_print_o);
	else if (options.spec == 'x' || options.spec == 'X')
		len = ft_parse_unum(options, va_arg(ap, long long int), ft_print_x);
	else if (options.spec == 'c' || options.spec == 'C')
		len = ft_print_c(options, va_arg(ap, int));
	else if (options.spec == 's')
		len = ft_print_s(options, va_arg(ap, int*), ft_strlen_s, ft_puts);
	else if (options.spec == 'S')
		len = ft_print_s(options, va_arg(ap, int*), ft_strlen_unicode, ft_puts_unicode);
	else if (options.spec == 'f' && options.length == LEN_LL)
		len = ft_parse_lf(options, va_arg(ap, long double));
	else if (options.spec == 'f')
		len = ft_parse_f(options, va_arg(ap, double));
	else if (options.spec == 'p')
		len = ft_print_p(options, va_arg(ap, void*));
	else if (options.spec == 'b')
		len = ft_parse_unum(options, va_arg(ap, long long int), ft_print_b);
	return (len);
}

t_options	ft_set_options(const char **format)
{
	t_options	options;
	int			i;

	i = 0;
	while (i < 7)
		options.flags[i++] = 0;
	options.width = 0;
	options.prec = -1;
	options.length = 0;
	options.spec = 0;
	// while (**format)
	// {
		ft_set_flags(format, &options);
		ft_set_width(format, &options);
		ft_set_prec(format, &options);
		ft_set_length(format, &options);
		ft_set_spec(**format, &options);
	// 		break;
	// }
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
		if (*format == '%' && *(format + 1) != '%')
		{
			format++;
			options = ft_set_options(&format);
			len += ft_handle_spec(options, ap);
		}
		else
		{
			if (*format == '%')
				format++;
			ft_putchar(*format);
			len++;
		}
		format++;
	}
	va_end(ap);
	return (len);
}
