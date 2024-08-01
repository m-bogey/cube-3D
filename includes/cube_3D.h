#ifndef CUBE_3D_H
# define CUBE_3D_H

#ifndef SCREEN_WIDTH
# define SCREEN_WIDTH 1000
#endif

#ifndef SCREEN_HEIGHT
# define SCREEN_HEIGHT 1000
#endif

#include "mlx.h"
#include <stdio.h> // pour le NULL
#include <stdlib.h> // exit

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_window;
}				t_mlx_data;

typedef struct s_cube
{
	t_mlx_data	mlx_cube;
}				t_cube;

void	init(t_cube *cube);
void	game(t_cube *cube);
void	quit_game_with_esc_or_cross(t_cube *cube);
void	safe_exit(t_cube *cube);

#endif