/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:20:23 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/18 17:30:05 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_options_di(t_options *opt, int *len, unsigned long long unum)
{
	*len = ft_unumlen(unum, 10);
	if (opt->flags[F_PLUS])
		opt->flags[F_SP] = 0;
	if (opt->flags[F_PLUS] || opt->flags[F_SP])
		*len += 1;
	if (opt->flags[F_MINUS])
		opt->flags[F_NULL] = 0;
	opt->width -= MAX(*len, opt->prec);
	opt->prec -= *len - (opt->flags[F_PLUS] || opt->flags[F_SP]);
}

int		ft_print_di(t_options opt, long long int num)
{
	unsigned long long int	unum;
	int						len;

	unum = num;
	if (num < 0)
	{
		unum = -num;
		opt.flags[F_PLUS] = 1;
	}
	ft_reset_options_di(&opt, &len, unum);
	if (opt.flags[F_SP])
		ft_putchar(' ');
	else if (opt.flags[F_PLUS] && (opt.flags[F_NULL] || opt.flags[F_MINUS]))
		ft_putchar(num < 0 ? '-' : '+');
	if (opt.flags[F_NULL] && opt.prec < 0)
		len += ft_print_width(opt.width, '0');
	else if (!opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	if (opt.flags[F_PLUS] && !(opt.flags[F_NULL] || opt.flags[F_MINUS]))
		ft_putchar(num < 0 ? '-' : '+');
	len += ft_print_prec(opt.prec);
	ft_printnum(unum, 10);
	if (opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	return (len);
}