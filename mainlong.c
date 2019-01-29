/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainlong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:44:46 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/29 12:52:53 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define COUNT_BITS 64
#define MAX_POWER 15
#define MAX_NUM 1000000000000000UL
#define MAX_INDEX 32

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
	printf("power: %d\n", power);
	printf("num: %llu\n", num);
	if (power >= MAX_POWER)
	{
		count = power / MAX_POWER;
	}
	last_pow = power % MAX_POWER;
	printf("count: %d last_pow: %d\n", count, last_pow);
	index = count;
	if (bigint[0] == 0)
	{
		if (count)
		{
			bigint[0] += num;
			count--;
		}
		else
		{
			bigint[0] += ft_pow(2, last_pow);
		}
	}
	while (count)
	{
		ft_bigint_multi_int(bigint, num);
		count--;
	}
	if (index)
		ft_bigint_multi_int(bigint, ft_pow(2, last_pow));
}

void	ft_reset_bigint(unsigned long long *bigint)
{
	int		i;

	i = 0;
	while (i < MAX_INDEX)
		bigint[i++] = 0;
}

int		main(void)
{
	t_fnum				fnum;
	unsigned long long	mantissa;
	unsigned long long	exponent;
	int					powers[COUNT_BITS];
	int					power;
	unsigned long long	res_bigint[MAX_INDEX];
	unsigned long long	temp_bigint[MAX_INDEX];
	int					index;
	int					max_index;

	fnum.f = DBL_MAX;
	ft_printbits(fnum.ll, 64);
	ft_putchar('\n');
	mantissa = (fnum.ll & 0x1FFFFFFFFFFFFF) | 0x10000000000000;
	// mantissa = 262144;
	printf("mantissa: %llu\n", mantissa);
	ft_printbits(mantissa, 64);
	ft_putchar('\n');
	exponent = ((fnum.ll >> 52) & 0x7FF) - 1023;
	printf("exponent: %llu\n", exponent);
	ft_printbits(exponent, 64);
	ft_putchar('\n');
	ft_reset_bigint(res_bigint);
	ft_reset_bigint(temp_bigint);
	power = 0;
	index = 0;
	max_index = 0;
	while (power < COUNT_BITS)
	{
		if (ft_checkbit(fnum.ll, power))
		{
			printf("HELLO1\n");
			if (power == 0)
				powers[power] = exponent - 23;
			else
				powers[power] = power * (exponent - 23);
			ft_set_bigint(temp_bigint, powers[power]);
			printf("HELLO2\n");
			ft_bigint_sum_bigint(res_bigint, temp_bigint);
			printf("HELLO3\n");
			ft_reset_bigint(temp_bigint);
			printf("HELLO4\n");
		}
		else
			powers[power] = 0;
		power++;
	}
	ft_print_bigint(res_bigint);
	printf("\ndbl: %lf\n", DBL_MAX);
	return (0);
}