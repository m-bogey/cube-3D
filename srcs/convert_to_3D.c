/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_3D.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbogey <mbogey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:47:57 by mbogey            #+#    #+#             */
/*   Updated: 2024/10/20 14:20:16 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

static void	draw_3d(t_cube *cube);

static void	init_convert_t_3d(t_cube *cube)
{
	if (cube->c.wall_height < 1)
		cube->c.wall_height = 1;
	cube->c.wall_start = (SCREEN_HEIGHT / 2) - (cube->c.wall_height / 2);
	cube->c.wall_end = cube->c.wall_start + cube->c.wall_height;
	if (cube->c.wall_start < 0)
		cube->c.wall_start = 0;
	if (cube->c.wall_end >= SCREEN_HEIGHT)
		cube->c.wall_end = SCREEN_HEIGHT - 1;
}

void	convert_to_3d(t_cube *cube)
{
	cube->c.wall_height = ((cube->tile_size_3d / cube->r.range_to_wall)
			* (SCREEN_WIDTH / 2) / tan(cube->data.pov / 2));
	init_convert_t_3d(cube);
	if (cube->r.texture_id == EAST || cube->r.texture_id == WEST)
		cube->c.hit_x = cube->r.ray_y;
	else
		cube->c.hit_x = cube->r.ray_x;
	cube->c.x_tex = (int)(cube->c.hit_x / cube->tile_size_3d
			* cube->texture[cube->r.texture_id].width)
		% cube->texture[cube->r.texture_id].width;
	if (cube->r.texture_id == WEST || cube->r.texture_id == SOUTH)
		cube->c.x_tex = cube->texture[cube->r.texture_id].width - cube->c.x_tex
			- 1;
	cube->c.step = 1.0 * cube->texture[cube->r.texture_id].height
		/ cube->c.wall_height;
	cube->c.tex_pos = (cube->c.wall_start - SCREEN_HEIGHT / 2
			+ cube->c.wall_height / 2) * cube->c.step;
	cube->c.y = 0;
	while (cube->c.y < SCREEN_HEIGHT)
	{
		draw_3d(cube);
		cube->c.y++;
	}
}

static void	draw_3d(t_cube *cube)
{
	char	*color;

	if (cube->c.y >= cube->c.wall_start && cube->c.y <= cube->c.wall_end)
	{
		cube->c.y_tex = (int)cube->c.tex_pos;
		if (cube->c.y_tex >= 0
			&& cube->c.y_tex < cube->texture[cube->r.texture_id].height)
		{
			color = cube->texture[cube->r.texture_id].address
				+ (cube->c.y_tex * cube->texture[cube->r.texture_id].line_len
					+ cube->c.x_tex
					* (cube->texture[cube->r.texture_id].bpp / 8));
			img_pix_put(&cube->img, cube->r.x, cube->c.y,
				*(unsigned int *)color);
		}
		cube->c.tex_pos += cube->c.step;
	}
	else if (cube->c.y < cube->c.wall_start)
		img_pix_put(&cube->img, cube->r.x, cube->c.y, cube->colors[0]);
	else
		img_pix_put(&cube->img, cube->r.x, cube->c.y, cube->colors[1]);
}
