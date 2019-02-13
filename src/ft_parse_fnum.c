/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:54:27 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/13 22:54:34 by afalmer-         ###   ########.fr       */
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
		{
			number[len] += 1;
		}
		else
		{
			ft_memmove(number + 1, number, count);
			number[0] = '1';
		}
	}
	else
		number[len] = '\0';
}

char	*ft_get_ipart(t_fnum *fnum, int shift)
{
	t_bigint	bigint;
	char		*result;
	int			size;
	int			len;
	// int			numlen;

	bigint = ft_get_bigint(fnum->mantissa, fnum->exp - shift);
	// len = ft_numlen_bigint(&bigint);
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

char	*ft_get_ipart_fpart(t_fnum *fnum, int prec, int shift)
{
	char	*result;
	int		len;

	fnum->ipart = fnum->mantissa >> (52 - fnum->exp);
	fnum->fpart = (fnum->mantissa << (fnum->exp + 1)) & 0x1FFFFFFFFFFFFF;
	result = (char*)malloc(ft_unumlen(fnum->ipart, 10) + prec + 4);
	len = ft_itoa_base(fnum->ipart, result, 10, 0);
	if (prec)
	{
		result[len++] = '.';
		prec++;
		while (prec--)
		{
			fnum->fpart *= 10;
			result[len++] = (fnum->fpart >> 53) + '0';
			fnum->fpart &= 0x1FFFFFFFFFFFFF;
		}
		result[len] = '\0';
		ft_rounding_fnum(result, len - 1);
	}
}

void	ft_parse_fnum(t_options *opt, t_buff *buffer, double num)
{
	t_fnum	fnum;
	char	*result;

	fnum.num.f = num;
	fnum.sign = (fnum.num.ll & (1ULL << 63)) ? 1 : 0;
	fnum.exp = ((fnum.num.ll >> 52) & 0x7FF) - 1023;
	fnum.mantissa = (fnum.num.ll & 0x1FFFFFFFFFFFFF) | 0x10000000000000;
	fnum.ipart = 0;
	fnum.fpart = 0;
	if (fnum.exp >= 52)
	{
		result = ft_get_ipart(&fnum, 52);
	}
	else if (fnum.exp >= 0)
	{
		result = ft_get_ipart_fpart(&fnum, opt->prec, 52);
	}
	else
	{
		
	}
}
