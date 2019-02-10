/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:46:48 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/07 19:32:39 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_options_u(t_options *opt, int *len, unsigned long long unum)
{
	*len = ft_unumlen(unum, 10);
	if (!unum && !opt->prec)
		*len -= 1;
	if (opt->flags[F_MINUS])
		opt->flags[F_NULL] = 0;
	opt->width -= MAX(*len, opt->prec);
	if (unum)
		opt->prec -= *len;
}

int		ft_print_u(t_options opt, unsigned long long unum)
{
	int		len;

	ft_reset_options_u(&opt, &len, unum);
	if (opt.flags[F_NULL] && opt.prec < 0)
		len += ft_print_width(opt.width, '0');
	else if (!opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	len += ft_print_prec(opt.prec);
	if (opt.prec)
		ft_printnum(unum, 10);
	if (opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	return (len);
}