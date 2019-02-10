/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:00:39 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/05 15:19:56 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen_r(char *str)
{
	int		len;

	len = 0;
	while (*str)
	{
		if ((*str >= 7 && *str <= 13) || *str == '\e')
		{
			len++;
		}
		len++;
		str++;
	}
	return (len + 1);
}

void	ft_print_str_r(char *str, int prec)
{
	while (*str && prec--)
	{
		if (*str == '\a')
			write(1, "\\a", 3);
		else if (*str == '\b')
			write(1, "\\b", 3);
		else if (*str == '\t')
			write(1, "\\t", 3);
		else if (*str == '\n')
			write(1, "\\n", 3);
		else if (*str == '\v')
			write(1, "\\v", 3);
		else if (*str == '\f')
			write(1, "\\f", 3);
		else if (*str == '\r')
			write(1, "\\r", 3);
		else if (*str == '\e')
			write(1, "\\e", 3);
		else
			write(1, str, 1);
		str++;
	}
	if (!*str)
		write(1, "\\0", 3);
}

int		ft_print_r(t_options opt, char *str)
{
	int		len;

	len = opt.prec < 0 ? ft_strlen_r(str) : opt.prec;
	opt.width = opt.prec < 0 ? opt.width : opt.width - opt.prec;
	if (!opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	ft_print_str_r(str, opt.prec);
	if (opt.flags[F_MINUS])
		len += ft_print_width(opt.width, ' ');
	return (len);
}
