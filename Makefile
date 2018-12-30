# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/28 19:13:21 by afalmer-          #+#    #+#              #
#    Updated: 2018/12/30 17:15:28 by afalmer-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

OBJ = ft_printf.o

HEADER = ft_printf.h

LIB = libft/libft.a

HEADER_DIR = libft/includes/

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@ -I $(HEADER_DIR)

$(LIB):
	make -C libft/

ex: $(NAME)
	gcc main.c $(NAME) -I $(HEADER_DIR) -L libft/ -lft

clean:
	rm -rf $(OBJ)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/
