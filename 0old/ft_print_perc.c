/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:30:50 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/06 14:14:41 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_perc(t_options opt, char c)
{
	int		len;

	len = 0;
	if (opt.flags[F_MINUS])
		opt.flags[F_NULL] = 0;
	if (opt.flags[F_NULL])
		len += ft_print_width(opt.width - 1, '0');
	else if (!opt.flags[F_MINUS])
		len += ft_print_width(opt.width - 1, ' ');
	ft_putchar(c);
	if (opt.flags[F_MINUS])
		len += ft_print_width(opt.width - 1, ' ');
	return (len + 1);
}
