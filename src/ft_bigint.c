/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:27:20 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/13 17:20:53 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_reset_bigint(t_bigint *bigint)
{
	int		i;

	i = 0;
	while (i < 1024)
		bigint->num[i++] = 0;
	bigint->size = 0;
}

void		ft_set_bigint(t_bigint *bigint, int power)
{
	int		num;
	int		count;
	int		last_pow;
	int		temp;

	count = 0;
	num = 1ULL << MAX_POWER;
	if (power >= MAX_POWER)
		count = power / MAX_POWER;
	last_pow = power % MAX_POWER;
	temp = count;
	if (count)
	{
		bigint->num[0] += num;
		count--;
	}
	else
		bigint->num[0] += 1ULL << last_pow;
	bigint->size = 1;
	while (count--)
		ft_bigint_multi_int(bigint, num);
	if (temp)
		ft_bigint_multi_int(bigint, 1ULL << last_pow);
}

t_bigint	ft_get_bigint(unsigned long long num, unsigned long long shift)
{
	t_bigint	res_bigint;
	t_bigint	temp_bigint;
	int			power;

	power = 0;
	ft_reset_bigint(&res_bigint);
	ft_reset_bigint(&temp_bigint);
	while (power < sizeof(num))
	{
		if (num & (1ULL << power))
		{
			ft_set_bigint(&temp_bigint, shift + power);
			ft_bigint_sum_bigint(&res_bigint, &temp_bigint);
			ft_reset_bigint(&temp_bigint);
		}
		power++;
	}
	return (res_bigint);
}
