/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:45:53 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/14 18:45:54 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

static void	check_player(char **map, t_player *pos);
static int	check_content(char **map);

int	check_map(char **map, t_player *pos)
{
	pos->x = -1;
	check_player(map, pos);
	if (pos->x == -1)
	{
		write(2, "Error\nPlayer\n", 13);
		return (-1);
	}
	if (check_content(map) == -1)
	{
		write(2, "Error\nMap content\n", 18);
		return (-1);
	}
	if (check_wall(map) == -1)
	{
		write(2, "Error\nWalls\n", 12);
		return (-1);
	}
	return (0);
}

static void	check_player(char **map, t_player *pos)
{
	ssize_t	y;
	ssize_t	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
					|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				pos->player_orientation_start = map[y][x];
				pos->y = y;
				pos->x = x;
				map[y][x] = '0';
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

static int	check_content(char **map)
{
	ssize_t	y;
	ssize_t	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != ' ')
				return (-1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
