/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:31:04 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/22 21:18:04 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_num(t_options options, long long num)
{
	int		len;

	len = 0;
	if (options.length == 0)
		len = ft_print_di(options, (int)num);
	else if (options.length == LEN_HH)
		len = ft_print_di(options, (char)num);
	else if (options.length == LEN_H)
		len = ft_print_di(options, (short int)num);
	else if (options.length == LEN_L)
		len = ft_print_di(options, (long int)num);
	else if (options.length == LEN_LL)
		len = ft_print_di(options, (long long int)num);
	return (len);
}

int		ft_parse_unum(t_options options, long long num, \
		int (*ft_print)(t_options, unsigned long long))
{
	int		len;

	len = 0;
	if (options.length == 0)
		len = ft_print(options, (unsigned int)num);
	else if (options.length == LEN_HH)
		len = ft_print(options, (unsigned char)num);
	else if (options.length == LEN_H)
		len = ft_print(options, (unsigned short int)num);
	else if (options.length == LEN_L)
		len = ft_print(options, (unsigned long int)num);
	else if (options.length == LEN_LL)
		len = ft_print(options, (unsigned long long int)num);
	return (len);
}

int		ft_parse_fnum(t_options options, long double num)
{
	int		len;

	len = 0;
	if (options.length != LEN_L)
		len = ft_print_f(options, (double)num);
	// else
	// 	len = ft_print_lf(options, (long double)num);
	return (len);
}
