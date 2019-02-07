/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:45:14 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/07 20:22:12 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <float.h>
# include <stdlib.h>



# include <stdio.h>



# define UNSIGN 1
# define SIGN -1

# define LEN_HH 1
# define LEN_H 2
# define LEN_L 4
# define LEN_LL 8
# define LEN_J 16
# define LEN_Z 32
# define LEN_TIME 64

# define F_MINUS 0
# define F_PLUS 1
# define F_SP 2
# define F_SHARP 3
# define F_NULL 4
# define F_WIDTH_STAR 5
# define F_PREC_STAR 6

#define COUNT_BITS 64
#define COUNT_BITS_LF 80
#define MAX_POWER 15
#define MAX_NUM 100000000000000UL
#define MAX_INDEX 1024

# define MAX(a, b) (a > b ? a : b)

typedef struct			s_options
{
	char				flags[7];
	int					width;
	int					prec;
	int					length;
	char				spec;
}						t_options;

typedef union			u_fnum
{
	double				f;
	long double			lf;
	unsigned long long	ll;
}						t_fnum;

typedef struct			s_fnum_div
{
	t_fnum				fnum;
	char				sign;
	int					exponent;
	unsigned long long	mantissa;
	unsigned long long	ipart;
	unsigned long long	fpart;
}						t_fnum_div;

typedef struct			s_bigint
{
	unsigned long long	num[MAX_INDEX];
	int					size;
}						t_bigint;

int					ft_printf(const char *format, ...);
t_options			ft_set_options(const char **format);
void				ft_set_length(const char **format, t_options *options);
void				ft_set_prec(const char **format, t_options *options);
void				ft_set_width(const char **format, t_options *options);
void				ft_set_flags(const char **format, t_options *options);
int					ft_set_spec(char c, t_options *options);
int					ft_atoi(const char *str);
int					ft_unumlen(unsigned long long int num, int base);
int					ft_handle_spec(t_options options, va_list ap);
int					ft_parse_num(t_options options, long long int num);
int					ft_parse_unum(t_options options, long long num, int (*ft_print)(t_options, unsigned long long));
int					ft_print_di(t_options options, long long int num);
int					ft_print_uoxX(t_options options, unsigned long long int unum);
int					ft_sum_flags(char *flags);
void				ft_printnum(unsigned long long int num, unsigned long long int base);
void				ft_printnumX(unsigned long long int num, unsigned long long int base);
void				ft_putchar(char c);
int					ft_print_c(t_options options, int c);
int					ft_print_s(t_options opt, int *str, int (*ft_len)(int*, int), void (*ft_print)(int*, int));
void				ft_print_unicode(int num, int bytes);
int					ft_convert_utf32_utf8(int utf32, char *p);
void				ft_reset_options(t_options *options, int *len);
int					ft_print_width(int width, int c);
int					ft_print_prec(int prec);
int					ft_print_u(t_options opt, unsigned long long unum);
int					ft_print_o(t_options opt, unsigned long long unum);
int					ft_print_x(t_options opt, unsigned long long unum);
int					ft_print_b(t_options opt, unsigned long long unum);
int					ft_strlen_unicode(int *str, int prec);
int					ft_strlen_s(int *str, int prec);
void				ft_puts(int *str, int prec);
void				ft_puts_unicode(int *str, int prec);
int					ft_parse_lf(t_options opt, long double num);
int					ft_parse_fnum(t_options options, long double num);
void				ft_print_bigint(t_bigint *bigint);
void				ft_bigint_sum_bigint(t_bigint *bigint1, t_bigint *bigint2);
void				ft_bigint_multi_int(t_bigint *bigint, int num);
int					ft_checkbit(long long n, int pos);
void				ft_printbits(long long n, int count);
unsigned long		ft_reversebits(unsigned long num);
int					ft_check_endian(void);
int					ft_swap_bytes(int n);
unsigned long long	ft_pow(int num, int pow);
int					ft_numlen_bigint(t_bigint *bigint);
int					ft_print_ipart_fpart(t_options opt, t_fnum_div fnum_div, int (*ft_print_prec)(int, t_fnum_div));
t_bigint			ft_get_bigint(unsigned long long num, unsigned long long shift);
void				ft_bigint_div_int(t_bigint *bigint, int num);
long long			ft_bigint_compare(t_bigint *bigint1, t_bigint *bigint2);
void				ft_bigint_minus_bigint(t_bigint *bigint1, t_bigint *bigint2);
int					ft_print_ipart_bigint(t_options opt, t_fnum_div fnum_div, int shift);
int					ft_print_p(t_options opt, void	*pointer);
int					ft_parse_f(t_options opt, double num);
char				*ft_itoa(unsigned long long n);
int					ft_print_k(t_options opt, unsigned long long unum);
int					ft_print_r(t_options opt, char *str);
int					ft_print_perc(t_options opt, char c);
int					ft_print_rand(t_options opt);

#endif
