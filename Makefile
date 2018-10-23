# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 08:29:04 by vmartynu          #+#    #+#              #
#    Updated: 2017/12/11 08:52:33 by vmartynu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC =./src/main.c ./src/ft_alpha.c ./src/ft_bzero.c ./src/ft_check_tetra.c \
./src/ft_fillit.c ./src/ft_free.c ./src/ft_push_tetra.c \
./src/ft_isalpha.c ./src/ft_map.c ./src/ft_memalloc.c ./src/ft_memset.c \
./src/ft_min_size.c ./src/ft_print_map.c ./src/ft_putchar.c ./src/ft_putstr.c \
./src/ft_remap.c ./src/ft_str_split_fil.c ./src/ft_validat.c ./src/ft_who_first.c  

OBJ = $(SRC: .c = .o)
H = ./inc
GCC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(GCC) -c $(SRC) -I$(H)
	$(GCC) -o $(NAME) $(OBJ) -I$(H)
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
