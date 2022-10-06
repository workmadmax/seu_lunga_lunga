/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:39:14 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/06 08:59:18 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_path(t_game *game, int x, int y)
{
    char    *p;

    p = &game->tmap[x][y];
    if (*p == 'E')
        game->val_ext++;
    if (*p != 'E' && *p != '1')
    {
        if (*p == 'C')
            game->tmp_col++;
        *p = 'x';
        if (game->tmap[x][y + 1] != '1' && game->tmap[x][y + 1] != 'x')
            check_path(game, x, y + 1);
        if (game->tmap[x][y - 1] != '1' && game->tmap[x][y - 1] != 'x')
            check_path(game, x, y - 1);
        if (game->tmap[x + 1][y] != '1' && game->tmap[x + 1][y] != 'x')
            check_path(game, x + 1, y);
        if (game->tmap[x - 1][y] != '1' && game->tmap[x - 1][y] != 'x')
            check_path(game, x - 1, y);
    }
}

void    valid_path(t_game *game)
{
    if (game->tmp_col != game->gems || game->val_ext != game->saida)
        exit_error("Error! invalid path for map");
}