/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandr <aleksandr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 20:42:05 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/11 21:21:32 by aleksandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <math.h>
#include <fcntl.h>
#include <float.h>
#include <limits.h>
#include <wchar.h>
//#include "ft_printf.h"

// int		ft_checkbit_double(double n, int pos)
// {
// 	unsigned long	*f;

// 	f = (unsigned long*)&n;
// 	return ((*f & (1UL << pos)) != 0);
// }

// void	ft_printbits_double(double n)
// {
// 	int		count;

// 	count = 64;
// 	while (count--)
// 	{
// 		ft_putchar(ft_checkbit_double(n, count) + '0');
// 		if ((count == 63 || count == 52 || (count < 52 && count % 8 == 0)) && count)
// 			ft_putchar(' ');
// 	}
// }


int		main(void)
{
	int		len;

	len = printf("%zu\n", sizeof(wchar_t));
	printf("len: %d\n", len);
	return (0);
}
