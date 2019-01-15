/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:32:33 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/15 20:06:56 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_width(int width, int len, int c)
{
	int		count;

	count = 0;
	while (width > len + count)
	{
		ft_putchar(c);
		count++;
	}
	return (count);
}

int		ft_print_prec(int prec)
{
	int		count;

	count = prec;
	if (prec > 0)
	{
		while (prec--)
			ft_putchar('0');
		return (count - prec + 1);
	}
	return (0);
}

void	ft_reset_options(t_options *options, int *len)
{
	if (options->flags[F_PLUS])
		options->flags[F_SP] = 0;
	if (options->flags[F_MINUS])
		options->flags[F_NULL] = 0;
	if (options->flags[F_PLUS] || options->flags[F_SP])
		*len += 1;
	options->width -= MAX(*len, options->prec);
	options->prec -= *len - (options->flags[F_PLUS] || options->flags[F_SP]);
}