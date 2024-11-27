/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mini_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbogey <mbogey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:51:00 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/20 13:53:41 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

static void	fill_mini_map_background(t_cube *cube);
static void	display_borders(t_cube *cube);
static void	display_mini_player(t_cube *cube);

void	display_mini_map(t_cube *cube)
{
	fill_mini_map_background(cube);
	display_borders(cube);
	draw_walls(cube);
	draw_pov(cube);
	display_mini_player(cube);
}

static void	fill_mini_map_background(t_cube *cube)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < cube->mini_map.height)
	{
		while (x < cube->mini_map.width)
		{
			img_pix_put(&cube->img, x, y, BLACK_PIXEL);
			x++;
		}
		x = 0;
		y++;
	}
}

static void	display_borders(t_cube *cube)
{
	double	x;
	double	y;

	y = cube->mini_map.height;
	while (y >= 0)
	{
		x = cube->mini_map.width;
		while (x <= cube->mini_map.width + 10)
		{
			img_pix_put(&cube->img, x, y, WHITE_PIXEL);
			x++;
		}
		y--;
	}
	x = cube->mini_map.width + 10;
	while (x >= 0)
	{
		y = cube->mini_map.height;
		while (y <= cube->mini_map.height + 10)
		{
			img_pix_put(&cube->img, x, y, WHITE_PIXEL);
			y++;
		}
		x--;
	}
}

static void	display_mini_player(t_cube *cube)
{
	double	x;
	double	y;
	double	theta;
	double	r;

	r = 1;
	theta = 0;
	while (r < 10)
	{
		while (theta < 360)
		{
			x = cube->mini_map.x_player + cos(theta) * r;
			y = cube->mini_map.y_player + sin(theta) * r;
			img_pix_put(&cube->img, x, y, WHITE_PIXEL);
			theta++;
		}
		theta = 0;
		r += 1;
	}
}
