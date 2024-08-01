#include "cube_3D.h"

static int	key_close(t_cube *cube);
static int	key_escape(int keycode, t_cube *cube);

void	quit_game_with_esc_or_cross(t_cube *cube)
{
	mlx_hook(cube->mlx_cube.mlx_window, 17, 0, key_close, cube);
	mlx_hook(cube->mlx_cube.mlx_window, 2, 1L << 0, key_escape, cube);
}

static int	key_close(t_cube *cube)
{
	safe_exit(cube);
	return (0);
}

static int	key_escape(int keycode, t_cube *cube)
{
	if (keycode == 65307)
		safe_exit(cube);
	return (0);
}
