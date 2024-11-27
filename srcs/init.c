/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbogey <mbogey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:15:47 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/20 14:20:08 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

static void	init_start_game(t_cube *cube);
static void	init_mini_map(t_cube *cube);
static int	init_str_texture(t_cube *cube);
static int	init_texture(t_cube *cube, t_type type, char *str);

int	init(t_cube *cube)
{
	init_start_game(cube);
	init_mini_map(cube);
	if (init_str_texture(cube) == -1)
		return (-1);
	return (0);
}

static void	init_start_game(t_cube *cube)
{
	cube->data.pov = M_PI / 3;
	if (cube->player.player_orientation_start == 'N')
		cube->data.theta = 270;
	else if (cube->player.player_orientation_start == 'W')
		cube->data.theta = 180;
	else if (cube->player.player_orientation_start == 'S')
		cube->data.theta = 90;
	else
		cube->data.theta = 0;
	cube->tile_size = 50;
	cube->tile_size_3d = 200;
	cube->coord.x = (cube->player.x * cube->tile_size) + cube->tile_size / 2;
	cube->coord.y = (cube->player.y * cube->tile_size) + cube->tile_size / 2;
	cube->coord.x_3d = (cube->player.x * cube->tile_size_3d)
		+ cube->tile_size_3d / 2;
	cube->coord.y_3d = (cube->player.y * cube->tile_size_3d)
		+ cube->tile_size_3d / 2;
}

static void	init_mini_map(t_cube *cube)
{
	cube->mini_map.height = SCREEN_HEIGHT / 4;
	cube->mini_map.width = SCREEN_WIDTH / 4;
	cube->mini_map.x_player = cube->mini_map.width / 2;
	cube->mini_map.y_player = cube->mini_map.height / 2;
	cube->mini_map.x = 0 + cube->mini_map.x_player - cube->coord.x;
	cube->mini_map.y = 0 + cube->mini_map.y_player - cube->coord.y;
	cube->mini_map.y_limit = cube->mini_map.height - cube->mini_map.y;
	cube->mini_map.x_limit = cube->mini_map.width - cube->mini_map.x;
}

static int	init_str_texture(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (cube->details[i].type != CEILING && cube->details[i].type != FLOOR)
		{
			if (init_texture(cube, cube->details[i].type,
					cube->details[i].str) == -1)
				return (-1);
		}
		else if (cube->details[i].type == CEILING)
			cube->colors[0] = cube->details[i].color;
		else
			cube->colors[1] = cube->details[i].color;
		i++;
	}
	return (0);
}

static int	init_texture(t_cube *cube, t_type type, char *str)
{
	char	*relative_path;

	relative_path = str;
	cube->texture[type].ptr_img = NULL;
	cube->texture[type].ptr_img = mlx_xpm_file_to_image(cube->data.mlx,
			relative_path, &cube->texture[type].width,
			&cube->texture[type].height);
	if (cube->texture[type].ptr_img == NULL)
	{
		write(2, "Error, init texture\n", 20);
		return (-1);
	}
	cube->texture[type].address = mlx_get_data_addr(cube->texture[type].ptr_img,
			&cube->texture[type].bpp, &cube->texture[type].line_len,
			&cube->texture[type].endian);
	return (0);
}
