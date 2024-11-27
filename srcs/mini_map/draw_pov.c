/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_POV.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:50:55 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/14 20:50:56 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

static void	raycasting_mini_map(t_cube *cube, double theta)
{
	int		i;
	int		j;

	theta = theta * M_PI / 180;
	i = cube->coord.x / cube->tile_size;
	j = cube->coord.y / cube->tile_size;
	cube->coord.x_end = cube->coord.x;
	cube->coord.y_end = cube->coord.y;
	while (cube->map[j][i] == '0' && cube->coord.x_end < cube->mini_map.x_limit
			&& cube->coord.y_end < cube->mini_map.y_limit)
	{
		i = cube->coord.x_end / cube->tile_size;
		j = cube->coord.y_end / cube->tile_size;
		cube->coord.x_end += cos(theta);
		cube->coord.y_end += sin(theta);
	}
}

void	draw_pov(t_cube *cube)
{
	double	theta;

	theta = cube->data.theta - 30;
	while (theta < cube->data.theta + 30)
	{
		raycasting_mini_map(cube, theta);
		draw_line(cube, PINK_PIXEL);
		theta += 1;
	}
}
