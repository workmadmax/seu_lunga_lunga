/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:29:09 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/17 16:08:07 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, char **map, int x, int y)
{
	if (map[x][y] == '0' || map[x][y] == 'P' || map[x][y] == 'E' || map[x][y] == 'C')
	{
		if (map[x][y] == 'C')
			game->val_gems++;
		if (map[x][y] == 'E')
			game->val_ext++;
		map[x][y] = 'M';
		flood_fill(game, map, x, y + 1);
		flood_fill(game, map, x, y - 1);
		flood_fill(game, map, x + 1, y);
		flood_fill(game, map, x - 1, y);
	}
}

void    valid_path(t_game *game)
{
   	if (game->val_gems != game->gems || game->val_ext != game->saida)
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
