/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainlong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:44:46 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/27 18:36:30 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define COUNT_BITS 64
#define MAX_POWER 15
#define MAX_NUM 1000000000000000UL
#define MAX_INDEX 32

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printnum(unsigned long long int num, unsigned long long int base)
{
	char	*str = "0123456789abcdef";

	if (num >= base)
		ft_printnum(num / base, base);
	ft_putchar(str[num % base]);
}

int		ft_unumlen(unsigned long long int num, int base)
{
	int		len;

	len = 0;
	while (num /= base)
		len++;
	return (len + 1);
}

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

void	ft_print_bigint(unsigned long long *bigint)
{
	int		i;

	i = MAX_INDEX;
	while (i--)
	{
		if (bigint[i] != 0)
		{
			ft_print_width(3 - ft_unumlen(bigint[i], 10), '0');
			ft_printnum(bigint[i], 10);
		}
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

void	ft_bigint_sum_bigint(unsigned long long *bigint1, \
							unsigned long long *bigint2)
{
	int					i;
	unsigned long long	temp;

	i = 0;
	temp = 0;
	while (i < MAX_INDEX)
	{
		bigint1[i] += temp + bigint2[i];
		temp = (bigint1[i] >= MAX_NUM);
		if (temp)
			bigint1[i] -= MAX_NUM;
		i++;
	}
}

void	ft_bigint_multi_int(unsigned long long *bigint, unsigned long long num)
{
	int					i;
	unsigned long long	temp;
	unsigned long long	div;

	i = 0;
	div = 0;
	while (i < MAX_INDEX)
	{
		temp = div + bigint[i] * num;
		bigint[i] = temp % MAX_NUM;
		div = temp / MAX_NUM;
		i++;
	}
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