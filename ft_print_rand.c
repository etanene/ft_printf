/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_rand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:42:43 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/07 18:57:56 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_rand(t_options opt)
{
	int		len;
	
	len = 0;
	if (opt.flags[F_MINUS])
		opt.flags[F_NULL] = 0;
	if (opt.flags[F_NULL])
		len += ft_print_width(opt.width - 1, '0');
	else if (!opt.flags[F_MINUS])
		len += ft_print_width(opt.width - 1, ' ');
	ft_putchar(opt.spec);
	if (opt.flags[F_MINUS])
		len += ft_print_width(opt.width - 1, ' ');
	return (len + 1);
}
