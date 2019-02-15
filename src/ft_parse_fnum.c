/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:54:27 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/15 20:24:43 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*ft_get_part(unsigned long long num, int shift, \
					t_bigint (*ft_get_bigint)(unsigned long long, int))
{
	t_bigint	bigint;
	char		*result;
	int			maxlen;
	int			numlen;
	int			size;
	int			len;

	bigint = ft_get_bigint(num, shift);
	size = bigint.size - 1;
	maxlen = ft_unumlen(MAX_NUM, 10) - 1;
	result = (char*)malloc(size * maxlen + ft_unumlen(bigint.num[size], 10) + 1);
	len = ft_itoa_base(bigint.num[size], result, 10, 0);
	while (size--)
	{
		numlen = ft_unumlen(bigint.num[size], 10);
		while (numlen++ < maxlen)
			result[len++] = '0';
		if (!bigint.num[size])
			result[len++] = '0';
		else
			len += ft_itoa_base(bigint.num[size], result + len, 10, 0);
	}
	result[len] = '\0';
	return (result);
}

// void	ft_print_f(t_options *opt, t_buff *buffer, char *ipart, char *fpart)
// {
	
// }

void	ft_parse_fnum(t_options *opt, t_buff *buffer, double num)
{
	t_fnum	fnum;
	char	*ipart;
	char	*fpart;
	int		temp;

	temp = buffer->i;
	temp = opt->prec;

	fnum.num.f = num;
	fnum.sign = (fnum.num.ll & (1ULL << 63)) ? 1 : 0;
	fnum.exp = ((fnum.num.ll >> 52) & 0x7FF) - 1023;
	fnum.mantissa = (fnum.num.ll & 0x1FFFFFFFFFFFFF) | 0x10000000000000;
	ipart = NULL;
	fpart = NULL;
	printf("exp: %d\n", fnum.exp);
	if (fnum.exp >= 52)
		ipart = ft_get_part(fnum.mantissa, fnum.exp - 52, ft_get_ipart);
	else if (fnum.exp >= 0)
	{
		ipart = ft_get_part(fnum.mantissa >> (52 - fnum.exp), 0, ft_get_ipart);
		fpart = ft_get_part(fnum.mantissa << (fnum.exp + 12), 0, ft_get_fpart);
	}
	else
		fpart = ft_get_part(fnum.mantissa << 11, -(fnum.exp + 1), ft_get_fpart);
	// ft_print_f(opt, buffer, ipart, fpart);
	printf("ipart: %s\n", ipart);
	printf("fpart: %s\n", fpart);
}
