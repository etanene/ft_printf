/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:43:48 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/05 19:05:05 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <float.h>
#include <time.h>
#include <wchar.h>

int     main(void)
{
/*
	long int		ld = 3124141;
	int				d = 2142;
	long long int	lld = 234234242424242;
	int				len = 0;

	printf("\nFLAGS\n");
	len = printf("original1: %ld world %d hello %lld\n", ld, d, lld);
	printf("len: %d\n", len);
	len = ft_printf("customft1: %ld world %d hello %lld\n", ld, d, lld);
	printf("len: %d\n\n", len);
	len = printf("original2: % d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft2: % d hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original3: % d hello\n", -d);
	printf("len: %d\n", len);
	len = ft_printf("customft3: % d hello\n", -d);
	printf("len: %d\n\n", len);
	len = printf("original4: %+d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft4: %+d hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original5: % +d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft5: % +d hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original6: %+ d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft6: %+ d hello\n", d);
	printf("len: %d\n\n", len);

	printf("\nWIDTH\n");
	len = printf("original7: %10d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft7: %10d hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original8: % 10d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft8: % 10d hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original9: % 10d hello\n", -d);
	printf("len: %d\n", len);
	len = ft_printf("customft9: % 10d hello\n", -d);
	printf("len: %d\n\n", len);
	len = printf("original10: %+10d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft10: %+10d hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original11: %010d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft11: %010d hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original12: %-10d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft12: %-10d hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original13: %+-10d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft13: %+-10d hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original14: %- 010d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft14: %- 010d hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original15: %0010d hello\n", -d);
	printf("len: %d\n", len);
	len = ft_printf("customft15: %0010d hello\n", -d);
	printf("len: %d\n\n", len);

	printf("\nPRECISION\n");
	len = printf("original16: %.d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft16: %.d hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original17: %.5d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft17: %.5d hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original18: %0.5d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft18: %0.5d hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original19: %-.5d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft19: %-.5d hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original20: % .5d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft20: % .5d hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original21: %10.5d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft21: %10.5d hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original22: %5.10d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft22: %5.10d hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original23: %+5.10d hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft23: %+5.10d hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original24: %5.10d hello\n", -d);
	printf("len: %d\n", len);
	len = ft_printf("customft24: %5.10d hello\n", -d);
	printf("len: %d\n\n", len);
	len = printf("original25: %010.5d hello\n", d, d, d);
	printf("len: %d\n", len);
	len = ft_printf("customft25: %010.5d hello\n", d, d, d);
	printf("len: %d\n\n", len);
	len = printf("original26: %05.10d hello\n", d, d, d);
	printf("len: %d\n", len);
	len = ft_printf("customft26: %05.10d hello\n", d, d, d);
	printf("len: %d\n\n", len);
	len = printf("original27: %-010.5d hello\n", d, d);
	printf("len: %d\n", len);
	len = ft_printf("customft27: %-010.5d hello\n", d, d);
	printf("len: %d\n\n", len);
*/
/*
	long int		lu = 3124141;
	int				u = 2142;
	long long int	llu = 234234242424242;
	int				len = 0;

	printf("\nFLAGS\n");
	len = printf("original1: %lu worlu %u hello %llu\n", lu, u, llu);
	printf("len: %u\n", len);
	len = ft_printf("customft1: %lu worlu %u hello %llu\n", lu, u, llu);
	printf("len: %u\n\n", len);
	len = printf("original2: % u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft2: % u hello\n", u);
	printf("len: %u\n\n", len);
	len = printf("original3: % u hello\n", -u);
	printf("len: %u\n", len);
	len = ft_printf("customft3: % u hello\n", -u);
	printf("len: %u\n\n", len);
	len = printf("original4: %+u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft4: %+u hello\n", u);
	printf("len: %u\n\n", len);
	len = printf("original5: % +u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft5: % +u hello\n", u);
	printf("len: %u\n\n", len);
	len = printf("original6: %+ u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft6: %+ u hello\n", u);
	printf("len: %u\n\n", len);

	printf("\nWIDTH\n");
	len = printf("original7: %10u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft7: %10u hello\n", u);
	printf("len: %u\n\n", len);
	len = printf("original8: % 10u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft8: % 10u hello\n", u);
	printf("len: %u\n\n", len);
	len = printf("original9: % 10u hello\n", -u);
	printf("len: %u\n", len);
	len = ft_printf("customft9: % 10u hello\n", -u);
	printf("len: %u\n\n", len);
	len = printf("original10: %+10u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft10: %+10u hello\n", u);
	printf("len: %u\n\n", len);
	len = printf("original11: %010u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft11: %010u hello\n", u);
	printf("len: %u\n\n", len);
	len = printf("original12: %-10u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft12: %-10u hello\n", u);
	printf("len: %u\n\n", len);
	len = printf("original13: %+-10u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft13: %+-10u hello\n", u);
	printf("len: %u\n\n", len);
	len = printf("original14: %- 010u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft14: %- 010u hello\n", u);
	printf("len: %u\n\n", len);
	len = printf("original15: %0010u hello\n", -u);
	printf("len: %u\n", len);
	len = ft_printf("customft15: %0010u hello\n", -u);
	printf("len: %u\n\n", len);

	printf("\nPRECISION\n");
	len = printf("original16: %.u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft16: %.u hello\n", u);
	printf("len: %u\n\n", len);
	len = printf("original17: %.5u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft17: %.5u hello\n", u);
	printf("len: %u\n\n", len);
	len = printf("original18: %0.5u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft18: %0.5u hello\n", u);
	printf("len: %u\n\n", len);
	len = printf("original19: %-.5u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft19: %-.5u hello\n", u);
	printf("len: %u\n\n", len);
	len = printf("original20: % .5u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft20: % .5u hello\n", u);
	printf("len: %u\n\n", len);
	len = printf("original21: %10.5u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft21: %10.5u hello\n", u);
	printf("len: %u\n\n", len);
	len = printf("original22: %5.10u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft22: %5.10u hello\n", u);
	printf("len: %u\n\n", len);
	len = printf("original23: %+5.10u hello\n", u);
	printf("len: %u\n", len);
	len = ft_printf("customft23: %+5.10u hello\n", u);
	printf("len: %u\n\n", len);
	len = printf("original24: %5.10u hello\n", -u);
	printf("len: %u\n", len);
	len = ft_printf("customft24: %5.10u hello\n", -u);
	printf("len: %u\n\n", len);
	len = printf("original25: %010.5u hello\n", u, u, u);
	printf("len: %u\n", len);
	len = ft_printf("customft25: %010.5u hello\n", u, u, u);
	printf("len: %u\n\n", len);
	len = printf("original26: %05.10u hello\n", u, u, u);
	printf("len: %u\n", len);
	len = ft_printf("customft26: %05.10u hello\n", u, u, u);
	printf("len: %u\n\n", len);
	len = printf("original27: %-010.5u hello\n", u, u);
	printf("len: %u\n", len);
	len = ft_printf("customft27: %-010.5u hello\n", u, u);
	printf("len: %u\n\n", len);
*/
/*
	long int		lo = 3124141;
	int				d = 2142;
	long long int	llo = 234234242424242;
	int				len = 0;

	printf("\noxX\n");
	len = printf("original28: %010.5X hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft28: %010.5X hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original29: %+010.5X hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft29: %+010.5X hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original30: %-010.5x hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft30: %-010.5x hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original31: % #10.5X hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft31: % #10.5X hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original32: %+#10.5x hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft32: %+#10.5x hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original33: % #10.5X hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft33: % #10.5X hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original34: % #010X hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft34: % #010X hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original42: %-#010.5x hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft42: %-#010.5x hello\n", d);
	printf("len: %d\n", len);


	len = printf("original35: % #10.5o hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft35: % #10.5o hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original36: %+#10.5o hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft36: %+#10.5o hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original37: % #o hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft37: % #o hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original38: % o hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft38: % o hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original39: %010o hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft39: %010o hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original40: %#10o hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft40: %#10o hello\n", d);
	printf("len: %d\n\n", len);
	len = printf("original41: %#10o hello\n", d);
	printf("len: %d\n", len);
	len = ft_printf("customft41: %#10o hello\n", d);
	printf("len: %d\n\n", len);
*/
/*
	int		c = 100;
	int		len;

	setlocale(LC_ALL, "");
	len = printf("original43: %10.5c world\n", c);
	printf("len: %d\n", len);
	len = ft_printf("customft43: %10.5c world\n", c);
	printf("len: %d\n", len);
	len = printf("original44: %10.5C world\n", c);
	printf("len: %d\n", len);
	len = ft_printf("customft44: %10.5C world\n", c);
	printf("len: %d\n", len);
	len = printf("original45: %-10.5C world\n", c);
	printf("len: %d\n", len);
	len = ft_printf("customft45: %-10.5C world\n", c);
	printf("len: %d\n", len);
	c = 6512;
	len = printf("original46: %10.5C world\n", c);
	printf("len: %d\n", len);
	len = ft_printf("customft46: %10.5C world\n", c);
	printf("len: %d\n", len);
	len = printf("original47: %10.5C world\n", L'֍');
	printf("len: %d\n", len);
	len = ft_printf("customft47: %10.5C world\n", L'֍');
	printf("len: %d\n", len);
	len = printf("original48: %-10.5C world\n", L'֍');
	printf("len: %d\n", len);
	len = ft_printf("customft48: %-10.5C world\n", L'֍');
	printf("len: %d\n", len);
*/
/*
	int		len;

	setlocale(LC_ALL, "");
	len = printf("original49: %s world\n", "hellO");
	printf("len: %d\n", len);
	len = ft_printf("customft49: %s world\n", "hellO");
	printf("len: %d\n", len);
	len = printf("original50: %10.3s world\n", "hellO");
	printf("len: %d\n", len);
	len = ft_printf("customft50: %10.3s world\n", "hellO");
	printf("len: %d\n", len);
	len = printf("original51: %10.0s world\n", "hellO");
	printf("len: %d\n", len);
	len = ft_printf("customft51: %10.0s world\n", "hellO");
	printf("len: %d\n", len);
	len = printf("original52: %0.3s world\n", "hellO");
	printf("len: %d\n", len);
	len = ft_printf("customft52: %0.3s world\n", "hellO");
	printf("len: %d\n", len);
	len = printf("original53: %.0s world\n", "hellO");
	printf("len: %d\n", len);
	len = ft_printf("customft53: %.0s world\n", "hellO");
	printf("len: %d\n", len);
	len = printf("original54: %0s world\n", "hellO");
	printf("len: %d\n", len);
	len = ft_printf("customft54: %0s world\n", "hellO");
	printf("len: %d\n", len);
	len = printf("original54: %-10.3s world\n", "hellO");
	printf("len: %d\n", len);
	len = ft_printf("customft54: %-10.3s world\n", "hellO");
	printf("len: %d\n", len);
	len = printf("original55: %S world\n", L"he֍llO֍");
	printf("len: %d\n", len);
	len = ft_printf("customft55: %S world\n", L"he֍llO֍");
	printf("len: %d\n", len);
	len = printf("original56: %10.6S world\n", L"he֍llO֍");
	printf("len: %d\n", len);
	len = ft_printf("customft56: %10.6S world\n", L"he֍llO֍");
	printf("len: %d\n", len);
	len = printf("original57: %10.0S world\n", L"he֍llO֍");
	printf("len: %d\n", len);
	len = ft_printf("customft57: %10.0S world\n", L"he֍llO֍");
	printf("len: %d\n", len);
	len = printf("original58: %0.6S world\n", L"he֍llO֍");
	printf("len: %d\n", len);
	len = ft_printf("customft58: %0.6S world\n", L"he֍llO֍");
	printf("len: %d\n", len);
	len = printf("original59: %.0S world\n", L"he֍llO֍");
	printf("len: %d\n", len);
	len = ft_printf("customft59: %.0S world\n", L"he֍llO֍");
	printf("len: %d\n", len);
	len = printf("original60: %0S world\n", L"he֍llO֍");
	printf("len: %d\n", len);
	len = ft_printf("customft60: %0S world\n", L"he֍llO֍");
	printf("len: %d\n", len);
	len = printf("original61: %-10.6S world\n", L"he֍llO֍");
	printf("len: %d\n", len);
	len = ft_printf("customft61: %-10.6S world\n", L"he֍llO֍");
	printf("len: %d\n", len);
*/

	// int		len;

	// len = printf("original62: %f world\n", 21);
	// printf("len: %d\n", len);
	// len = ft_printf("customft62: %f world\n", 21);
	// printf("len: %d\n", len);
	// len = printf("original63: %f world\n", 21.21);
	// printf("len: %d\n", len);
	// len = ft_printf("customft63: %f world\n", 21.21);
	// printf("len: %d\n", len);
	// len = printf("original64: %f world\n", -818.375);
	// printf("len: %d\n", len);
	// len = ft_printf("customft64: %f world\n", -818.375);
	// printf("len: %d\n", len);
	// len = printf("original65: %f world\n", 21.0);
	// printf("len: %d\n", len);
	// len = ft_printf("customft65: %f world\n", 21.0);
	// printf("len: %d\n", len);
	// len = printf("original66: %f world\n", 21.123456789);
	// printf("len: %d\n", len);
	// len = ft_printf("customft66: %f world\n", 21.123456789);
	// printf("len: %d\n", len);
	// len = printf("original67: %f world\n", 21.123456123);
	// printf("len: %d\n", len);
	// len = ft_printf("customft67: %f world\n", 21.123456123);
	// printf("len: %d\n", len);
	// len = printf("original68: %lf world\n", 21.123456123);
	// printf("len: %d\n", len);
	// len = ft_printf("customft68: %lf world\n", 21.123456123);
	// printf("len: %d\n", len);
	// len = printf("original69: %lf world\n", 21.123456467);
	// printf("len: %d\n", len);
	// len = ft_printf("customft69: %lf world\n", 21.123456467);
	// printf("len: %d\n", len);
	// len = printf("original70: %lf world\n", 2131231144141.123456123);
	// printf("len: %d\n", len);
	// len = ft_printf("customft70: %lf world\n", 2131231144141.123456123);
	// printf("len: %d\n", len);
	// len = printf("original71: %lf world\n", DBL_MAX);
	// printf("len: %d\n", len);
	// len = ft_printf("customft71: %lf world\n", DBL_MAX);
	// printf("len: %d\n", len);
	// len = printf("original72: %lf world\n", DBL_MIN);
	// printf("len: %d\n", len);
	// len = ft_printf("customft72: %lf world\n", DBL_MIN);
	// printf("len: %d\n", len);
	// len = printf("original73: %Lf world\n", -818.375L);
	// printf("len: %d\n", len);
	// len = ft_printf("customft73: %Lf world\n", -818.375L);
	// printf("len: %d\n", len);
	// len = printf("original74: %.10Lf world\n", 1.512542325252525251313141L);
	// printf("len: %d\n", len);
	// len = ft_printf("customft74: %.10Lf world\n", 1.512542325252525251313141L);
	// printf("len: %d\n", len);
	// len = printf("original75: %Lf world\n", 21.123456123L);
	// printf("len: %d\n", len);
	// len = ft_printf("customft75: %Lf world\n", 21.123456123);
	// printf("len: %d\n", len);
	// len = printf("original76: %Lf world\n", 2131231144141.123456123L);
	// printf("len: %d\n", len);
	// len = ft_printf("customft76: %Lf world\n", 2131231144141.123456123);
	// printf("len: %d\n", len);
	// len = printf("original77: %Lf world\n", LDBL_MAX);
	// printf("len: %d\n", len);
	// len = ft_printf("customft77: %Lf world\n", LDBL_MAX);
	// printf("len: %d\n", len);

	// int		len;

	// len = ft_printf("customft77: %#.*b world\n", 8, 23);
	// printf("len: %d\n", len);
	// len = ft_printf("customft78: %k world\n", 20181124);
	// printf("len: %d\n", len);
	// len = ft_printf("customft79: %tk world\n", 402311);
	// printf("len: %d\n", len);
	// len = ft_printf("customft80: %.3r world\n", "\tstring\n");
	// printf("len: %d\n", len);
	// len = ft_printf("customft81: %X world\n", -42);
	// printf("len: %d\n", len);

	int		len;
	len = printf("original82: %#x world\n", 0);
	printf("len: %d\n", len);
	len = ft_printf("customft82: %#x world\n", 0);
	printf("len: %d\n", len);
	len = printf("original83: %#.x %#.0x world\n", 0, 0);
	printf("len: %d\n", len);
	len = ft_printf("customft83: %#.x %#.0x world\n", 0, 0);
	printf("len: %d\n", len);
	len = printf("original84: %#.x %#.0x world\n", 21, 21);
	printf("len: %d\n", len);
	len = ft_printf("customft84: %#.x %#.0x world\n", 21, 21);
	printf("len: %d\n", len);
	len = printf("original85: %#5.x %#5.0x world\n", 0, 0);
	printf("len: %d\n", len);
	len = ft_printf("customft85: %#5.x %#5.0x world\n", 0, 0);
	printf("len: %d\n", len);
	

	//int		len;
	// int		num;
	// long long int num;
	// char		*s = "HELLO";
	// void		*p;

	// num = 63;
	// p = &num;
	// printf("\np\n");
	// len = printf("original73: %p world\n", &num);
	// printf("len: %d\n", len);
	// len = ft_printf("customft73: %p world\n", &num);
	// printf("len: %d\n", len);
	// len = printf("original74: %p world\n", s);
	// printf("len: %d\n", len);
	// len = ft_printf("customft74: %p world\n", s);
	// printf("len: %d\n", len);
	// len = printf("original75: %20p world\n", s);
	// printf("len: %d\n", len);
	// len = ft_printf("customft75: %20p world\n", s);
	// printf("len: %d\n", len);
	// len = printf("original76: %020p world\n", s);
	// printf("len: %d\n", len);
	// len = ft_printf("customft76: %020p world\n", s);
	// printf("len: %d\n", len);
	// len = printf("original77: %-20p world\n", s);
	// printf("len: %d\n", len);
	// len = ft_printf("customft77: %-20p world\n", s);
	// printf("len: %d\n", len);

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
