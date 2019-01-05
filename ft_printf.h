/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:45:14 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/04 19:10:15 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define UNSIGN 1
# define SIGN -1
# define HH 2
# define H 3
# define L 4
# define LL 5

typedef struct	s_options
{
	char		flags;
	int			width;
	int			precision;
	int			length;
	char		spec;
}				t_options;

int		ft_printf(const char *format, ...);

#endif
