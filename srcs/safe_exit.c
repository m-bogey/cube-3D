#include "cube_3D.h"

void	safe_exit(t_cube *cube)
{
	if (cube->mlx_cube.mlx != NULL)
		mlx_loop_end(cube->mlx_cube.mlx);
	if (cube->mlx_cube.mlx_window != NULL)
		mlx_destroy_window(cube->mlx_cube.mlx, cube->mlx_cube.mlx_window);
	exit(0);
}