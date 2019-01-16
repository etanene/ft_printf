/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:32:33 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/16 19:41:56 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_width(int width, int c)
{
	int		count;

	count = 0;
	while (width > count)
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
		return (count);
	}
	return (0);
}

void	ft_reset_options(t_options *opt, int *len)
{
	if (opt->spec == 'd' || opt->spec == 'i')
	{
		if (opt->flags[F_PLUS])
			opt->flags[F_SP] = 0;
		if (opt->flags[F_PLUS] || opt->flags[F_SP])
			*len += 1;
	}
	else
	{
		opt->flags[F_SP] = 0;
		opt->flags[F_PLUS] = 0;
		if (opt->flags[F_SHARP] && opt->spec == 'o')
			*len += 1;
		else if (opt->flags[F_SHARP] && (opt->spec == 'x' || opt->spec == 'X'))
			opt->width -= 2;
	}
	if (opt->flags[F_MINUS])
		opt->flags[F_NULL] = 0;
	opt->width -= MAX(*len, opt->prec);
	opt->prec -= *len - (opt->flags[F_PLUS] || opt->flags[F_SP]);
	if (opt->flags[F_SHARP] && (opt->spec == 'x' || opt->spec == 'X'))
		*len += 2;
}
