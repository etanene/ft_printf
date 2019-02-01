/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:51:47 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/01 21:07:36 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_numlen_bigint(t_bigint *bigint)
{
	int		len;
	int		width;
	int		i;

	width = ft_unumlen(MAX_NUM, 10) - 1;
	i = bigint->size - 1;
	len = ft_unumlen(bigint->num[i], 10);
	while (i--)
		len += width;
	return (len);
}

void	ft_print_bigint(t_bigint *bigint)
{
	int		i;
	int		width;
	int		numlen;

	width = ft_unumlen(MAX_NUM, 10) - 1;
	i = bigint->size;
	while (i--)
	{
		numlen = ft_unumlen(bigint->num[i], 10);
		if (i != bigint->size - 1)
			ft_print_width(width - numlen, '0');
		ft_printnum(bigint->num[i], 10);
	}
}

void	ft_bigint_sum_int(unsigned long long *bigint, unsigned long long num, \
						int index)
{
	if ((bigint[index] += num) >= MAX_NUM)
	{
		bigint[index] -= MAX_NUM;
		ft_bigint_sum_int(bigint, 1, index + 1);
	}
}

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
		i++;
		if (temp)
			bigint1->num[i - 1] -= MAX_NUM;
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
		if (div && i == bigint->size)
			bigint->size++;
	}
}

void	ft_bigint_div_int(t_bigint *bigint, int num)
{
	int					i;
	unsigned long long	temp;
	unsigned long long	div;

	div = 0;
	i = bigint->size;
	while (i)
	{
		temp = bigint->num[i] + div * ;
	}
}
