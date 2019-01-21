/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:46:48 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/18 17:30:47 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_options_u(t_options *opt, int *len)
{
	if (opt->flags[F_MINUS])
		opt->flags[F_NULL] = 0;
	opt->width -= MAX(*len, opt->prec);
	opt->prec -= *len;
}

int		ft_print_u(t_options opt, unsigned long long unum)
{
	int		len;

	len = ft_unumlen(unum, 10);
	ft_reset_options_u(&opt, &len);
	if (opt.flags[F_NULL] && opt.prec < 0)
		len += ft_print_width(opt.width, '0');
	else if (!opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	len += ft_print_prec(opt.prec);
	ft_printnum(unum, 10);
	if (opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	return (len);
}