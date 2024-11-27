/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mini_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:50:38 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/14 20:50:40 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

void	display_frames(t_cube *cube)
{
	cube->img.ptr_img = mlx_new_image(cube->data.mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	if (cube->img.ptr_img == NULL)
		safe_exit(cube);
	cube->img.address = mlx_get_data_addr(cube->img.ptr_img, &cube->img.bpp,
			&cube->img.line_len, &cube->img.endian);
	raycasting_3d(cube);
	display_mini_map(cube);
	mlx_put_image_to_window(cube->data.mlx, cube->data.mlx_window,
		cube->img.ptr_img, 0, 0);
	mlx_destroy_image(cube->data.mlx, cube->img.ptr_img);
	cube->img.ptr_img = NULL;
}
