/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandr <aleksandr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 23:30:07 by aleksandr         #+#    #+#             */
/*   Updated: 2019/02/10 23:48:05 by aleksandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_num(t_options *opt, t_buff *buffer, long long num)
{
	if (opt.spec == 'D')
		ft_print_di(opt, buffer, (long)num);
	else if (opt.length == 0)
		ft_print_di(opt, buffer, (int)num);
	else if (opt.length == LEN_HH)
		ft_print_di(opt, buffer, (char)num);
	else if (opt.length == LEN_H)
		ft_print_di(opt, buffer, (short)num);
	else if (opt.length == LEN_L)
		ft_print_di(opt, buffer, (long)num);
	else if (opt.length == LEN_LL)
		ft_print_di(opt, buffer, (long long)num);
	else if (opt.length == LEN_J)
		ft_print_di(opt, buffer, (intmax_t)num);
	else if (opt.length == LEN_Z)
		ft_print_di(opt, buffer, (ssize_t)num);
}

void	ft_parse_unum(t_options *opt, t_buff *buffer, unsigned long long unum, \
					int (*ft_print)(t_options*, t_buff*, unsigned long long))
{
	if (opt.spec == 'U' || opt.spec == 'O')
		ft_print(opt, buffer, (unsigned long)unum);
	else if (opt.length == 0)
		ft_print(opt, buffer, (unsigned int)unum);
	else if (opt.length == LEN_HH)
		ft_print(opt, buffer, (unsigned char)unum);
	else if (opt.length == LEN_H)
		ft_print(opt, buffer, (unsigned short)unum);
	else if (opt.length == LEN_L)
		ft_print(opt, buffer, (unsigned long)unum);
	else if (opt.length == LEN_LL)
		ft_print(opt, buffer, (unsigned long long)unum);
	else if (opt.length == LEN_J)
		ft_print(opt, buffer, (uintmax_t)unum);
	else if (opt.length == LEN_Z)
		ft_print(opt, buffer, (size_t)unum);
}
