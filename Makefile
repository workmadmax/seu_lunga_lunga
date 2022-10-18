# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 20:23:22 by mdouglas          #+#    #+#              #
#    Updated: 2022/10/18 13:52:09 by mdouglas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc

OBJS = $(SRCS:.c=.o)
SRCS = exit_game.c game.c img.c map.c moves.c utils.c valid_path.c

MFLAGS = ./ft/libft.a ./mlx/libmlx_Linux.a
AFLAGS = -Wall -Wextra -Werror -g
FLAGS =  -fPIE -Imlx_linux -lXext -lX11 -lm

RM = rm -rf

all: $(MFLAGS) $(NAME)

$(MFLAGS):
		make -C ./ft
		make -C ./mlx

$(NAME): $(OBJS)
		$(CC) $(AFLAGS) $(OBJS) $(MFLAGS) $(FLAGS) -o $(NAME)

fclean: clean
		make fclean -C ./ft
		$(RM) $(NAME)

clean:
	make clean -C ./ft
	make clean -C ./mlx
	$(RM) *.o

re: fclean all

.PHONY : all fclean clean re