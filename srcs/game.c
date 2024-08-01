#include <stdio.h>
#include "mlx.h"

void	game()
{
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 300, 300, "Dodo");
	if (mlx_window == NULL)
		return ; //TODO : protection/clean avec exit
	mlx_loop(mlx);
}