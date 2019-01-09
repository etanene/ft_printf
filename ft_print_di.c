/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:20:23 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/09 15:43:18 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_prefnum_di(t_options options, int len, long long int num)
{
	int		temp;

	if (options.flags[F_SP] || options.flags[F_PLUS])
	{
		len++;
		if (options.flags[F_SP])
			ft_putchar(' ');
		else if (options.flags[F_NULL] || options.flags[F_MINUS])
			ft_putchar(num < 0 ? '-' : '+');
	}
	temp = MAX(len, options.prec);
	while (!options.flags[F_MINUS] && options.width > temp)
	{
		if (options.flags[F_NULL] && !options.prec)
			ft_putchar('0');
		else
			ft_putchar(' ');
		temp++;
	}
	if (options.flags[F_PLUS] && !(options.flags[F_NULL] || options.flags[F_MINUS]))
		ft_putchar(num < 0 ? '-' : '+');
	return (temp + (options.prec && (options.flags[F_SP] || options.flags[F_PLUS])));
}

int		ft_print_di(t_options options, long long int num)
{
	unsigned long long int	unum;
	int						len;
	int						temp;

	unum = num;
	if (num < 0)
	{
		unum = -num;
		options.flags[F_PLUS] = 1;
	}
	len = ft_unumlen(unum, 10);
	if (options.flags[F_PLUS])
		options.flags[F_SP] = 0;
	if (options.flags[F_MINUS])
		options.flags[F_NULL] = 0;
	temp = ft_prefnum_di(options, len, num);
	while (options.prec-- > len)
		ft_putchar('0');
	ft_printnum(unum, 10);
	while (options.flags[F_MINUS] && options.width > temp)
	{
		ft_putchar(' ');
		temp++;
	}
	return (temp);
}