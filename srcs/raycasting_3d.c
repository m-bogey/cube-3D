/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbogey <mbogey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:47:57 by mbogey            #+#    #+#             */
/*   Updated: 2024/10/20 14:20:22 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

static void		init_raycasting(t_cube *cube);
static double	calcul_range_to_wall(t_cube *cube);
static int		choise_texture(t_cube *cube);

void	raycasting_3d(t_cube *cube)
{
	init_raycasting(cube);
	while (cube->r.x < SCREEN_WIDTH)
	{
		cube->r.ray_angle = cube->r.theta - (cube->data.pov / 2)
			+ ((double)cube->r.x / (double)SCREEN_WIDTH) * cube->data.pov;
		cube->r.ray_x = cube->coord.x_3d;
		cube->r.ray_y = cube->coord.y_3d;
		cube->r.hit = false;
		while (cube->r.hit != true)
		{
			cube->r.ray_x += cos(cube->r.ray_angle);
			cube->r.ray_y += sin(cube->r.ray_angle);
			cube->r.map_x = (int)(cube->r.ray_x / cube->tile_size_3d);
			cube->r.map_y = (int)(cube->r.ray_y / cube->tile_size_3d);
			if (cube->map[cube->r.map_y][cube->r.map_x] == '1')
			{
				cube->r.hit = true;
				cube->r.range_to_wall = calcul_range_to_wall(cube);
				cube->r.texture_id = choise_texture(cube);
				convert_to_3d(cube);
			}
		}
		cube->r.x++;
	}
}

static void	init_raycasting(t_cube *cube)
{
	cube->r.texture_id = 0;
	cube->r.x = 0;
	cube->r.theta = cube->data.theta * M_PI / 180;
}

static double	calcul_range_to_wall(t_cube *cube)
{
	double	theta;
	double	range_to_wall;

	theta = cube->data.theta * M_PI / 180;
	range_to_wall = sqrt((cube->r.ray_x - cube->coord.x_3d)
			* (cube->r.ray_x - cube->coord.x_3d)
			+ (cube->r.ray_y - cube->coord.y_3d)
			* (cube->r.ray_y - cube->coord.y_3d));
	range_to_wall *= cos(theta - cube->r.ray_angle);
	if (range_to_wall < 0.001)
		range_to_wall = 0.001;
	return (range_to_wall);
}

static int	choise_texture(t_cube *cube)
{
	int	map_x_before_hit_wall;
	int	map_y_before_hit_wall;
	int	orientation_x;
	int	orientation_y;

	map_x_before_hit_wall = (int)((cube->r.ray_x - cos(cube->r.ray_angle))
			/ cube->tile_size_3d);
	map_y_before_hit_wall = (int)((cube->r.ray_y - sin(cube->r.ray_angle))
			/ cube->tile_size_3d);
	orientation_x = cube->r.map_x - map_x_before_hit_wall;
	orientation_y = cube->r.map_y - map_y_before_hit_wall;
	if (orientation_x == 1 && orientation_y == 0)
		cube->r.texture_id = EAST;
	else if (orientation_x == -1 && orientation_y == 0)
		cube->r.texture_id = WEST;
	else if (orientation_x == 0 && orientation_y == -1)
		cube->r.texture_id = NORTH;
	else if (orientation_x == 0 && orientation_y == 1)
		cube->r.texture_id = SOUTH;
	return (cube->r.texture_id);
}
