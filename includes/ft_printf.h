/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandr <aleksandr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:32:10 by aleksandr         #+#    #+#             */
/*   Updated: 2019/02/11 16:45:37 by aleksandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>

# define MAX_LEN 512

# define F_MINUS 1
# define F_PLUS 2
# define F_SP 4
# define F_SHARP 8
# define F_NULL 16
# define F_LOWER 32

# define LEN_HH 1
# define LEN_H 2
# define LEN_L 4
# define LEN_LL 8
# define LEN_J 16
# define LEN_Z 32
# define LEN_TIME 64

# define MAX_DEC 20
# define MAX_BIN 65

typedef struct	s_options
{
	int			flags;
	int			width;
	int			prec;
	int			length;
	int			base;
	char		spec;
}				t_options;

typedef struct	s_buff
{
	char		buff[MAX_LEN];
	int			i;
	int			len;
}				t_buff;

int				ft_printf(const char *format, ...);

void			ft_set_buff(t_buff *buffer);
void			ft_out_buff(t_buff *buffer);
void			ft_in_buff(t_buff *buffer, unsigned char c);

int				ft_atoi(const char *str);
int				ft_unumlen(unsigned long long num, int base);
int				ft_itoa_base(unsigned long long num, char *str, int base, \
					char lower);

void			ft_set_options(t_options *opt, char **format, va_list ap);
void			ft_set_flags(const char **format, t_options *opt);
void			ft_set_prec(const char **format, t_options *opt, va_list ap);
void			ft_set_length(const char **format, t_options *opt);
int				ft_set_spec(char c, t_options *opt);

void			ft_handle_spec(t_options *opt, t_buff *buffer, va_list ap);
int				ft_handle_num(t_options *opt, t_buff *buffer, va_list ap);
int				ft_handle_other(t_options *opt, t_buff *buffer, va_list ap);

void			ft_parse_num(t_options *opt, t_buff *buffer, long long num);
void			ft_parse_unum(t_options *opt, t_buff *buffer, \
					unsigned long long unum, \
					int (*ft_print)(t_options*, t_buff*, unsigned long long));

void			ft_print_di(t_options *opt, t_buff *buffer, long long num);
void			ft_print_uoxb(t_options *opt, t_buff *buffer, \
					unsigned long long unum);
void			ft_print_c(t_options *opt, t_buff *buffer, unsigned char c);


void			ft_print_width(t_buff *buffer, int *width, char c);
void			ft_print_prec(t_buff *buffer, int prec, int len);
void			ft_print_sharp(t_buff *buffer, t_options *opt);

#endif
