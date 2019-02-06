/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:09:50 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/06 20:27:57 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_set_spec(char c, t_options *options)
{
	char	*nospec;

	nospec = "-+ #0*.hlLtzj";
	options->spec = 0;
	if ((c >= 0 && c <= 127))
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

void	ft_set_width(const char **format, t_options *options)
{
	options->width = ft_atoi(*format);
	if (options->width)
		*format += ft_unumlen(options->width, 10);
	else if (**format == '*')
	{
		options->flags[F_WIDTH_STAR] = 1;
		(*format)++;
	}
}

void	ft_set_prec(const char **format, t_options *options)
{
	if (**format == '.')
	{
		(*format)++;
		options->prec = ft_atoi(*format);
		if (options->prec > 0)
			*format += ft_unumlen(options->prec, 10);
		else if (**format == '*')
		{
			options->flags[F_PREC_STAR] = 1;
			(*format)++;
		}
		else
		{
			options->prec = 0;
			if (**format == '0')
				(*format)++;
		}
	}

}

void	ft_set_length(const char **format, t_options *options)
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
		else if (**format == 'L')
			options->length = LEN_LL;
		else if (**format == 't')
			options->length = LEN_TIME;
		else if (**format == 'z')
			options->length = LEN_Z;
		else if (**format == 'j')
			options->length = LEN_J;
		else
			break;
		(*format)++;
	}
}
