/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbogey <mbogey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:51:47 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/16 21:39:12 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

static void	move_map_and_player(t_cube *cube, t_movement move);
static void	move_forward_backward(t_cube *cube, double theta);
static void	move_left_right(t_cube *cube, double theta);

int	move_pix(t_cube *cube)
{
	double	theta;

	cube->data.theta = (int)cube->data.theta % 360;
	theta = cube->data.theta * M_PI / 180;
	move_forward_backward(cube, theta);
	move_left_right(cube, theta);
	if (cube->keys[LEFT])
		cube->data.theta -= 2;
	if (cube->keys[RIGHT])
		cube->data.theta += 2;
	display_frames(cube);
	return (0);
}

static void	move_forward_backward(t_cube *cube, double theta)
{
	t_movement	move;

	if (cube->keys['w'])
	{
		move = (t_movement){cos(theta), sin(theta), -cos(theta), -sin(theta)};
		move_map_and_player(cube, move);
	}
	if (cube->keys['s'])
	{
		move = (t_movement){-cos(theta), -sin(theta), cos(theta), sin(theta)};
		move_map_and_player(cube, move);
	}
}

static void	move_left_right(t_cube *cube, double theta)
{
	t_movement	move;

	if (cube->keys['d'])
	{
		theta = (cube->data.theta + 90) * M_PI / 180;
		move = (t_movement){cos(theta), sin(theta), -cos(theta), -sin(theta)};
		move_map_and_player(cube, move);
	}
	if (cube->keys['a'])
	{
		theta = (cube->data.theta + 90) * M_PI / 180;
		move = (t_movement){-cos(theta), -sin(theta), cos(theta), sin(theta)};
		move_map_and_player(cube, move);
	}
}

static void	move_map_and_player(t_cube *cube, t_movement move)
{
	int	i;
	int	j;

	i = (cube->coord.x + move.inc_plr_maplimit_x * 10) / cube->tile_size;
	j = (cube->coord.y + move.inc_plr_maplimit_y * 10) / cube->tile_size;
	if (cube->map[j][i] == '0')
	{
		cube->coord.x += move.inc_plr_maplimit_x * 3;
		cube->coord.y += move.inc_plr_maplimit_y * 3;
		cube->coord.x_3d += move.inc_plr_maplimit_x * 12;
		cube->coord.y_3d += move.inc_plr_maplimit_y * 12;
		cube->mini_map.x += move.inc_map_x * 3;
		cube->mini_map.y += move.inc_map_y * 3;
		cube->mini_map.x_limit += move.inc_plr_maplimit_x * 3;
		cube->mini_map.y_limit += move.inc_plr_maplimit_y * 3;
	}
}
