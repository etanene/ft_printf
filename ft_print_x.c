/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:52:03 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/18 19:50:27 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_options_x(t_options *opt, int *len, unsigned long long unum)
{
	*len = ft_unumlen(unum, 16);
	if (opt->flags[F_SHARP])
		opt->width -= 2;
	if (opt->flags[F_MINUS])
		opt->flags[F_NULL] = 0;
	opt->width -= MAX(*len, opt->prec);
	opt->prec -= *len;
	if (opt->flags[F_SHARP])
		*len += 2;
}

int		ft_print_x(t_options opt, unsigned long long unum)
{
	int		len;

	ft_reset_options_x(&opt, &len, unum);
	if (opt.flags[F_SHARP] && (opt.flags[F_MINUS] || opt.flags[F_NULL]))
	{
		ft_putchar('0');
		ft_putchar(opt.spec);
	}
	if (opt.flags[F_NULL] && opt.prec < 0)
		len += ft_print_width(opt.width, '0');
	else if (!opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	if (opt.flags[F_SHARP] && !(opt.flags[F_MINUS] || opt.flags[F_NULL]))
	{
		ft_putchar('0');
		ft_putchar(opt.spec);
	}
	len += ft_print_prec(opt.prec);
	if (opt.spec == 'x')
		ft_printnum(unum, 16);
	else
		ft_printnumX(unum, 16);
	if (opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	return (len);
}
