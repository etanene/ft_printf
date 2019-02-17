/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandr <aleksandr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:54:27 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/17 13:39:02 by aleksandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// int		ft_checkbit(long long n, int pos)
// {
// 	return ((n & (1UL << pos)) != 0);
// }

// void	ft_printbits(long long n, int count)
// {
// 	while (count--)
// 	{
// 		ft_putchar(ft_checkbit(n, count) + '0');
// 		if (!(count % 8) && count)
// 			ft_putchar(' ');
// 	}
// }

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
	maxlen = ft_unumlen(MAX_NUM, 10);
	result = (char*)malloc(size * maxlen + ft_unumlen(bigint.num[size], 10));
	len = ft_itoa_base(bigint.num[size], result, 10, 0);
	while (size--)
	{
		numlen = ft_unumlen(bigint.num[size], 10);
		while (numlen++ < maxlen - 1)
			result[len++] = '0';
		if (!bigint.num[size])
			result[len++] = '0';
		else
			len += ft_itoa_base(bigint.num[size], result + len, 10, 0);
	}
	result[len] = '\0';
	return (result);
}

char	ft_get_sign_f(t_options *opt, char sign)
{
	char	res;

	res = 0;
	if (sign)
	{
		res = '-';
		opt->width--;
	}
	else if (opt->flags & F_PLUS)
	{
		res = '+';
		opt->width--;
	}
	else if (opt->flags & F_SP)
	{
		sign = ' ';
		opt->width--;
	}
	if (opt->flags & F_MINUS)
		opt->flags &= ~F_NULL;
	if (opt->prec == -1)
		opt->prec = 6;
	return (res);
}

char	*ft_get_fnum(t_fnum *fnum, int prec, int ilen)
{
	char	*number;
	int		i;
	int		flen;

	i = 0;
	flen = fnum->zero + ft_strnlen(fnum->fpart, -1);
	prec += prec ? 2 : 0;
	number = (char*)malloc(ilen + prec + 1);
	while (i < ilen)
		number[i++] = *fnum->ipart++;
	if (prec)
	{
		number[i++] = '.';
		while (fnum->zero-- && (i < ilen + prec))
			number[i++] = '0';
		while (*fnum->fpart && (i < ilen + prec))
			number[i++] = *fnum->fpart++;
		if (prec - 2 < flen)
			ft_rounding(number, i - 1);
		else
			while (i < ilen + prec - 1)
				number[i++] = '0';
	}
	number[i] = '\0';
	return (number);
}

void	ft_print_f(t_options *opt, t_buff *buffer, t_fnum *fnum)
{
	int		len;
	char	sign;
	char	*number;

	sign = ft_get_sign_f(opt, fnum->sign);
	len = 0;
	if (!fnum->ipart && ++len)
		fnum->ipart = "0";
	else
		len = ft_strnlen(fnum->ipart, -1);
	if (!fnum->fpart)
		fnum->fpart = "0";
	opt->width -= opt->prec ? opt->prec + len + 1 : len;
	if (!(opt->flags & (F_NULL + F_MINUS)))
		ft_print_width(buffer, &opt->width, ' ');
	if (sign)
		ft_in_buff(buffer, sign);
	if (!(opt->flags & F_MINUS))
		ft_print_width(buffer, &opt->width, (opt->flags & F_NULL) ? '0' : ' ');
	number = ft_get_fnum(fnum, opt->prec, len);
	while (*number)
		ft_in_buff(buffer, *number++);
	ft_print_width(buffer, &opt->width, ' ');
}

int		ft_get_zero(unsigned long long num, int shift, char *fpart)
{
	int		len;
	int		zero;
	int		power;

	len = ft_strnlen(fpart, -1);
	zero = 0;
	power = 0;
	while (power < 64)
	{
		if (num & (1ULL << power))
		{
			zero = 64 - power + shift - len;
			break;
		}
		power++;
	}
	return (zero);
}

void	ft_parse_fnum(t_options *opt, t_buff *buffer, double num)
{
	t_fnum	fnum;

	fnum.num.f = num;
	fnum.sign = (fnum.num.ll & (1ULL << 63)) ? 1 : 0;
	fnum.exp = ((fnum.num.ll >> 52) & 0x7FF) - 1023;
	fnum.man = (fnum.num.ll & 0x1FFFFFFFFFFFFF) | 0x10000000000000;
	fnum.ipart = NULL;
	fnum.fpart = NULL;
	fnum.zero = 0;
	if (fnum.exp >= 52)
		fnum.ipart = ft_get_part(fnum.man, fnum.exp - 52, ft_get_ipart);
	else if (fnum.exp >= 0)
	{
		fnum.ipart = ft_get_part(fnum.man >> (52 - fnum.exp), 0, ft_get_ipart);
		fnum.fpart = ft_get_part(fnum.man << (fnum.exp + 12), 0, ft_get_fpart);
		fnum.zero = ft_get_zero(fnum.man << (fnum.exp + 12), 0, fnum.fpart);
	}
	else
	{
		fnum.fpart = ft_get_part(fnum.man << 11, -(fnum.exp + 1), ft_get_fpart);
		fnum.zero = ft_get_zero(fnum.man << 11, -(fnum.exp + 1), fnum.fpart);
	}
	ft_print_f(opt, buffer, &fnum);
}
