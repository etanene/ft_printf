/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:51:45 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/18 17:32:23 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_options_o(t_options *opt, int *len)
{
	if (opt->flags[F_SHARP])
		*len += 1;
	if (opt->flags[F_MINUS])
		opt->flags[F_NULL] = 0;
	opt->width -= MAX(*len, opt->prec);
	opt->prec -= *len;
}

int		ft_print_o(t_options opt, unsigned long long unum)
{
	int		len;

	len = ft_unumlen(unum, 8);
	ft_reset_options_o(&opt, &len);
	if (opt.flags[F_SHARP] && (opt.flags[F_MINUS] || opt.flags[F_NULL]))
		ft_putchar('0');
	if (opt.flags[F_NULL] && opt.prec < 0)
		len += ft_print_width(opt.width, '0');
	else if (!opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	if (opt.flags[F_SHARP] && !(opt.flags[F_MINUS] || opt.flags[F_NULL]))
		ft_putchar('0');
	len += ft_print_prec(opt.prec);
	ft_printnum(unum, 8);
	if (opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	return (len);
}
