/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbogey <mbogey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:13:31 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/20 14:15:30 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

void	safe_exit(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cube->texture[i].ptr_img != NULL)
			mlx_destroy_image(cube->data.mlx, cube->texture[i].ptr_img);
		i++;
	}
	if (cube->data.mlx_window != NULL)
		mlx_destroy_window(cube->data.mlx, cube->data.mlx_window);
	if (cube->data.mlx != NULL)
	{
		mlx_destroy_display(cube->data.mlx);
		free(cube->data.mlx);
	}
	if (cube->img.ptr_img != NULL)
		mlx_destroy_image(cube->data.mlx, cube->img.ptr_img);
	free_details_and_map(cube);
	exit(0);
}
