/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diuoxX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:35:21 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/07 14:57:27 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnum(unsigned long long int num)
{
	if (num >= 10)
		ft_printnum(num / 10);
	ft_putchar(num % 10 + '0');
}
/*
int			ft_sum_flags(char *flags)
{
	int		sum;
	int		i;

	sum = 0;
	i = 0;
	while (i < 5)
		sum += flags[i++];
	return (sum);
}
*/
int		ft_print_prefnum(t_options options, int len, long long int num)
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
		if (options.flags[4] && !options.prec)
			ft_putchar('0');
		else
			ft_putchar(' ');
		temp++;
	}
	if (options.flags[F_PLUS] && !(options.flags[F_NULL] || options.flags[F_MINUS]))
		ft_putchar(num < 0 ? '-' : '+');
	return (temp + (options.prec && (options.flags[F_SP] || options.flags[F_PLUS])));
}

int		ft_print_diuoxX(t_options options, long long int num, int type)
{
	unsigned long long int	unum;
	int						len;
	int						temp;	
	//int						flags_sum;

	unum = num;
	if (type == SIGN && num < 0)
	{
		unum = -num;
		options.flags[F_PLUS] = 1;
	}
	len = ft_unumlen(unum);
	if (options.flags[F_PLUS])
		options.flags[F_SP] = 0;
	if (options.flags[F_MINUS])
		options.flags[F_NULL] = 0;
	//flags_sum = ft_sum_flags(options.flags);
	temp = ft_print_prefnum(options, len, num);
	while (options.prec-- > len)
		ft_putchar('0');
	ft_printnum(unum);
	while (options.flags[F_MINUS] && options.width > temp)
	{
		ft_putchar(' ');
		temp++;
	}
	return (temp);
}