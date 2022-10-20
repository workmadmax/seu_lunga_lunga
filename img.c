/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:30:36 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/20 09:14:52 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	drawn_map(t_game *game)
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
				pos.x * 64, pos.y * 64);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
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

	if (!game->info_map.coll)
		exit_error("failed to load image");
	game->info_map.coll = mlx_xpm_file_to_image(game->mlx,
			"./imgs/rune.xpm", &wid, &hei);
	if (!game->info_map.wall)
		exit_error("failed to load image");
	game->info_map.wall = mlx_xpm_file_to_image(game->mlx,
			"./imgs/wall.xpm", &wid, &hei);
	if (!game->info_map.hero)
		exit_error("failed to load image");
	game->info_map.hero = mlx_xpm_file_to_image(game->mlx,
			"./imgs/chara.xpm", &wid, &hei);
	if (!game->info_map.grass)
		exit_error("failed to load image");
	game->info_map.grass = mlx_xpm_file_to_image(game->mlx,
			"./imgs/land.xpm", &wid, &hei);
	if (!game->info_map.door)
		exit_error("failed to load image");
	game->info_map.door = mlx_xpm_file_to_image(game->mlx,
			"./imgs/chest.xpm", &wid, &hei);
}
