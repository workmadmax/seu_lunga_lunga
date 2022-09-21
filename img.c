/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:30:36 by mdouglas          #+#    #+#             */
/*   Updated: 2022/09/21 23:00:18 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map(t_game *game)
{
	t_loc	pos;

	pos.y = 0;
	while (game->map[pos.y])
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x])
		{
			set_img(game, game->map[pos.y][pos.x]);
			mlx_put_image_to_window(game->mlx, game->win, game->imgPtr,
				pos.x * 30, pos.y * 30);
			pos.x++;
		}
		pos.y++;
	}
}

void set_img(t_game *game, char c)
{
    if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
    {
        if (c == '1')
            game->imgPtr = game->infoMap.wall;
        if (c == '0')
            game->imgPtr = game->infoMap.grass;
        if (c == 'P')
            game->imgPtr = game->infoMap.player;
        if (c == 'C')
            game->imgPtr = game->infoMap.coll;
        if (c == 'E')
            game->imgPtr = game->infoMap.exit;
		//game->imgPtr = mlx_xpm_file_to_image(game->mlx, render, &game->imgWid,
		//	&game->imgHei);
		//game->addr = mlx_get_data_addr(game->imgPtr, &game->bpp, &game->lenght, &game->endian);
	}
}

void	init_img(t_game *game)
{
	int	wid;
	int	hei;
	
	game->infoMap.coll = mlx_xpm_file_to_image(game->mlx, "./imgs/coll.xpm", &wid, &hei);
	game->infoMap.wall = mlx_xpm_file_to_image(game->mlx, "./imgs/sand.xpm", &wid, &hei);
	game->infoMap.player = mlx_xpm_file_to_image(game->mlx, "./imgs/play1.xpm", &wid, &hei);
	game->infoMap.grass = mlx_xpm_file_to_image(game->mlx, "./imgs/grass.xpm", &wid, &hei);
	game->infoMap.exit = mlx_xpm_file_to_image(game->mlx, "./imgs/exit.xpm", &wid, &hei);
}