/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:51:07 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/14 20:51:33 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

static void	fill_tile(t_cube *cube, int y, int x);

void	draw_walls(t_cube *cube)
{
	int		j;
	int		i;
	double	x;
	double	y;

	x = cube->mini_map.x;
	y = cube->mini_map.y;
	i = 0;
	j = 0;
	while (cube->map[j])
	{
		while (cube->map[j][i])
		{
			if (cube->map[j][i] == '1')
				fill_tile(cube, y, x);
			i++;
			x += cube->tile_size;
		}
		i = 0;
		j++;
		x = cube->mini_map.x;
		y += cube->tile_size;
	}
}

static void	fill_tile(t_cube *cube, int y, int x)
{
	int	end_tile_x;
	int	end_tile_y;
	int	tmp_x;

	end_tile_x = x + cube->tile_size;
	end_tile_y = y + cube->tile_size;
	tmp_x = x;
	while (y < end_tile_y)
	{
		while (x < end_tile_x)
		{
			if (x < cube->mini_map.width && y < cube->mini_map.height
				&& x >= 0 && y >= 0)
				img_pix_put(&cube->img, x, y, SILVER_PIXEL);
			x++;
		}
		x = tmp_x;
		y++;
	}
}
