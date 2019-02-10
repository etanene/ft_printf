/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:48:22 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/29 12:54:13 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

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

unsigned long	ft_reversebits(unsigned long num)
{
	unsigned long	res;
	int				count;

	count = 64;
	res = 0UL;
	while (count--)
	{
		res <<= 1UL;
		res |= 1UL & num;
		num >>= 1UL;
	}
	return (res);
}

int		ft_check_endian(void)
{
	short int	x;

	x = 1;
	return (*((char*)&x) == 0 ? 0 : 1);
}

int		ft_swap_bytes(int n)
{
	int		count;
	int		i;
	int		res;
	char	temp;
	char	*p;

	res = n;
	p = (char*)&res;
	i = 0;
	count = 0;
	while (i < 4)
	{
		if (*(p + i) != 0)
			count++;
		i++;
	}
	i = 0;
	while (--count > i)
	{
		temp = *(p + count);
		*(p + count) = *(p + i);
		*(p + i) = temp;
		i++;
	}
	return (res);
}
