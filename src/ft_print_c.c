/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandr <aleksandr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:05:27 by aleksandr         #+#    #+#             */
/*   Updated: 2019/02/11 18:49:41 by aleksandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(t_options *opt, t_buff *buffer, unsigned char c)
{
	// if (opt->flags & F_MINUS)
	// 	opt->flags &= ~F_NULL;
	opt->width--;
	if (!(opt->flags & F_MINUS))
		ft_print_width(buffer, &opt->width, (opt->flags & F_NULL) ? '0' : ' ');
	ft_in_buff(buffer, c);
	if (opt->flags & F_MINUS)
		ft_print_width(buffer, &opt->width, ' ');
}

int		ft_convert_to_utf8(wint_t c, char *lc)
{
	int		bytes;

	bytes = 0;
	if (++bytes && c <= 0x7F)
		lc[0] = c;
	else if (++bytes && utf32 <= 0x7FF)
	{
		lc[0] = 0xC0 | (c >> 6);
		lc[1] = 0x80 | (c & 0x3F);
	}
	else if (++bytes && utf32 <= 0xFFFF)
	{
		lc[0] = 0xE0 | (c >> 12);
		lc[1] = 0x80 | ((c >> 6) & 0x3F);
		lc[2] = 0x80 | (c & 0x3F);
	}
	else if (++bytes && utf32 <= 0x10FFFF)
	{
		lc[0] = 0xF0 | (c >> 18);
		lc[1] = 0x80 | ((c >> 12) & 0x3F);
		lc[2] = 0x80 | ((c >> 6) & 0x3F);
		lc[3] = 0x80 | (c & 0x3F);
	}
	return (c <= 0x10FFFF ? bytes : 0);
}

void	ft_print_lc(t_options *opt, t_buff *buffer, wint_t c)
{
	int		bytes;
	char	lc[4];

	bytes = ft_convert_to_utf8(c, lc);
	opt->width -= bytes;
	if (!(opt->flags & F_MINUS))
		ft_print_width(buffer, &opt->width, (opt->flags & F_NULL) ? '0' : ' ');
	while (bytes--)
		ft_in_buff(buffer, *lc++);
	if (opt->flags & F_MINUS)
		ft_print_width(buffer, &opt->width, ' ');
}
