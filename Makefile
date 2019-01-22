# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/28 19:13:21 by afalmer-          #+#    #+#              #
#    Updated: 2019/01/22 12:59:18 by afalmer-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

OBJ =	obj/ft_printf.o obj/ft_putchar.o obj/ft_atoi.o obj/ft_set_options.o \
		obj/ft_parse_nums.o obj/ft_num_base.o obj/ft_print_di.o \
		obj/ft_print_c.o obj/ft_print_s.o \
		obj/ft_print_options.o obj/ft_print_u.o obj/ft_print_o.o \
		obj/ft_print_x.o obj/ft_print_f.o

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

obj/%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@ -g

ex: $(NAME)
	gcc main.c $(NAME) -g

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
