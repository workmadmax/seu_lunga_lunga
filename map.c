/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:34:13 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/19 13:54:31 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_game *game, char *arg)
{
	int		fd;
	int		line;
	char	*temps;
	t_loc	pos;

	line = count_line(arg);
	game->map = malloc(sizeof(char **) * (line + 1));
	if (!game->map)
		exit_error("Faleid to allocte memory");
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		exit_error("Error file map not exist!");
	pos.x = 0;
	pos.y = 0;
	while (pos.x <= line)
	{
		temps = get_next_line(fd);
		game->map[pos.x++] = ft_strtrim(temps, "\n");
		free(temps);
	}
	close(fd);
	set_map(game, arg);
}

void	check_wall(t_game *game)
{
	t_loc	pos;

	pos.x = 0;
	while (game->map[pos.x] != 0)
	{
		pos.y = 0;
		if ((int)ft_strlen(game->map[pos.x]) != game->info_map.map_len)
			exit_error("The map must rectangular!");
		if (pos.x == 0 || pos.x == game->info_map.map_hei - 1)
		{
			while (game->map[pos.x][pos.y] != '\0')
			{
				if (game->map[pos.x][pos.y] != '1')
					exit_error("Th map must be surrounded by walls!");
				pos.y++;
			}
		}
		if (game->map[pos.x][0] != '1' ||
			game->map[pos.x][game->info_map.map_len - 1] != '1')
			exit_error("The map must be surrounded by walls2!");
		pos.x++;
	}
}

void	check_elem(t_game *game)
{
	t_loc		pos;
	
	pos.x = 0;
	game->gems = 0;
	while (game->map[pos.x])
	{
		pos.y = 0;
		while (game->map[pos.x][pos.y])
		{
			if (game->map[pos.x][pos.y] == 'P')
				set_hero(game, pos.y, pos.x, 'P');
			else if (game->map[pos.x][pos.y] == 'C')
				game->gems++;
			else if (game->map[pos.x][pos.y] == 'E')
				game->exit++;
			pos.y++;
		}
		pos.x++;
	}
	if (game->hero.total != 1 || game->exit != 1 || game->gems < 1)
		exit_error("Elements not good");
	game->tmp_map = ft_dup_array(game->map);
	if (!game->tmp_map)
		exit_error("sem mapa temporario");
	flood_fill(game, game->hero.x, game->hero.y);
	valid_path(game);
}
