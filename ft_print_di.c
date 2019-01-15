/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:20:23 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/15 20:42:02 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
int		ft_di_preffix(t_options options, int len, long long int num)
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
	temp = ft_di_preffix(options, len, num);
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
*/

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
	len = ft_unumlen(unum, 10);
	ft_reset_options(&opt, &len);
	if (opt.flags[F_SP])
		ft_putchar(' ');
	else if (opt.flags[F_PLUS] && (opt.flags[F_NULL] || opt.flags[F_MINUS]))
		ft_putchar(num < 0 ? '-' : '+');
	//printf("\nwidth: %d\n", opt.width);
	if (!opt.flags[F_MINUS] && (opt.flags[F_NULL] || opt.prec == -1))
		len += ft_print_width(opt.width, 0, '0');
	else if (!opt.flags[F_MINUS])
		len += ft_print_width(opt.width, 0, ' ');
	if (opt.flags[F_PLUS] && !(opt.flags[F_NULL] || opt.flags[F_MINUS]))
		ft_putchar(num < 0 ? '-' : '+');
	//printf("\nprec: %d, len: %d\n", opt.prec, len);
	len += ft_print_prec(opt.prec);
	ft_printnum(unum, 10);
	if (opt.flags[F_MINUS])
		len += ft_print_width(opt.width, 0, ' ');
	return (len);
}