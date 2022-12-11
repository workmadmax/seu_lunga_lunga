/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:48:25 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/11 17:53:48 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_a(t_game *game)
{
	if (game->hero.collect != game->gems
		&& game->map[game->hero.y][game->hero.x - 1] == 'E')
		return (0);
	if (game->map[game->hero.y][game->hero.x - 1] != '1')
	{
		game->map[game->hero.y][game->hero.x] = '0';
		game->hero.x--;
		verify_obj(game);
		game->map[game->hero.y][game->hero.x] = 'P';
		ft_printf("Steps : %d\n", game->steps++);
		return (1);
	}
	return (0);
}

int	move_d(t_game *game)
{
	if (game->hero.collect != game->gems
		&& game->map[game->hero.y][game->hero.x + 1] == 'E')
		return (0);
	if (game->map[game->hero.y][game->hero.x + 1] != '1')
	{
		game->map[game->hero.y][game->hero.x] = '0';
		game->hero.x++;
		verify_obj(game);
		game->map[game->hero.y][game->hero.x] = 'P';
		ft_printf("Steps : %d\n", game->steps++);
		return (1);
	}
	return (0);
}

int	move_s(t_game *game)
{
	if (game->hero.collect != game->gems
		&& game->map[game->hero.y + 1][game->hero.x] == 'E')
		return (0);
	if (game->map[game->hero.y + 1][game->hero.x] != '1')
	{
		game->map[game->hero.y][game->hero.x] = '0';
		game->hero.y++;
		verify_obj(game);
		game->map[game->hero.y][game->hero.x] = 'P';
		ft_printf("Steps : %d\n", game->steps++);
		return (1);
	}
	return (0);
}

int	move_w(t_game *game)
{
	if (game->hero.collect != game->gems
		&& game->map[game->hero.y -1][game->hero.x] == 'E')
		return (0);
	if (game->map[game->hero.y - 1][game->hero.x] != '1')
	{
		game->map[game->hero.y][game->hero.x] = '0';
		game->hero.y--;
		verify_obj(game);
		game->map[game->hero.y][game->hero.x] = 'P';
		ft_printf("Steps : %d\n", game->steps++);
		return (1);
	}
	return (0);
}
