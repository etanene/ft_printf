/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:43:48 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/06 15:22:07 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int     main(void)
{
	int		d = 21;
	printf("flags && width\n");
	printf("original: %d hello\n", d);
	ft_printf("customft: %d hello\n\n", d);
	printf("original: % d hello\n", d);
	ft_printf("customft: % d hello\n\n", d);
	printf("original: % d hello\n", -d);
	ft_printf("customft: % d hello\n\n", -d);
	printf("original: %+d hello\n", d);
	ft_printf("customft: %+d hello\n\n", d);
	printf("original: % +d hello\n", d);
	ft_printf("customft: % +d hello\n\n", d);
	printf("original: %+ d hello\n", d);
	ft_printf("customft: %+ d hello\n\n", d);

	printf("original: %10d hello\n", d);
	ft_printf("customft: %10d hello\n\n", d);
	printf("original: % 10d hello\n", d);
	ft_printf("customft: % 10d hello\n\n", d);
	printf("original: % 10d hello\n", -d);
	ft_printf("customft: % 10d hello\n\n", -d);
	printf("original: %+10d hello\n", d);
	ft_printf("customft: %+10d hello\n\n", d);
	printf("original: %010d hello\n", d);
	ft_printf("customft: %010d hello\n\n", d);
	printf("original: %-10d hello\n", d);
	ft_printf("customft: %-10d hello\n\n", d);
	printf("original: %+-10d hello\n", d);
	ft_printf("customft: %+-10d hello\n\n", d);
	printf("original: %0010d hello\n", -d);
	ft_printf("customft: %0010d hello\n\n", -d);
	printf("original: %- 010d hello\n", d);
	ft_printf("customft: %- 010d hello\n\n", d);
/*
	int						d = 21;
	printf("\n%%d\n");
	printf("original: num: %d, -num: %d\n", d, -d);
	ft_printf("customft: num: %d, -num: %d\n", d, -d);
	printf("original: MAX: %d, MIN: %d\n", INT_MAX, INT_MIN);
	ft_printf("customft: MAX: %d, MIN: %d\n", INT_MAX, INT_MIN);
	printf("original: MAX+1: %d, MIN-1: %d\n", INT_MAX + 1, INT_MIN - 1);
	ft_printf("customft: MAX+1: %d, MIN-1: %d\n", INT_MAX + 1, INT_MIN - 1);
	printf("original: MAX+21: %d, MIN-21: %d\n", INT_MAX + 21, INT_MIN - 21);
	ft_printf("customft: MAX+21: %d, MIN-21: %d\n", INT_MAX + 21, INT_MIN - 21);

	unsigned int			u = 21;
	printf("\n%%u\n");
	printf("original: num: %u, -num: %u\n", u, -u);
	ft_printf("customft: num: %u, -num: %u\n", u, -u);
	printf("original: MAX: %u, MIN: %u\n", UINT_MAX, INT_MIN);
	ft_printf("customft: MAX: %u, MIN: %u\n", UINT_MAX, INT_MIN);
	printf("original: MAX+1: %u, MIN-1: %u\n", UINT_MAX + 1, INT_MIN - 1);
	ft_printf("customft: MAX+1: %u, MIN-1: %u\n", UINT_MAX + 1, INT_MIN - 1);
	printf("original: MAX+21: %u, MIN-21: %u\n", UINT_MAX + 21, INT_MIN - 21);
	ft_printf("customft: MAX+21: %u, MIN-21: %u\n", UINT_MAX + 21, INT_MIN - 21);

	char					hhd = 21;
	printf("\n%%hhd\n");
	printf("original: num: %hhd, -num: %hhd\n", hhd, -hhd);
	ft_printf("customft: num: %hhd, -num: %hhd\n", hhd, -hhd);
	printf("original: MAX: %hhd, MIN: %hhd\n", CHAR_MAX, CHAR_MIN);
	ft_printf("customft: MAX: %hhd, MIN: %hhd\n", CHAR_MAX, CHAR_MIN);
	printf("original: MAX+1: %hhd, MIN-1: %hhd\n", CHAR_MAX + 1, CHAR_MIN - 1);
	ft_printf("customft: MAX+1: %hhd, MIN-1: %hhd\n", CHAR_MAX + 1, CHAR_MIN - 1);
	printf("original: MAX+21: %hhd, MIN-21: %hhd\n", CHAR_MAX + 21, CHAR_MIN - 21);
	ft_printf("customft: MAX+21: %hhd, MIN-21: %hhd\n", CHAR_MAX + 21, CHAR_MIN - 21);

	unsigned char			hhu = 21;
	printf("\n%%hhu\n");
	printf("original: num: %hhu, -num: %hhu\n", hhu, -hhu);
	ft_printf("customft: num: %hhu, -num: %hhu\n", hhu, -hhu);
	printf("original: MAX: %hhu, MIN: %hhu\n", UCHAR_MAX, CHAR_MIN);
	ft_printf("customft: MAX: %hhu, MIN: %hhu\n", UCHAR_MAX, CHAR_MIN);
	printf("original: MAX+1: %hhu, MIN-1: %hhu\n", UCHAR_MAX + 1, CHAR_MIN - 1);
	ft_printf("customft: MAX+1: %hhu, MIN-1: %hhu\n", UCHAR_MAX + 1, CHAR_MIN - 1);
	printf("original: MAX+21: %hhu, MIN-21: %hhu\n", UCHAR_MAX + 21, CHAR_MIN - 21);
	ft_printf("customft: MAX+21: %hhu, MIN-21: %hhu\n", UCHAR_MAX + 21, CHAR_MIN - 21);

	short int				hd = 21;
	printf("\n%%hd\n");
	printf("original: num: %hd, -num: %hd\n", hd, -hd);
	ft_printf("customft: num: %hd, -num: %hd\n", hd, -hd);
	printf("original: MAX: %hd, MIN: %hd\n", SHRT_MAX, SHRT_MIN);
	ft_printf("customft: MAX: %hd, MIN: %hd\n", SHRT_MAX, SHRT_MIN);
	printf("original: MAX+1: %hd, MIN-1: %hd\n", SHRT_MAX + 1, SHRT_MIN - 1);
	ft_printf("customft: MAX+1: %hd, MIN-1: %hd\n", SHRT_MAX + 1, SHRT_MIN - 1);
	printf("original: MAX+21: %hd, MIN-21: %hd\n", SHRT_MAX + 21, SHRT_MIN - 21);
	ft_printf("customft: MAX+21: %hd, MIN-21: %hd\n", SHRT_MAX + 21, SHRT_MIN - 21);

	unsigned short int		hu = 21;
	printf("\n%%hu\n");
	printf("original: num: %hu, -num: %hu\n", hu, -hu);
	ft_printf("customft: num: %hu, -num: %hu\n", hu, -hu);
	printf("original: MAX: %hu, MIN: %hu\n", USHRT_MAX, SHRT_MIN);
	ft_printf("customft: MAX: %hu, MIN: %hu\n", USHRT_MAX, SHRT_MIN);
	printf("original: MAX+1: %hu, MIN-1: %hu\n", USHRT_MAX + 1, SHRT_MIN - 1);
	ft_printf("customft: MAX+1: %hu, MIN-1: %hu\n", USHRT_MAX + 1, SHRT_MIN - 1);
	printf("original: MAX+21: %hu, MIN-21: %hu\n", USHRT_MAX + 21, SHRT_MIN - 21);
	ft_printf("customft: MAX+21: %hu, MIN-21: %hu\n", USHRT_MAX + 21, SHRT_MIN - 21);

	long int				ld = 21;
	printf("\n%%ld\n");
	printf("original: num: %ld, -num: %ld\n", ld, -ld);
	ft_printf("customft: num: %ld, -num: %ld\n", ld, -ld);
	printf("original: MAX: %ld, MIN: %ld\n", LONG_MAX, LONG_MIN);
	ft_printf("customft: MAX: %ld, MIN: %ld\n", LONG_MAX, LONG_MIN);
	printf("original: MAX+1: %ld, MIN-1: %ld\n", LONG_MAX + 1, LONG_MIN - 1);
	ft_printf("customft: MAX+1: %ld, MIN-1: %ld\n", LONG_MAX + 1, LONG_MIN - 1);
	printf("original: MAX+21: %ld, MIN-21: %ld\n", LONG_MAX + 21, LONG_MIN - 21);
	ft_printf("customft: MAX+21: %ld, MIN-21: %ld\n", LONG_MAX + 21, LONG_MIN - 21);

	unsigned long int		lu = 21;
	printf("\n%%lu\n");
	printf("original: num: %lu, -num: %lu\n", lu, -lu);
	ft_printf("customft: num: %lu, -num: %lu\n", lu, -lu);
	printf("original: MAX: %lu, MIN: %lu\n", ULONG_MAX, LONG_MIN);
	ft_printf("customft: MAX: %lu, MIN: %lu\n", ULONG_MAX, LONG_MIN);
	printf("original: MAX+1: %lu, MIN-1: %lu\n", ULONG_MAX + 1, LONG_MIN - 1);
	ft_printf("customft: MAX+1: %lu, MIN-1: %lu\n", ULONG_MAX + 1, LONG_MIN - 1);
	printf("original: MAX+21: %lu, MIN-21: %lu\n", ULONG_MAX + 21, LONG_MIN - 21);
	ft_printf("customft: MAX+21: %lu, MIN-21: %lu\n", ULONG_MAX + 21, LONG_MIN - 21);

	long long int			lld = 21;
	printf("\n%%lld\n");
	printf("original: num: %lld, -num: %lld\n", lld, -lld);
	ft_printf("customft: num: %lld, -num: %lld\n", lld, -lld);
	printf("original: MAX: %lld, MIN: %lld\n", LLONG_MAX, LLONG_MIN);
	ft_printf("customft: MAX: %lld, MIN: %lld\n", LLONG_MAX, LLONG_MIN);
	printf("original: MAX+1: %lld, MIN-1: %lld\n", LLONG_MAX + 1, LLONG_MIN - 1);
	ft_printf("customft: MAX+1: %lld, MIN-1: %lld\n", LLONG_MAX + 1, LLONG_MIN - 1);
	printf("original: MAX+21: %lld, MIN-21: %lld\n", LLONG_MAX + 21, LLONG_MIN - 21);
	ft_printf("customft: MAX+21: %lld, MIN-21: %lld\n", LLONG_MAX + 21, LLONG_MIN - 21);

	unsigned long long int	llu = 21;
	printf("\n%%llu\n");
	printf("original: num: %llu, -num: %llu\n", llu, -llu);
	ft_printf("customft: num: %llu, -num: %llu\n", llu, -llu);
	printf("original: MAX: %llu, MIN: %llu\n", ULLONG_MAX, LLONG_MIN);
	ft_printf("customft: MAX: %llu, MIN: %llu\n", ULLONG_MAX, LLONG_MIN);
	printf("original: MAX+1: %llu, MIN-1: %llu\n", ULLONG_MAX + 1, LLONG_MIN - 1);
	ft_printf("customft: MAX+1: %llu, MIN-1: %llu\n", ULLONG_MAX + 1, LLONG_MIN - 1);
	printf("original: MAX+21: %llu, MIN-21: %llu\n", ULLONG_MAX + 21, LLONG_MIN - 21);
	ft_printf("customft: MAX+21: %llu, MIN-21: %llu\n", ULLONG_MAX + 21, LLONG_MIN - 21);
*/
	return (0);
}
