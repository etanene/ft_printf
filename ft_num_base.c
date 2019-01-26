/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:44:24 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/26 16:19:39 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnumX(unsigned long long int num, unsigned long long int base)
{
	char	*strX = "0123456789ABCDEF";

	if (num >= base)
		ft_printnum(num / base, base);
	ft_putchar(strX[num % base]);
}

void	ft_printnum(unsigned long long int num, unsigned long long int base)
{
	char	*str = "0123456789abcdef";

	if (num >= base)
		ft_printnum(num / base, base);
	ft_putchar(str[num % base]);
}

double	ft_pow(int num, int pow)
{
	double	res;

	res = 1;
	while (pow--)
		res *= num;
	return (res);
}

void	ft_printnum_f(double num)
{
	double	limit;
	double	curr;

	limit = 1.0;
	// printf("\nnum: %f\n", num);
	// printf("limit: %f\n", limit);
	while (num > limit)
	{
		// printf("limit: %f\n", limit);
		limit *= 10.0;
	}
	// printf("limit: %f\n", limit / 10);
	limit /= 10.0;
	while (limit > 0.1)
	{
		curr = (int)(num / limit);
		// printf("curr: %f, num: %f, limit: %f\n", curr, num, limit);
		ft_putchar(curr + '0');
		num = num - limit * curr;
		limit /= 10.0;
	}
}

int		ft_unumlen(unsigned long long int num, int base)
{
	int		len;

	len = 0;
	while (num /= base)
		len++;
	return (len + 1);
}
