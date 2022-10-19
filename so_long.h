/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:32:47 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/19 13:45:46 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./ft/libft.h"
# include "./ft/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define FOCUS 9

typedef struct s_map
{
	int		map_len;
	int		map_hei;
	char	*coll;
	char	*grass;
	char	*hero;
	char	*wall;
	char	*door;
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
	int		img_wid;
	int		img_hei;
	int		gems;
	int		steps;
	int		exit;
	int		val_gems;
	int		val_ext;
	char	*map_str;
	char	**map;
	char	**tmp_map;
	void	*mlx;
	void	*win;
	void	*img_ptr;
	t_obj	hero;
	t_map	info_map;
}	t_game;

/* game */

int		keycode(int key, t_game *game);
void	init_mlx(t_game *game);
void	set_game(t_game *game);

/* exit */

int		exit_game(t_game *game);
void	free_map(t_game *game);
void	exit_error(char	*error_msg);
void	new_check(t_game *game, char **map, int x, int y);
char	**ft_dup_map(char **map);

/* map */

void	parse_map(t_game *game, char *arg);
void	check_wall(t_game *game);
void	check_elem(t_game *game);

/* img */

void	drawn_map(t_game *game);
void	init_img(t_game *game);
void	set_img(t_game *game, char c);

/* utils */

int		keycode(int key, t_game *game);
int		count_line(char *argc);
void	set_map(t_game *game, char *arg);
void	check_ext(char *file, int argc);
void	set_hero(t_game *game, int x, int y, char elem);
void	verify_obj(t_game *game);

/* moves */

int	move_a(t_game *game);
int	move_d(t_game *game);
int	move_w(t_game *game);
int	move_s(t_game *game);

/* valid path */

char	**ft_dup_array(char	**array);
void	flood_fill(t_game *game, int x, int y);
void    valid_path(t_game *game);




#endif