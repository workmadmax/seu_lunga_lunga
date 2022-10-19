/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:17:15 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/19 13:57:00 by mdouglas         ###   ########.fr       */
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
	game->info_map.wall = "./imgs/wall.xpm";
	game->info_map.coll = "./imgs/rune.xpm";
	game->info_map.hero = "./imgs/chara.xpm";
	game->info_map.door = "./imgs/chest.xpm";
	game->info_map.grass = "./imgs/land.xpm";
}

void	set_game(t_game *game)
{
	game->steps = 1;
	game->gems = 0;
	game->hero.collect = 0;
	game->hero.total = 0;
	game->exit = 0;
	game->val_ext = 0;
	game->val_gems = 0;
}

void	check_ext(char *file, int argc)
{
	char *ext;

	if (argc < 2)
		ft_printf("Error nos argumentos passados\n");
	ext = ft_strrchr(file, '.');
	if (!ext || ft_strncmp(ext, ".ber", 4) != 0)
		ft_printf("Mapa precisa ser .ber\n");
}

