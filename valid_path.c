/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:29:09 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/19 13:45:18 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, int x, int y)
{
	char	*p;
	
	p = &game->tmp_map[y][x];
	if (*p == 'E')
		game->val_ext = 1;
	if (*p != 'E' && *p != '1')
	{
		if (*p == 'C')
			game->val_gems++;
		*p = '.';
		if (game->tmp_map[y][x + 1] != '1' && game->tmp_map[y][x + 1] != '.')
			flood_fill(game, x + 1, y);
		if (game->tmp_map[y][x - 1] != '1' && game->tmp_map[y][x - 1] != '.')
			flood_fill(game, x - 1, y);
		if (game->tmp_map[y + 1][x] != '1' && game->tmp_map[y + 1][x] != '.')
			flood_fill(game, x, y + 1);
		if (game->tmp_map[y - 1][x] != '1' && game->tmp_map[y - 1][x] != '.')
			flood_fill(game, x, y - 1);
	}
}

void    valid_path(t_game *game)
{
	int	idx;

	idx = 0;
	while (game->tmp_map[idx])
	{
		free(game->tmp_map[idx]);
		idx++;
	}
	free(game->tmp_map);
   	if (game->val_gems != game->gems || game->val_ext != game->exit)
		exit_error("sem caminho valido");
}

static int	ft_array_len(char **array)
{
	int	len;

	len = -1;
	if (array == NULL || *array == NULL)
		return (len);
	while (array[++len])
		;
	return (len);
}

char	**ft_dup_array(char **array)
{
	char	**cpy;
	int		len;

	if (array == NULL || *array == NULL)
		return (NULL);
	len = ft_array_len(array) + 1;
	cpy = (char **)malloc(len * sizeof(char *));
	cpy[--len] = NULL;
	while (len--)
		cpy[len] = ft_strdup(array[len]);
	return (cpy);
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