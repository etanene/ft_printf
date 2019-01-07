/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:31:04 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/07 13:48:04 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_num(t_options options, long long int num, int type)
{
	int		len;

	len = 0;
	if (options.length == 0)
		len = ft_print_diuoxX(options, (int)num, type);
	else if (options.length == LEN_HH)
		len = ft_print_diuoxX(options, (char)num, type);
	else if (options.length == LEN_H)
		len = ft_print_diuoxX(options, (short int)num, type);
	else if (options.length == LEN_L)
		len = ft_print_diuoxX(options, (long int)num, type);
	else if (options.length == LEN_LL)
		len = ft_print_diuoxX(options, (long long int)num, type);
	return (len);
}

int		ft_parse_unum(t_options options, long long int num, int type)
{
	int		len;

	len = 0;
	if (options.length == 0)
		len = ft_print_diuoxX(options, (unsigned int)num, type);
	else if (options.length == LEN_HH)
		len = ft_print_diuoxX(options, (unsigned char)num, type);
	else if (options.length == LEN_H)
		len = ft_print_diuoxX(options, (unsigned short int)num, type);
	else if (options.length == LEN_L)
		len = ft_print_diuoxX(options, (unsigned long int)num, type);
	else if (options.length == LEN_LL)
		len = ft_print_diuoxX(options, (unsigned long long int)num, type);
	return (len);
}