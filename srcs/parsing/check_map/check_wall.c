/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:46:09 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/14 18:46:10 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

static size_t	get_height(char **map);
static int		check_wall_surrounds_floor(char **map, size_t map_height,
					size_t y, size_t x);
static int		check_surroundings(char right, char left, char down, char up);
static int		check_angles(char lu_a, char ru_a, char ld_a,
					char lr_a);

int	check_wall(char **map)
{
	size_t	x;
	size_t	y;
	size_t	map_height;

	x = 0;
	y = 0;
	map_height = get_height(map);
	if (check_wall_surrounds_floor(map, map_height, y, x) == -1)
		return (-1);
	return (0);
}

static size_t	get_height(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static int	check_wall_surrounds_floor(char **map, size_t map_height,
			size_t y, size_t x)
{
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == '0')
			{
				if (x > 0 && x < ft_strlen(map[y])
					&& y > 0 && y < (map_height - 1))
				{
					if (check_surroundings(map[y][x + 1], map[y][x - 1],
						map[y + 1][x], map[y - 1][x]) == -1)
						return (-1);
					if (check_angles(map[y - 1][x - 1], map[y - 1][x + 1],
						map[y + 1][x - 1], map[y + 1][x + 1]) == -1)
						return (-1);
				}
				else
					return (-1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

static int	check_surroundings(char right, char left, char down, char up)
{
	if (right == ' ' || left == ' ' || down == ' ' || up == ' '
		|| right == '\n' || left == '\n' || down == '\n' || up == '\n'
		||right == '\0' || left == '\0' || down == '\0' || up == '\0')
	{
		return (-1);
	}
	return (0);
}

static int	check_angles(char lu_a, char ru_a, char ld_a,
			char rd_a)
{
	if (lu_a == ' ' || ru_a == ' ' || ld_a == ' ' || rd_a == ' '
		|| lu_a == '\n' || ru_a == '\n' || ld_a == '\n' || rd_a == '\n'
		|| lu_a == '\0' || ru_a == '\0' || ld_a == '\0' || rd_a == '\0')
	{
		return (-1);
	}
	return (0);
}
