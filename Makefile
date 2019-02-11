# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleksandr <aleksandr@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/10 16:37:58 by aleksandr         #+#    #+#              #
#    Updated: 2019/02/11 21:21:11 by aleksandr        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCDIR = src/
SRC = ft_printf.c ft_utils.c ft_buff_manage.c ft_set_options.c ft_parse_nums.c \
		ft_print_options.c ft_print_diuoxb.c ft_print_cs.c ft_print_prk.c

OBJDIR := obj/
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

INCLUDES = includes/
HEADER = $(addprefix $(INCLUDES), ft_printf.h)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@ -I $(INCLUDES)

main.o: main.c
	gcc $(FLAGS) -c $< -o $@

ex: main.c $(NAME)
	gcc $(FLAGS) $< $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
