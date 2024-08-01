#include "cube_3D.h"

static void	init_mlx_cube(t_cube *cube);

void	init(t_cube *cube)
{
	init_mlx_cube(cube);
}

static void	init_mlx_cube(t_cube *cube)
{
	cube->mlx_cube.mlx = NULL;
	cube->mlx_cube.mlx_window = NULL;
}