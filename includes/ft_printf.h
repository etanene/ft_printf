/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:32:10 by aleksandr         #+#    #+#             */
/*   Updated: 2019/02/13 22:07:04 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <inttypes.h>
# include <stdlib.h>

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

# define MAX_POWER 15
# define MAX_NUM 100000000000000UL

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

union					u_f
{
	double				f;
	long double			lf;
	unsigned long long	ll;
};

typedef struct			s_fnum
{
	union u_f			num;
	char				sign;
	int					exp;
	unsigned long long	mantissa;
	unsigned long long	ipart;
	unsigned long long	fpart;
}						t_fnum;

typedef struct			s_bigint
{
	unsigned long long	num[1024];
	int					size;
}						t_bigint;


int				ft_printf(const char *format, ...);

void			ft_set_buff(t_buff *buffer);
void			ft_out_buff(t_buff *buffer);
void			ft_in_buff(t_buff *buffer, unsigned char c);

int				ft_atoi(const char *str);
int				ft_unumlen(unsigned long long num, int base);
int				ft_itoa_base(unsigned long long num, char *str, int base, \
					char lower);
int				ft_strnlen(char *str, int n);
int				ft_wstrnlen(wchar_t *str, int n);
int				ft_rstrnlen(char *str, int n);

void			ft_set_options(t_options *opt, const char **format, va_list ap);
void			ft_set_flags(const char **format, t_options *opt);
void			ft_set_width(const char **format, t_options *opt, va_list ap);
void			ft_set_prec(const char **format, t_options *opt, va_list ap);
void			ft_set_length(const char **format, t_options *opt);
int				ft_set_spec(char c, t_options *opt);

void			ft_handle_spec(t_options *opt, t_buff *buffer, va_list ap);
int				ft_handle_num(t_options *opt, t_buff *buffer, va_list ap);
int				ft_handle_other(t_options *opt, t_buff *buffer, va_list ap);

void			ft_parse_num(t_options *opt, t_buff *buffer, long long num);
void			ft_parse_unum(t_options *opt, t_buff *buffer, \
					unsigned long long unum);
void			ft_parse_fnum(t_options *opt, t_buff *buffer, double num);

void			ft_print_di(t_options *opt, t_buff *buffer, long long num);
void			ft_print_uoxb(t_options *opt, t_buff *buffer, \
					unsigned long long unum);
void			ft_print_c(t_options *opt, t_buff *buffer, unsigned char c);
void			ft_print_lc(t_options *opt, t_buff *buffer, wchar_t c);
void			ft_print_s(t_options *opt, t_buff *buffer, char *str);
void			ft_print_ls(t_options *opt, t_buff *buffer, wchar_t *str);
void			ft_print_p(t_options *opt, t_buff *buffer, void *pointer);
void			ft_print_r(t_options *opt, t_buff *buffer, char *str);
void			ft_print_rand(t_options *opt, t_buff *buffer);

char			*ft_get_ipart(t_fnum *fnum, int shift);

t_bigint		ft_get_bigint(unsigned long long num, unsigned long long shift);
void			ft_reset_bigint(t_bigint *bigint);
void			ft_set_bigint(t_bigint *bigint, int power);

void			ft_bigint_sum_bigint(t_bigint *bigint1, t_bigint *bigint2);
void			ft_bigint_multi_int(t_bigint *bigint, int num);

void			ft_print_width(t_buff *buffer, int *width, char c);
void			ft_print_prec(t_buff *buffer, int prec, int len);
void			ft_print_sharp(t_buff *buffer, t_options *opt);

#endif
