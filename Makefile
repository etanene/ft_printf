# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/10 16:37:58 by aleksandr         #+#    #+#              #
#    Updated: 2019/02/14 19:41:52 by afalmer-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCDIR = src/
SRC = ft_printf.c ft_utils.c ft_buff_manage.c ft_set_options.c ft_parse_nums.c \
		ft_print_options.c ft_print_diuoxb.c ft_print_cs.c ft_print_prk.c \
		ft_parse_fnum.c ft_bigint.c ft_bigint_operations.c

OBJDIR = obj/
OBJ = $(addprefix $(OBJDIR), $(SRC:%.c=%.o))

INCLUDES = includes/
HEADER = $(addprefix $(INCLUDES), ft_printf.h)

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@ -I $(INCLUDES) -g

$(OBJDIR):
	mkdir obj/

main.o: main.c
	gcc -c $< -o $@ -I $(INCLUDES) -g

ex: main.o $(NAME)
	gcc $(FLAGS) $< $(NAME)

clean:
	rm -rf $(OBJ) main.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
