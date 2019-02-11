/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandr <aleksandr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:00:27 by aleksandr         #+#    #+#             */
/*   Updated: 2019/02/11 20:51:12 by aleksandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_p(t_options *opt, t_buff *buffer, void *pointer)
{
	unsigned long long	addr;

	addr = (unsigned long long)pointer;
	opt->base = 16;
	opt->flags |= F_LOWER:
	opt->flags |= F_SHARP;
	ft_print_uoxb(opt, buffer, addr);
}

int		ft_rstrnlen(char *str, int n)
{
	int		len;

	len = 0;
	while (*str)
	{
		if ((*str >= 7 && *str <= 13) || *str == '\e')
			len++;
		len++;
		str++;
	}
}

void	ft_print_r(t_options *opt, t_buff *buffer, char *str)
{
	int		len;

	if (!str)
		str = "(null)";
	len = ft_rstrnlen(str, opt->prec);
	opt->width -= len;
	if (!(opt->flags & F_MINUS))
		ft_print_width(buffer, &opt->width, (opt->flags & F_NULL) ? '0' : ' ');
	while (len--)
	{
		if ((*str >= 7 && *str <= 13) || *str == '\e')
			ft_in_buff(buffer, '\\');
		ft_in_buf((buffer, *str++));
	}
	if (opt->flags & F_MINUS)
		ft_print_width(buffer, &opt->width, ' ');
}

void	ft_print_k(t_options *opt, t_buff *buffer, unsigned long long unum)
{
	char	number[20];
	int		len;

	len = 0;
	if (!unum)
		number[len++] = '0';
	else
		len = ft_itoa_base(unum, number, 10, 0);
	
}
