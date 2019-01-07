/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:45:14 by afalmer-          #+#    #+#             */
/*   Updated: 2019/01/07 16:14:18 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define UNSIGN 1
# define SIGN -1

# define LEN_HH 1
# define LEN_H 2
# define LEN_L 4
# define LEN_LL 8

# define F_MINUS 0
# define F_PLUS 1
# define F_SP 2
# define F_SHARP 3
# define F_NULL 4

# define MAX(a, b) (a > b ? a : b)

typedef struct	s_options
{
	char		flags[5];
	int			width;
	int			prec;
	int			length;
	char		spec;
}				t_options;

int				ft_printf(const char *format, ...);
t_options		ft_set_options(const char **format);
void			ft_set_length(const char **format, t_options *options);
void			ft_set_prec(const char **format, t_options *options);
void			ft_set_width(const char **format, t_options *options);
void			ft_set_flags(const char **format, t_options *options);
int				ft_set_spec(char c, t_options *options);
int				ft_atoi(const char *str);
int				ft_unumlen(unsigned long long int num, char spec);
int				ft_handle_spec(t_options options, va_list ap);
int				ft_parse_num(t_options options, long long int num, int type);
int				ft_parse_unum(t_options options, long long int num, int type);
int				ft_print_diuoxX(t_options options, long long int num, int type);
int				ft_sum_flags(char *flags);
void			ft_printnum(unsigned long long int num, char spec);
void			ft_putchar(char c);

#endif
