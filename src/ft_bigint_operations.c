/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:07:49 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/13 17:18:15 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bigint_sum_bigint(t_bigint *bigint1, t_bigint *bigint2)
{
	int					i;
	unsigned long long	temp;

	i = 0;
	temp = 0;
	while (i < bigint2->size || temp)
	{
		bigint1->num[i] += temp + bigint2->num[i];
		temp = (bigint1->num[i] >= MAX_NUM);
		if (i == bigint1->size)
			bigint1->size++;
		if (temp)
			bigint1->num[i] -= MAX_NUM;
		i++;
	}
}

void	ft_bigint_multi_int(t_bigint *bigint, int num)
{
	int					i;
	unsigned long long	temp;
	unsigned long long	div;

	i = 0;
	div = 0;
	while (i < bigint->size)
	{
		temp = div + bigint->num[i] * num;
		bigint->num[i] = temp % MAX_NUM;
		div = temp / MAX_NUM;
		i++;
		if (i == bigint->size && div)
			bigint->size++;
	}
}
