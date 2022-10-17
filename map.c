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
		exit_error("Error map not exist!");
	pos.y = 0;
	pos.x = 0;
	while (pos.y <= line)
	{
		temps = get_next_line(fd);
		game->map[pos.y++] = ft_strtrim(temps, "\n");
		free(temps);
	}
	close(fd);
	set_map(game, arg);
}

void	check_wall(t_game *game)
{
	t_loc	pos;

	pos.y = 0;
	while (game->map[pos.y] != 0)
	{
		pos.x = 0;
		if ((int)ft_strlen(game->map[pos.y]) != game->info_map.map_len)
			exit_error("The map must rectangular!");
		if (pos.y == 0 || pos.y == game->info_map.map_hei - 1)
		{
			while (game->map[pos.y][pos.x] != '\0')
			{
				if (game->map[pos.y][pos.x] != '1')
					exit_error("Th map must be surrounded by walls!");
				pos.x++;
			}
		}
		if (game->map[pos.y][0] != '1' ||
			game->map[pos.y][game->info_map.map_len - 1] != '1')
			exit_error("The map must be surrounded by walls2!");
		pos.y++;
	}
}

void	check_elem(t_game *game)
{
	t_loc		pos;

	pos.y = 0;
	game->gems = 0;
	while (game->map[pos.y])
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x])
		{
			if (game->map[pos.y][pos.x] == 'P')
				set_hero(game, pos.x, pos.y, 'P');
			else if (game->map[pos.y][pos.x] == 'C')
				game->gems++;
			else if (game->map[pos.y][pos.x] == 'E')
				game->saida++;
			pos.x++;
		}
		pos.y++;
	}
	if (game->hero.total != 1 || game->saida != 1 || game->gems < 1)
		exit_error("Elements not good");
	game->tmp_map = ft_dup_array(game->map);
	flood_fill(game, game->tmp_map, game->hero.x, game->hero.y);
	printf("%d\n", game->hero.x);
	printf("%d\n", game->hero.y);
	printf("%d\n", game->gems);
	printf("%d\n", game->val_gems);
	printf("%d\n", game->val_ext);
	printf("%d\n", game->saida);
	while (*game->tmp_map)
	{
		printf("%s\n", *game->tmp_map);
		game->tmp_map++;
	}
}
