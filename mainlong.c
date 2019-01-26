/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainlong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:44:46 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/26 21:47:29 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define COUNT_BITS 64
#define MAX_POWER 48
#define MAX_NUM 1000000000000000UL
#define MAX_INDEX 32

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_checkbit(long long n, int pos)
{
	return ((n & (1UL << pos)) != 0);
}

void	ft_printbits(long long n, int count)
{
	while (count--)
	{
		ft_putchar(ft_checkbit(n, count) + '0');
		if (!(count % 8) && count)
			ft_putchar(' ');
	}
}

unsigned long long	ft_pow(int num, int pow)
{
	unsigned long long	res;

	res = 1;
	while (pow--)
		res *= num;
	return (res);
}

int		ft_add_to_bigint(unsigned long long *bigint, unsigned long long num, \
						int index)
{
	if ((bigint[index] += num) >= MAX_NUM)
	{
		bigint[index] -= MAX_NUM;
		index = ft_add_to_bigint(bigint, 1, index + 1);
	}
	return (index);
}

void	ft_set_bigint(unsigned long long *bigint, int power)
{
	int					count;
	int					last_pow;
	unsigned long long	num;
	int					max_index;
	int					index;

	count = 0;
	max_index = 0;
	index = 0;
	num = ft_pow(2, MAX_POWER);
	while (power)
	{
		count++;
		last_pow = power % MAX_POWER;
		power /= MAX_POWER;
	}
	while (count)
	{
		if ((index = ft_add_to_bigint(bigint, num, 0)) > max_index)
			max_index = index;
		count--;
	}
	if ((index = ft_add_to_bigint(bigint, ft_pow(2, last_pow), 0)) > max_index)
		max_index = index;
}

int		main(void)
{
	t_fnum				fnum;
	unsigned long long	mantissa;
	int					powers[COUNT_BITS];
	int					power;
	unsigned long long	bigint[MAX_INDEX];

	fnum.f = -818.375;
	ft_printbits(fnum.ll, 64);
	ft_putchar('\n');
	mantissa = (fnum.ll & 0x1FFFFFFFFFFFFF) | 0x10000000000000;
	ft_printbits(mantissa, 64);
	ft_putchar('\n');
	power = 0;
	while (power < MAX_INDEX)
		bigint[power++] = 0;
	power = 0;
	while (power < COUNT_BITS)
	{
		if (ft_checkbit(mantissa, power))
		{
			powers[power] = power * 1000;
			ft_set_bigint(bigint, power);
		}
		else
			powers[power] = 0;
	}
	return (0);
}