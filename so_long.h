/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:32:47 by mdouglas          #+#    #+#             */
/*   Updated: 2022/09/21 22:56:43 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "./ft/libft.h"
# include "./ft/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>


typedef struct s_map
{
	int		mapLen;
	int		mapHei;
	int		exitX;
	int		exitY;
	char	*coll;
	char	*grass;
	char	*player;
	char	*wall;
	char	*exit;
}	t_map;

typedef struct s_objs
{
	int	x;
	int	y;
	int	total;
	int	collect;
}	t_obj;

typedef struct s_loc
{
	int	x;
	int	y;
}	t_loc;

typedef struct s_game
{
	int		imgWid;
	int		imgHei;
	int		bpp;
	int		lenght;
	int		gems;
	int		steps;
	int		endian;
	char	*argv;
	char	**map;
	char	*addr;
	void	*mlx;
	void	*win;
	void	*imgPtr;
	t_obj	player;
	t_map	infoMap;
}	t_game;


/* game */

int		keycode(int key, t_game *game);
void	init_mlx(t_game *game);
void	init_img(t_game *game);

/* map */

void	parse_map(t_game *game);
void	check_wall(t_game *game);
void	check_elem(t_game *game);

/* img */

void	create_map(t_game *game);
void	set_img(t_game *game, char c);


/* utils */

void	exit_error(char	*error_msg);
int		exit_game(t_game *game);
int		keycode(int key, t_game *game);
int		count_line(char *argv);
void	set_map(t_game *game);
void	check_ext(char *file, int argc);
void	set_hero(t_game *game, int x, int y, char elem);
void	verify_obj(t_game *game);
void	set_game(t_game *game);


/* moves */

int	move_a(t_game *game);
int	move_d(t_game *game);
int	move_w(t_game *game);
int	move_s(t_game *game);


#endif