#include "cube_3D.h"

void	game(t_cube *cube)
{
	cube->mlx_cube.mlx = mlx_init();
	cube->mlx_cube.mlx_window = mlx_new_window(cube->mlx_cube.mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "Dodo");
	if (cube->mlx_cube.mlx_window == NULL)
		safe_exit(cube);
	quit_game_with_esc_or_cross(cube);
	mlx_loop(cube->mlx_cube.mlx);
}