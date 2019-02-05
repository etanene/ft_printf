/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_k.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:15:33 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/05 16:25:41 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_k(t_options opt, unsigned long long unum)
{
	int			len;
	char		*date;
	char		space[3];

	len = 0;
	date = ft_itoa(unum);
	space[0] = 4;
	space[1] = 7;
	space[2] = '-';
	if (opt.length == LEN_TIME)
	{
		space[0] = 2;
		space[1] = 5;
		space[2] = ':';
	}
	while (*date)
	{
		if (len == space[0] || len == space[1])
		{
			ft_putchar(space[2]);
			len++;
		}
		ft_putchar(*date++);
		len++;
	}
	return (len);
}
