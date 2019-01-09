# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/28 19:13:21 by afalmer-          #+#    #+#              #
#    Updated: 2019/01/09 17:23:10 by afalmer-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

OBJ =	ft_printf.o ft_putchar.o ft_atoi.o ft_set_options.o ft_parse_nums.o \
		ft_num_base.o ft_print_di.o ft_print_uoxX.o

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@ -g

ex: $(NAME)
	gcc main.c $(NAME) -g

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
