# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 20:23:22 by mdouglas          #+#    #+#              #
#    Updated: 2022/10/19 14:05:10 by mdouglas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc

OBJS = $(SRCS:.c=.o)
SRCS = exit_game.c game.c img.c map.c moves.c utils.c valid_path.c

MFLAGS = ./ft/libft.a ./mlx/libmlx_Linux.a ./ft_printf/libftprintf.a
AFLAGS = -Wall -Wextra -Werror -g
FLAGS =  -fPIE -Imlx_linux -lXext -lX11 -lm

RM = rm -rf

all: $(MFLAGS) $(NAME)

$(MFLAGS):
		make -C ./ft
		make -C ./mlx
		make -C ./ft_printf

$(NAME): $(OBJS)
		$(CC) $(AFLAGS) $(OBJS) $(MFLAGS) $(FLAGS) -o $(NAME)

fclean: clean
		make fclean -C ./ft
		make fclean -C ./ft_printf
		$(RM) $(NAME)

clean:
	make clean -C ./ft
	make clean -C ./mlx
	make clean -C ./ft_printf
	$(RM) $(OBJS)

re: fclean all

run:
	./so_long map.ber

val:
	valgrind -s ./so_long map.ber

.PHONY : all fclean clean re run