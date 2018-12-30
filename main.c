/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:43:48 by afalmer-          #+#    #+#             */
/*   Updated: 2018/12/30 18:56:18 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int     main(void)
{
	printf("\n%%d\n");
	printf("original: num: %d, -num: %d\n", 21, -21);
	ft_printf("customft: num: %d, -num: %d\n", 21, -21);
	printf("original: MAX: %d, MIN: %d\n", INT_MAX, INT_MIN);
	ft_printf("customft: MAX: %d, MIN: %d\n", INT_MAX, INT_MIN);
	printf("original: MAX+1: %d, MIN-1: %d\n", INT_MAX + 1, INT_MIN - 1);
	ft_printf("customft: MAX+1: %d, MIN-1: %d\n", INT_MAX + 1, INT_MIN - 1);
	printf("original: MAX+21: %d, MIN-21: %d\n", INT_MAX + 21, INT_MIN - 21);
	ft_printf("customft: MAX+21: %d, MIN-21: %d\n", INT_MAX + 21, INT_MIN - 21);


	return (0);
}
