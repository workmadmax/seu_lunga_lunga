# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 20:23:22 by mdouglas          #+#    #+#              #
#    Updated: 2022/12/11 17:58:20 by mdouglas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME						=	so_long
CC							= 	gcc
RM							=	rm -rf

OBJS						=	$(SRCS:%.c=%.o)
SRCS						=	exit_game.c game.c img.c \
								 map.c moves.c utils.c valid_path.c \

LIBPATH						=	./ft
PRINTFPATH					=	./ft_printf
MLXPATHS					=	./mlx

LIBFT						=	libft.a
PRINTF						=	$(PRINFTPATH)/libftprintf.a
MLX							=	libmlx_Linux

CFLAGS						=	-Wall -Wextra -Werror -g
MLXFLAGS					=	-fPIE -Imlx_linux -lXext -lX11 -lm


.c.o:
								$(CC) -c $< -o $(<:.c=.o)
							
all:						$(NAME)

$(NAME):					$(OBJS)
								$(MAKE) -C $(LIBPATH)
								$(MAKE) -C $(PRINFTPATH)
								$(CC) $(CFLAGS) $(OBJS) $(LIB) $(PRINTF) $(MLXFLAGS) -o $(NAME)
clean:
								$(MAKE) -C $(LIBPATH) clean
								$(MAKE) -C $(MLXPATHS) clean
								$(MAKE) -C $(PRINTFPATH) clean
								$(RM) $(OBJS)

fclean:						clean
								$(MAKE) -C $(LIBPATH) fclean
								$(MAKE) -C $(PRINTFPATH) fclean
								$(RM) $(NAME)


re:							fclean all

run:
								./so_long map.ber

val:
								valgrind -s ./so_long map.ber

.PHONY : 						all fclean clean re run val