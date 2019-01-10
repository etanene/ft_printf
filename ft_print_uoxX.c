/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uoxX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:35:21 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/10 13:06:33 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_prefnum_uoxX(t_options options, int len)
{
	int		count;
	int		temp;

	count = 0;
	if (options.flags[F_SHARP])
	{
		if (options.spec != 'o')
			count += 2;
		else
			count++;
		if (options.flags[F_MINUS] || options.flags[F_NULL])
		{
			ft_putchar('0');
			if (options.spec == 'x' || options.spec == 'X')
				ft_putchar(options.spec);
		}
	}
	temp = MAX(len, options.prec);
	while (!options.flags[F_MINUS] && options.width - temp > count - (options.spec == 'o' && options.prec - len == 1))
	{
		if (options.flags[F_NULL] && !options.prec)
			ft_putchar('0');
		else
			ft_putchar(' ');
		count++;
	}
	if (options.flags[F_SHARP] && !(options.flags[F_MINUS] || options.flags[F_NULL]))
	{
		if (!(options.spec == 'o' && options.prec - len == 1))
			ft_putchar('0');
		if (options.spec == 'x' || options.spec == 'X')
			ft_putchar(options.spec);
	}
	return (temp + count - (options.spec == 'o' && options.prec - len == 1));
}

int		ft_print_uoxX(t_options options, unsigned long long int unum)
{
	int		len;
	int		base;
	int		count;

	base = 10;
	if (options.spec == 'u')
		base = 10;
	else if (options.spec == 'o')
		base = 8;
	else if (options.spec == 'x' || options.spec == 'X')
		base = 16;
	len = ft_unumlen(unum, base);
	if (options.flags[F_MINUS])
		options.flags[F_NULL] = 0;
	if (options.spec == 'u')
		options.flags[F_SHARP] = 0;
	count = ft_prefnum_uoxX(options, len);
	while (options.prec-- > len)
		ft_putchar('0');
	if (options.spec == 'X')
		ft_printnumX(unum, base);
	else
		ft_printnum(unum, base);
	while (options.flags[F_MINUS] && options.width > count)
	{
		ft_putchar(' ');
		count++;
	}
	return (count);
}
