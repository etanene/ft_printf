/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:58:05 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/19 17:03:12 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <float.h>
#include <limits.h>

// typedef union			u_fnum
// {
// 	double				f;
// 	long double			lf;
// 	unsigned long long	ll;
// }						t_fnum;


int		main(void)
{
	int len;

	setlocale(LC_ALL, "");
	// len = printf("original1: %x\n", 42);
	// printf("len: %d\n", len);
	// len = ft_printf("customft1: %x\n", 42);
	// printf("len: %d\n", len);
	// len = printf("original2: %.2x\n", 5427);
	// printf("len: %d\n", len);
	// len = ft_printf("customft2: %.2x\n", 5427);
	// printf("len: %d\n", len);
	// len = printf("original3: %+04.2d\n", 1);
	// printf("len: %d\n", len);
	// len = ft_printf("customft3: %+04.2d\n", 1);
	// printf("len: %d\n", len);
	// len = printf("original4: %s\n", "abc");
	// printf("len: %d\n", len);
	// len = ft_printf("customft4: %s\n", "abc");
	// printf("len: %d\n", len);
	// len = printf("original5: %###-#0000 33...12..#0+0d", 256);
	// printf("len: %d\n", len);
	// len = ft_printf("customft5: %###-#0000 33...12..#0+0d", 256);
	// printf("len: %d\n", len);
	// len = printf("original6: %p", 0);
	// printf("len: %d\n", len);
	// len = ft_printf("customft6: %p", 0);
	// printf("len: %d\n", len);
	// len = printf("original7: %S", L"米");
	// printf("len: %d\n", len);
	// len = ft_printf("customft7: %S", L"米");
	// printf("len: %d\n", len);
	// len = printf("original8: %#.x %#.0x\n", 0, 0);
	// printf("len: %d\n", len);
	// len = ft_printf("customft8: %#.x %#.0x\n", 0, 0);
	// printf("len: %d\n", len);
	// len = printf("original9: %#.o %#.0o\n", 0, 0);
	// printf("len: %d\n", len);
	// len = ft_printf("customft9: %#.o %#.0o\n", 0, 0);
	// printf("len: %d\n", len);
	// len = printf("original10: %#o\n", 0);
	// printf("len: %d\n", len);
	// len = ft_printf("customft10: %#o\n", 0);
	// printf("len: %d\n", len);
	// len = printf("original11: %.o %.0o\n", 0, 0);
	// printf("len: %d\n", len);
	// len = ft_printf("customft11: %.o %.0o\n", 0, 0);
	// printf("len: %d\n", len);
	// len = printf("original12: %#.3o\n", 1);
	// printf("len: %d\n", len);
	// len = ft_printf("customft12: %#.3o\n", 1);
	// printf("len: %d\n", len);
	// len = printf("original13: %#.o\n", 42);
	// printf("len: %d\n", len);
	// len = ft_printf("customft13: %#.o\n", 42);
	// printf("len: %d\n", len);

	
	// printf("%.1000E\n", DBL_MIN);
	// ft_printf("%.1000E\n", DBL_MIN);
	// ft_printf("%e\n", 0.0);
	// printf("%e\n", 0.00025);
	// printf("%f f\n", DBL_MIN);
	// ft_printf("%f f\n", 0.135);
	// printf("%k\n", LDBL_MAX);
	ft_printf("%k\n", 11213);
	return (0);
}
