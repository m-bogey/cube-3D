/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbogey <mbogey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:51:47 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/16 21:44:06 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

static int	keys_press(int keycode, t_cube *cube);
static int	keys_release(int keycode, t_cube *cube);
static int	key_close(t_cube *cube);

int	game(t_cube *cube)
{
	cube->data.mlx = mlx_init();
	if (cube->data.mlx == NULL)
		return (-1);
	if (init(cube) == -1)
		return (-1);
	cube->data.mlx_window = mlx_new_window(cube->data.mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "Dodo");
	if (cube->data.mlx_window == NULL)
		return (-1);
	display_frames(cube);
	mlx_hook(cube->data.mlx_window, 2, 1L << 0, keys_press, cube);
	mlx_hook(cube->data.mlx_window, 3, 1L << 1, keys_release, cube);
	mlx_hook(cube->data.mlx_window, 17, 0, key_close, cube);
	mlx_loop_hook(cube->data.mlx, move_pix, cube);
	mlx_loop(cube->data.mlx);
	return (0);
}

static int	keys_press(int keycode, t_cube *cube)
{
	if (keycode == ECHAP)
		safe_exit(cube);
	if (keycode < 70000)
		cube->keys[keycode] = 1;
	return (0);
}

static int	keys_release(int keycode, t_cube *cube)
{
	if (keycode < 70000)
		cube->keys[keycode] = 0;
	return (0);
}

static int	key_close(t_cube *cube)
{
	safe_exit(cube);
	return (0);
}
