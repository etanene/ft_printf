/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:07:32 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/04 20:32:13 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_options_p(t_options *opt, int len)
{
	if (opt->flags[F_MINUS])
		opt->flags[F_NULL] = 0;
	opt->width -= len + 2;
}

int		ft_print_p(t_options opt, void	*pointer)
{
	int					len;
	unsigned long long	address;

	address = (unsigned long long)pointer;
	len = ft_unumlen(address, 16);
	ft_reset_options_p(&opt, len);
	if (opt.flags[F_MINUS] || opt.flags[F_NULL])
		write(1, "0x", 2);
	if (opt.flags[F_NULL])
		len += ft_print_width(opt.width, '0');
	else if (!opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	if (!(opt.flags[F_MINUS] || opt.flags[F_NULL]))
		write(1, "0x", 2);
	ft_printnum(address, 16);
	if (opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	return (len + 2);
}
