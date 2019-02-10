/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 20:07:39 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/04 20:49:16 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_options_b(t_options *opt, int *len)
{
	if (opt->flags[F_SHARP])
		opt->width -= 2;
	if (opt->flags[F_MINUS])
		opt->flags[F_NULL] = 0;
	opt->width -= MAX(*len, opt->prec);
	opt->prec -= *len;
	if (opt->flags[F_SHARP])
		*len += 2;
}

int		ft_print_b(t_options opt, unsigned long long unum)
{
	int		len;

	len = ft_unumlen(unum, 2);
	ft_reset_options_b(&opt, &len);
	if (opt.flags[F_SHARP] && (opt.flags[F_MINUS] || opt.flags[F_NULL]))
		write(1, "0b", 2);
	if (opt.flags[F_NULL] && opt.prec < 0)
		len += ft_print_width(opt.width, '0');
	else if (!opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	if (opt.flags[F_SHARP] && !(opt.flags[F_MINUS] || opt.flags[F_NULL]))
		write(1, "0b", 2);
	len += ft_print_prec(opt.prec);
	ft_printnum(unum, 2);
	if (opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	return (len);
}
