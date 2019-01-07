/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diuoxX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:35:21 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/07 17:47:43 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnum(unsigned long long int num, char spec)
{
	unsigned long long int	base;
	char					*str = "0123456789abcdef";
	char					*strX = "0123456789ABCDEF";

	base = 0;
	if (spec == 'd' || spec == 'i' || spec == 'u')
		base = 10;
	else if (spec == 'o')
		base = 8;
	else if (spec == 'x' || spec == 'X')
		base = 16;
	if (num >= base)
		ft_printnum(num / base, spec);
	if (spec != 'X')
		ft_putchar(str[num % base]);
	else
		ft_putchar(strX[num % base]);
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

	if (options.spec == 'd' || options.spec == 'i' || options.spec == 'u')
	{
		if (options.flags[F_SP] || options.flags[F_PLUS])
		{
			len++;
			if (options.flags[F_SP])
				ft_putchar(' ');
			else if (options.flags[F_NULL] || options.flags[F_MINUS])
				ft_putchar(num < 0 ? '-' : '+');
		}
	}
	else if (options.spec == 'o')
	{
		if (options.flags[F_SHARP] && !options.width)
		{
			len++;
			ft_putchar('0');
		}
	}
	/*
	if (options.flags[F_SHARP] && (options.spec == 'o' || options.spec == 'x' || options.spec == 'X'))
	{
		ft_putchar('0');
		len++;
		if (options.spec != 'o')
		{
			ft_putchar(options.spec);
			len++;
		}
	}
	*/
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

int		ft_print_diuoxX(t_options options, long long int num, int type)
{
	unsigned long long int	unum;
	int						len;
	int						temp;

	unum = num;
	if (type == SIGN && num < 0)
	{
		unum = -num;
		options.flags[F_PLUS] = 1;
	}
	len = ft_unumlen(unum, options.spec);
	if (options.flags[F_PLUS])
		options.flags[F_SP] = 0;
	if (options.flags[F_MINUS])
		options.flags[F_NULL] = 0;
	temp = ft_print_prefnum(options, len, num);
	while (options.prec-- > len)
		ft_putchar('0');
	ft_printnum(unum, options.spec);
	while (options.flags[F_MINUS] && options.width > temp)
	{
		ft_putchar(' ');
		temp++;
	}
	return (temp);
}