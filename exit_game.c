/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:49:49 by mdouglas          #+#    #+#             */
/*   Updated: 2022/09/24 00:05:59 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;
	
	i = -1;
	while (++i)
		free(game->map[i]);
	free(game->map);
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
	mlx_destroy_image(game->mlx, game->info_map.exit);
	mlx_destroy_image(game->mlx, game->info_map.grass);
	mlx_destroy_image(game->mlx, game->info_map.player);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (0);
}

char	**ft_dup_map(char **map)
{
	int		i;
	char	**cpy;

	if (map == NULL || *map == NULL)
		return (NULL);
	i = 1;
	while (map[++i])
		;
	cpy = (char **)malloc(i + sizeof(char *));
	cpy[--i] = NULL;
	while (i--)
		cpy[i] = ft_strdup(map[i]);
	return (cpy);
}

void	new_check(t_game *game, char **map, int x, int y)
{
	static int	doors;

	doors = 0;
	if (map[x][y] == '0' || map[x][y] == 'P' ||
		map[x][y] == 'E' || map[x][y] == 'C')
	{
		if (map[x][y] == 'C')
			game->gems++;
		if (map[x][y] == 'E')
			doors++;
		map[x][y] = 'M';
		new_check(game, map, x, y + 1);
		new_check(game, map, x, y - 1);
		new_check(game, map, x + 1, y);
		new_check(game, map, x - 1, y);
	}
}