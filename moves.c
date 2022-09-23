/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:48:25 by mdouglas          #+#    #+#             */
/*   Updated: 2022/09/22 14:57:32 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_a(t_game *game)
{
	if (game->player.collect != game->gems
		&& game->map[game->player.y][game->player.x - 1] == 'E')
			return (0);
	if (game->map[game->player.y][game->player.x - 1] != '1')
	{
		game->map[game->player.y][game->player.x] = '0';
		game->player.x--;
		verify_obj(game);
		game->map[game->player.y][game->player.x] = 'P';
		printf("Steps : %d\n", game->steps++);
		return (1);
	}
	return (0);
}

int	move_d(t_game *game)
{
	if (game->player.collect != game->gems
		&& game->map[game->player.y][game->player.x + 1] == 'E')
		return (0);
	if (game->map[game->player.y][game->player.x + 1] != '1')
	{
		game->map[game->player.y][game->player.x] = '0';
		game->player.x++;
		verify_obj(game);
		game->map[game->player.y][game->player.x] = 'P';
		printf("Steps : %d\n", game->steps++);
		return (1);
	}
	return (0);
}

int move_s(t_game *game)
{
	if (game->player.collect != game->gems
		&& game->map[game->player.y + 1][game->player.x] == 'E')
			return (0);
	if (game->map[game->player.y + 1][game->player.x] != '1')
	{
		game->map[game->player.y][game->player.x] = '0';
		game->player.y++;
		verify_obj(game);
		game->map[game->player.y][game->player.x] = 'P';
		printf("Steps : %d\n", game->steps++);
		return (1);
	}
	return (0);
}

int move_w(t_game *game)
{
	if (game->player.collect != game->gems
		&& game->map[game->player.y -1][game->player.x] == 'E')
		return (0);
	if (game->map[game->player.y - 1][game->player.x] != '1')
	{
		game->map[game->player.y][game->player.x] = '0';
		game->player.y--;
		verify_obj(game);
		game->map[game->player.y][game->player.x] = 'P';
		printf("Steps : %d\n", game->steps++);
		return (1);
	}
	return (0);
}