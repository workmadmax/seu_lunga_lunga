/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ximbinha.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:29:09 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/16 19:11:54 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_path(t_game *game, int x, int y)
{
    char    *p;

    p = &game->tmp_map[x][y];
    if (*p == 'E')
        game->val_ext++;
    if (*p != 'E' && *p != '1')
    {
        if (*p == 'C')
            game->val_gems++;
        *p = 'x';
        if (game->tmp_map[x][y + 1] != '1' && game->tmp_map[x][y + 1] != 'x')
            check_path(game, x, y + 1);
        if (game->tmp_map[x][y - 1] != '1' && game->tmp_map[x][y - 1] != 'x')
            check_path(game, x, y - 1);
        if (game->tmp_map[x + 1][y] != '1' && game->tmp_map[x + 1][y] != 'x')
            check_path(game, x + 1, y);
        if (game->tmp_map[x - 1][y] != '1' && game->tmp_map[x - 1][y] != 'x')
            check_path(game, x - 1, y);
    }
	valid_path(game);
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
