/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:00:27 by aleksandr         #+#    #+#             */
/*   Updated: 2019/02/12 16:53:14 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_p(t_options *opt, t_buff *buffer, void *pointer)
{
	unsigned long long	addr;

	addr = (unsigned long long)pointer;
	opt->base = 16;
	opt->flags |= F_LOWER;
	opt->flags |= F_SHARP;
	ft_print_uoxb(opt, buffer, addr);
}

void	ft_print_rand(t_options *opt, t_buff *buffer)
{
	opt->width--;
	if (!(opt->flags & F_MINUS))
		ft_print_width(buffer, &opt->width, (opt->flags & F_NULL) ? '0' : ' ');
	ft_in_buff(buffer, opt->spec);
	if (opt->flags & F_MINUS)
		ft_print_width(buffer, &opt->width, ' ');
}

int		ft_rstrnlen(char *str, int n)
{
	int		len;

	len = 0;
	while (n--)
	{
		if (!*str)
			break ;
		if ((*str >= 7 && *str <= 13) || *str == '\e')
			len++;
		len++;
		str++;
	}
	return (len);
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
		ft_in_buff(buffer, *str++);
	}
	if (opt->flags & F_MINUS)
		ft_print_width(buffer, &opt->width, ' ');
}

// hh:mm:ss	

// void	ft_print_k(t_options *opt, t_buff *buffer, unsigned long long unum)
// {
// 	char	str[20];
// 	int		len;
// 	int		sec;
// 	int		minutes;
// 	int		hours;

// 	len = 0;
// 	// if (!unum)
// 	// 	number[len++] = '0';
// 	// else
// 	// 	len = ft_itoa_base(unum, number, 10, 0);
// 	sec = unum % 60;
// 	unum /= 60;
// 	minutes = unum % 60;
// 	unum /= 60;
// 	hours = unum;
// 	while (len < 2)
// 	{
// 		str[len++] = sec % 10;
// 		sec /= 10;
// 	}
// 	if (minutes)
// 		str[len++] = ':';
// 	while (len < 5)
// 	{
// 		str[len++] = minutes % 10;
// 		minutes / 10;
// 	}
// 	if (hours)
// 		str[len++] = ':';
// }
