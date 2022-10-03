/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:30:36 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/03 16:15:42 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	drawn_map(t_game *game)
{
	t_loc	pos;

	pos.y = 0;
	while (game->map[pos.y])
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x])
		{
			set_img(game, game->map[pos.y][pos.x]);
			mlx_put_image_to_window(game->mlx, game->win, game->img_ptr,
				pos.x * 30, pos.y * 30);
			pos.x++;
		}
		pos.y++;
	}
}

void	set_img(t_game *game, char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
	{
		if (c == '1')
			game->img_ptr = game->info_map.wall;
		if (c == '0')
			game->img_ptr = game->info_map.grass;
		if (c == 'P')
			game->img_ptr = game->info_map.hero;
		if (c == 'C')
			game->img_ptr = game->info_map.coll;
		if (c == 'E')
			game->img_ptr = game->info_map.door;
	}
}

void	init_img(t_game *game)
{
	int	wid;
	int	hei;

	game->info_map.coll = mlx_xpm_file_to_image(game->mlx,
			"./img/coll.xpm", &wid, &hei);
	game->info_map.wall = mlx_xpm_file_to_image(game->mlx,
			"./img/sand.xpm", &wid, &hei);
	game->info_map.hero = mlx_xpm_file_to_image(game->mlx,
			"./img/play1.xpm", &wid, &hei);
	game->info_map.grass = mlx_xpm_file_to_image(game->mlx,
			"./img/grass.xpm", &wid, &hei);
	game->info_map.door = mlx_xpm_file_to_image(game->mlx,
			"./img/exit.xpm", &wid, &hei);
}
