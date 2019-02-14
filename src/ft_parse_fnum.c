/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:54:27 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/14 19:54:16 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rounding(char *number, int len)
{
	int		count;

	count = len;
	if (number[len] >= '5')
	{
		number[len--] = '\0';
		while (len >= 0)
		{
			if (number[len] == '9')
				number[len] = '0';
			else if (number[len] != '.')
				break;
			len--;
		}
		if (len >= 0)
			number[len] += 1;
		else
		{
			ft_memmove(number + 1, number, count);
			number[0] = '1';
		}
	}
	else
		number[len] = '\0';
}

char	*ft_get_ipart(unsigned long long num, int shift, int base)
{
	t_bigint	bigint;
	char		*result;
	int			size;
	int			len;

	bigint = ft_get_bigint(num, shift, base);
	size = bigint.size - 1;
	result = (char*)malloc(size * ft_unumlen(MAX_NUM, 10) + \
						ft_unumlen(bigint.num[size], 10) + 1);
	len = ft_itoa_base(bigint.num[size], result, 10, 0);
	while (size--)
	{
		len += ft_itoa_base(bigint.num[size], result + len, 10, 0);
	}
	result[len] = '\0';
	return (result);
}

void	ft_parse_fnum(t_options *opt, t_buff *buffer, double num)
{
	t_fnum	fnum;
	char	*ipart;
	char	*fpart;
	int		temp;

	temp = opt->prec;
	temp = buffer->i;
	fnum.num.f = num;
	fnum.sign = (fnum.num.ll & (1ULL << 63)) ? 1 : 0;
	fnum.exp = ((fnum.num.ll >> 52) & 0x7FF) - 1023;
	fnum.mantissa = (fnum.num.ll & 0x1FFFFFFFFFFFFF) | 0x10000000000000;
	ipart = NULL;
	fpart = NULL;
	if (fnum.exp >= 52)
		ipart = ft_get_ipart(fnum.mantissa, fnum.exp - 52, 2);
	else if (fnum.exp >= 0)
	{
		ipart = ft_get_ipart(fnum.mantissa >> (52 - fnum.exp), 0, 2);
		fpart = ft_get_ipart(fnum.mantissa << (fnum.exp + 12), 0, 5);
	}
	else
		fpart = ft_get_ipart(fnum.mantissa << 11, -fnum.exp, 5);
	printf("\nipart: %s\n", ipart);
	printf("fpart: %s\n", fpart);
}
