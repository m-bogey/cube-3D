/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:51:00 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/14 20:51:01 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

static double	get_steps(t_cube *cube);
static double	get_incre(double diff, double steps);

void	draw_line(t_cube *cube, unsigned long color)
{
	t_line	line;
	double	x;
	double	y;
	int		i;

	x = cube->mini_map.x_player;
	y = cube->mini_map.y_player;
	line.steps = get_steps(cube);
	line.incre_x = get_incre(cube->coord.x_end - cube->coord.x, line.steps);
	line.incre_y = get_incre(cube->coord.y_end - cube->coord.y, line.steps);
	i = 0;
	while (i < (int)line.steps)
	{
		if (x >= 0 && y >= 0)
			img_pix_put(&cube->img, x, y, color);
		x += line.incre_x;
		y += line.incre_y;
		i++;
	}
}

static double	get_steps(t_cube *cube)
{
	double	steps_x;
	double	steps_y;

	steps_x = cube->coord.x_end - cube->coord.x;
	steps_y = cube->coord.y_end - cube->coord.y;
	if (steps_x < 0)
		steps_x = -steps_x;
	if (steps_y < 0)
		steps_y = -steps_y;
	if (steps_x > steps_y)
		return (steps_x);
	return (steps_y);
}

static double	get_incre(double diff, double steps)
{
	double	incre;

	incre = diff / steps;
	return (incre);
}
