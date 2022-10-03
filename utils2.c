/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 22:59:07 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/03 16:17:09 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_filling(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				if (map[x][y + 1] == '0' || map[x][y + 1] == 'C')
					return (0);
				if (map[x][y - 1] == '0' || map[x][y - 1] == 'C')
					return (0);
				if (map[x + 1][y] == '0' || map[x + 1][y] == 'C')
					return (0);
				if (map[x - 1][y] == '0' || map[x - 1][y] == 'C')
					return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

void	set_fill(char **map, int x, int y)
{
	if (map[x][y + 1] == '0' || map[x][y + 1] == 'C')
		map[x][y + 1] = 'P';
	if (map[x][y - 1] == '0' || map[x][y - 1] == 'C')
		map[x][y - 1] = 'P';
	if (map[x + 1][y] == '0' || map[x + 1][y] == 'C')
		map[x + 1][y] = 'P';
	if (map[x - 1][y] == '0' || map[x - 1][y] == 'C')
		map[y - 1][y] = 'P';
}

void	flood(char **map)
{
	int	x;
	int y;
	
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
				set_fill(map, x, y);
			x++;
		}
		y++;
	}
}

int	flood_fill(char **map, int lines)
{
	int		idx;
	char	**temp;

	idx = -1;
	temp = ft_calloc(sizeof(char *), lines + 1);
	if (!temp)
		return (0);
	while (++idx < lines)
		temp[idx] = ft_strdup(map[idx]);
	while (!check_filling(temp))
		flood(temp);
	if (checkout(temp) && !check_collects(temp, 'C'))
		return (free_strmap(temp), 1);
	return (free_strmap(temp), 0);
}

int	checkout(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				if (map[i][j + 1] == 'P')
					return (1);
				if (map[i][j - 1] == 'P')
					return (1);
				if (map[i + 1][j] == 'P')
					return (1);
				if (map[i - 1][j] == 'P')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_path(char **argv, char **map)
{
	if (!flood_fill(map, count_line(argv[1])))
	{
		exit_error("Sem caminho valido leila");
		return (0);
	}
	return (1);
}
