/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:32:33 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/18 19:51:18 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_width(int width, int c)
{
	int		count;

	count = 0;
	while (width > count)
	{
		ft_putchar(c);
		count++;
	}
	return (count);
}

int		ft_print_prec(int prec)
{
	int		count;

	count = prec;
	if (prec > 0)
	{
		while (prec--)
			ft_putchar('0');
		return (count);
	}
	return (0);
}
