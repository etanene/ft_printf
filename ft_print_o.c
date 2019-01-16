/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:51:45 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/16 17:45:19 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_o(t_options opt, unsigned long long unum)
{
	int		len;

	len = ft_unumlen(unum, 8);
	ft_reset_options(&opt, &len);
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
