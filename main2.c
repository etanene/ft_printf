/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 20:42:05 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/10 20:52:59 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "ft_printf.h"

int		ft_checkbit(int n, int pos)
{
	return ((n & (1 << pos)) != 0);
}

void	ft_printbits(int n, int count)
{
	while (count--)
	{
		ft_putchar(ft_checkbit(n, count) + '0');
		if (!(count % 8) && count)
			ft_putchar(' ');
	}
}

void	ft_print_c(int c)
{
	char	*p;

	ft_printbits(c, 32);
	ft_putchar('\n');
	p = (char*)&c;
	write(1, p, 2);
	ft_putchar('\n');
	ft_printbits(*p, 8);
	ft_putchar('\n');
	ft_printbits(*(p + 1), 8);
	ft_putchar('\n');
	if (!ft_checkbit(*p, 3) && ft_checkbit(*p, 4) && ft_checkbit(*p, 5) && ft_checkbit(*p, 6) && ft_checkbit(*p, 7))
	{
		if (!ft_checkbit(*(p + 1), 6) && ft_checkbit(*(p + 1), 7))
		{
			if (!ft_checkbit(*(p + 2), 6) && ft_checkbit(*(p + 2), 7))
			{
				if (!ft_checkbit(*(p + 3), 6) && ft_checkbit(*(p + 3), 7))
				{
					write(1, p, 4);
				}
			}
		}
	}
	else if (!ft_checkbit(*p, 4) && ft_checkbit(*p, 5) && ft_checkbit(*p, 6) && ft_checkbit(*p, 7))
	{
		if (!ft_checkbit(*(p + 1), 6) && ft_checkbit(*(p + 1), 7))
		{
			if (!ft_checkbit(*(p + 2), 6) && ft_checkbit(*(p + 2), 7))
			{
				write(1, p, 3);
			}
		}
	}
	else if (!ft_checkbit(*p, 5) && ft_checkbit(*p, 6) && ft_checkbit(*p, 7))
	{
		if (!ft_checkbit(*(p + 1), 6) && ft_checkbit(*(p + 1), 7))
		{
			write(1, p, 2);
		}
	}
	else
		write(1, p, 1);
	
}

int		main(void)
{
	int		c;
	char	s[2] = {194, 162};

	setlocale(LC_ALL, "");
	c = 41666;
	//write(1, &c, 1);
	write(1, s, 2);
	printf("\n%C\n", L'δ');
	ft_print_c(c);
	
	return (0);
}
