/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:09:50 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/08 18:43:53 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_set_spec(char c, t_options *options)
{
	char	*nospec;

	nospec = "-+ #0*.hlLtzj";
	options->spec = 0;
	if ((c >= 0 && c <= 127) && !(c >= '0' && c <= '9'))
	{
		while (*nospec)
		{
			if (c == *nospec)
				return (0);
			nospec++;
		}
		options->spec = c;
		return (1);
	}
	return (0);
}

void	ft_set_flags(const char **format, t_options *options)
{
	while (**format)
	{
		if (**format == '-')
			options->flags[F_MINUS] = 1;
		else if (**format == '+')
			options->flags[F_PLUS] = 1;
		else if (**format == ' ')
			options->flags[F_SP] = 1;
		else if (**format == '#')
			options->flags[F_SHARP] = 1;
		else if (**format == '0')
			options->flags[F_NULL] = 1;
		else
			break;
		(*format)++;
	}
}

void	ft_set_width(const char **format, t_options *options, va_list ap)
{
	if (!options->width || (**format >= '1' && **format <= '9'))
	{
		options->width = ft_atoi(*format);
		if (options->width)
			*format += ft_unumlen(options->width, 10);
	}
	if (**format == '*')
	{
		options->width = va_arg(ap, int);
		if (options->width < 0)
		{
			options->flags[F_MINUS] = 1;
			options->width = -options->width;
		}
		options->flags[F_WIDTH_STAR] = 1;
		(*format)++;
	}
}

void	ft_set_prec(const char **format, t_options *opt)
{
	if (**format == '.')
	{
		(*format)++;
		opt->prec = ft_atoi(*format);
		if (opt->prec > 0)
			*format += ft_unumlen(opt->prec, 10);
		else if (**format == '*')
		{
			opt->flags[F_PREC_STAR] = 1;
			(*format)++;
		}
		else
		{
			opt->prec = 0;
			if (**format == '0')
				(*format)++;
		}
	}

}

void	ft_set_length(const char **format, t_options *opt)
{
	while (**format)
	{
		if (**format == 'h' && *(*format + 1) == 'h' && (*format)++)
			opt->length = opt->length < LEN_HH ? LEN_HH : opt->length;
		else if (**format == 'h' && opt->length != LEN_HH)
			opt->length = opt->length < LEN_H ? LEN_H : opt->length;
		else if (**format == 'l' && *(*format + 1) == 'l' && (*format)++)
			opt->length = opt->length < LEN_LL ? LEN_LL : opt->length;
		else if (**format == 'l' && opt->length != LEN_LL)
			opt->length = opt->length < LEN_L ? LEN_L : opt->length;
		else if (**format == 'L')
			opt->length = opt->length < LEN_LL ? LEN_LL : opt->length;
		else if (**format == 't')
			opt->length = opt->length < LEN_TIME ? LEN_TIME : opt->length;
		else if (**format == 'z')
			opt->length = opt->length < LEN_Z ? LEN_Z : opt->length;
		else if (**format == 'j')
			opt->length = opt->length < LEN_J ? LEN_J : opt->length;
		else
			break;
		(*format)++;
	}
}
