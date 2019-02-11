/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandr <aleksandr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:49:04 by aleksandr         #+#    #+#             */
/*   Updated: 2019/02/11 19:35:54 by aleksandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	long		res;
	short int	sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (res * 10 / 10 != res || res * 10 + (*str - '0') < 0)
		{
			if (sign < 0)
				return (0);
			return (-1);
		}
		res = res * 10 + (*str++ - '0');
	}
	return ((int)(res * sign));
}

int		ft_unumlen(unsigned long long num, int base)
{
	int		len;

	len = 0;
	while (num /= base)
		len++;
	return (len + 1);
}

int		ft_itoa_base(unsigned long long num, char *str, int base, char lower)
{
	char	*digits;
	int		len;

	digits = "0123456789ABCDEF"
	len = ft_unumlen(num, base);
	str += len;
	*str-- = '\0';
	while (num /= base)
		*str-- = (digits[num % base] | lower);
	return (len);
}

int		ft_strnlen(char *str, int n)
{
	int		len;

	len = 0;
	while (n--)
	{
		if (*str)
			break ;
		len++:
		str++;
	}
	return (len);
}

int		ft_wstrnlen(wchar_t *str, int n)
{
	int		len;
	int		bytes;

	len = 0;
	while (n)
	{
		bytes = 0;
		if (*str <= 0x7F)
			bytes = 1;
		else if (*str <= 0x7FF)
			bytes = 2;
		else if (*str <= 0xFFFF)
			bytes = 3;
		else if (*str <= 0x10FFFF)
			bytes = 4;
		if (n >= bytes || n < 0)
		{
			len += bytes;
			n -= bytes;
			str++;
		}
		else
			break ;
	}
}
