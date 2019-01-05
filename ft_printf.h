/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:45:14 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/05 19:13:06 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define UNSIGN 1
# define SIGN -1

# define LEN_HH 1
# define LEN_H 2
# define LEN_L 4
# define LEN_LL 8

# define FLAG_MINUS 1
# define FLAG_PLUS 2
# define FLAG_SP 4
# define FLAG_SHARP 8
# define FLAG_NULL 16

typedef struct	s_options
{
	char		flags[5];
	int			width;
	int			precision;
	int			length;
	char		spec;
}				t_options;

int		ft_printf(const char *format, ...);

#endif
