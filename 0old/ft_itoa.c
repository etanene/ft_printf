/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:27:17 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/05 13:38:16 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa(unsigned long long num)
{
	char				*res;
	char				*new_res;
	int					len;


	len = ft_unumlen(num, 10);
	if ((res = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	new_res = res + len - 1;
	*(new_res + 1) = '\0';
	while (len--)
	{
		*new_res-- = num % 10 + '0';
		num /= 10;
	}
	return (res);
}
