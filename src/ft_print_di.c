/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandr <aleksandr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 00:55:24 by aleksandr         #+#    #+#             */
/*   Updated: 2019/02/11 01:34:57 by aleksandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_di(t_options *opt, t_buff *buffer, long long num)
{
	unsigned long long	unum;
	char				sign;
	char				num[20];
	int					len;

	if (opt->flags & F_MINUS)
		opt->flags &= ~F_NULL;
	unum = num;
	sign = 0;
	if (num < 0)
	{
		sign = '-';
		unum = -num;
		opt->width--;
	}
	else if (opt->flags & F_PLUS)
	{
		sign = '+';
		opt->width--;
	}
	else if (opt->flags & F_SP)
	{
		sign = ' ';
		opt->width--;
	}
	len = 0;
	if (!unum)
		num[len++] = '0';
	else
	{

	}
}
