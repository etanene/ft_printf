/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:44:24 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/07 16:14:51 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unumlen(unsigned long long int num, char spec)
{
	int		len;
	int		base;

	base = 0;
	if (spec == 'd' || spec == 'i' || spec == 'u')
		base = 10;
	else if (spec == 'o')
		base = 8;
	else if (spec == 'x' || spec == 'X')
		base = 16;
	len = 0;
	while (num /= base)
		len++;
	return (len + 1);
}