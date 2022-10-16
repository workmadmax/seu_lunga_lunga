/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:17:15 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/16 20:12:36 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verify_obj(t_game *game)
{
	if (game->map[game->hero.y][game->hero.x] == 'C')
		game->hero.collect++;
	if (game->map[game->hero.y][game->hero.x] == 'E'
		&& game->hero.collect == game->gems)
		exit_game(game);
}

int	count_line(char *arg)
{
	char	*line;
	int		cnt;
	int		fd;

	cnt = 0;
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	cnt = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		++cnt;
	}
	free(line);
	close(fd);
	return (cnt);
}

void	set_map(t_game *game, char *arg)
{
	game->info_map.map_len = ft_strlen(game->map[0]);
	game->info_map.map_hei = count_line(arg);
	game->info_map.wall = "./imgs/sand.xpm";
	game->info_map.coll = "./imgs/coll.xpm";
	game->info_map.hero = "./imgs/play1.xpm";
	game->info_map.door = "./imgs/door.xpm";
	game->info_map.grass = "./imgs/grass.xpm";
}

void	set_game(t_game *game)
{
	game->steps = 1;
	game->gems = 0;
	game->hero.collect = 0;
	game->hero.total = 0;
	game->saida = 0;
	game->val_ext = 0;
	game->val_gems = 0;
}

void	check_ext(char *file, int argc)
{
	char *ext;

	if (argc < 2)
		printf("Error nos argumentos passados\n");
	ext = ft_strrchr(file, '.');
	if (!ext || ft_strncmp(ext, ".ber", 4) != 0)
		printf("Mapa precisa ser .ber\n");
}

void	set_hero(t_game *game, int x, int y, char elem)
{
	if (elem == 'P')
	{
		game->hero.total += 1;
		game->hero.x = x;
		game->hero.y = y;
	}
}
