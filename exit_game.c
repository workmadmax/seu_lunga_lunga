/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:49:49 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/16 20:10:18 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[++i])
		free(game->map[i]);
	free(game->map);
}

void	free_strmap(char **map)
{
	int	idx;

	idx = -1;
	while (map[++idx])
		free(map[idx]);
	free(map);
}

void	exit_error(char	*error_msg)
{
	printf("Error\n%s\n Closing Program\n", error_msg);
	exit (0);
}

int	exit_game(t_game *game)
{
	printf("Thanks for play\n");
	free_map(game);
	mlx_destroy_image(game->mlx, game->info_map.wall);
	mlx_destroy_image(game->mlx, game->info_map.coll);
	mlx_destroy_image(game->mlx, game->info_map.door);
	mlx_destroy_image(game->mlx, game->info_map.grass);
	mlx_destroy_image(game->mlx, game->info_map.hero);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (0);
}

int	check_collects(char **map, char qavats)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	cnt = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] == qavats)
				cnt++;
			j++;
		}
		i++;
	}
	return (cnt);
}
