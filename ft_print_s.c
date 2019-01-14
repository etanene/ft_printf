/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:48:31 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/14 20:51:54 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_s(t_options options, int *str)
{
	int		len;
	char	*s;

	len = 0;
	if (options.spec == 's')
	{
		s = (char*)str;
		while (*s)
		{
			len++;
			ft_putchar(*s++);
		}
	}
	else
	{
		while (*str)
			len += ft_print_c(options, *str++);
	}
	return (len);
}