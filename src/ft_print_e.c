/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandr <aleksandr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:00:27 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/18 22:55:26 by aleksandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_exp(char *number, t_fnum *fnum, char spec)
{
	int		numlen;

	*number++ = spec;
	*number++ = (fnum->fpart && !fnum->ipart) ? '-' : '+';
	if (fnum->fpart && !fnum->ipart)
	{
		if ((numlen = ft_unumlen(fnum->zero, 10)) < 2)
			*number++ = '0';
		number += ft_itoa_base(fnum->zero + 1, number, 10, 0);
	}
	else
	{
		if (!fnum->ipart || ((numlen = ft_strnlen(fnum->ipart, -1)) < 11))
			*number++ = '0';
		if (!fnum->ipart || numlen == 1)
			*number++ = '0';
		else
			number += ft_itoa_base(numlen - 1, number, 10, 0);
	}
	*number = '\0';
}

char	*ft_get_enum(t_fnum *fnum, int prec, int ilen, char spec)
{
	int		i;
	int		zero;
	char	*ipart;
	char	*fpart;
	char	*number;

	prec += prec ? 2 : 0;
	number = (char*)malloc(ilen + prec + 2);
	ipart = fnum->ipart;
	fpart = fnum->fpart;
	zero = fnum->zero;
	i = 0;
	if (!ipart && !fpart)
		number[i++] = '0';
	else
		number[i++] = ipart ? *ipart++ : *fpart++;
	if (prec)
	{
		number[i++] = '.';
		while (ipart && *ipart && (i < prec + 1))
			number[i++] = *ipart++;
		while (ipart && zero-- && (i < prec + 1))
			number[i++] = '0';
		while (fpart && *fpart && (i < prec + 1))
			number[i++] = *fpart++;
		while (i < prec + 1)
			number[i++] = '0';
		ft_rounding(number, --i);
	}
	ft_set_exp(&number[i], fnum, spec);
	return (number);
}

void	ft_print_e(t_options *opt, t_buff *buffer, t_fnum *fnum)
{
	char	sign;
	char	*number;
	char	*temp;
	int		len;
	int		numlen;

	sign = ft_get_sign_f(opt, fnum->sign);
	numlen = ft_unumlen(fnum->zero + 1, 10);
	len = numlen < 2 ? 5 : numlen + 3;
	opt->width -= opt->prec ? opt->prec + len + 1 : len;
	if (!(opt->flags & (F_NULL + F_MINUS)))
		ft_print_width(buffer, &opt->width, ' ');
	if (sign)
		ft_in_buff(buffer, sign);
	if (!(opt->flags & F_MINUS))
		ft_print_width(buffer, &opt->width, (opt->flags & F_NULL) ? '0' : ' ');
	number = ft_get_enum(fnum, opt->prec, len, opt->spec);
	temp = number;
	while (*temp)
		ft_in_buff(buffer, *temp++);
	ft_strdel(&number);
	ft_print_width(buffer, &opt->width, ' ');
}