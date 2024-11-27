/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3D.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:34:39 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/20 21:28:27 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_3D_H
# define CUBE_3D_H

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 1500
# endif

# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 1500
# endif

# define WALL_HEIGHT 8

# define PINK_PIXEL 0xFF69B4
# define BLACK_PIXEL 0x000000
# define WHITE_PIXEL 0xFFFFFF
# define SILVER_PIXEL 0xC0C0C0

# define PLAYER_2D_SIZE 25

# define ECHAP 65307
# define LEFT 65361
# define RIGHT 65363

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "struct.h"
# include "parsing.h"
# include <unistd.h>
# include <errno.h>

int		game(t_cube *cube);
int		init(t_cube *cube);
void	use_keys(t_cube *cube);
void	safe_exit(t_cube *cube);
void	move_pixels(t_cube *cube);
int		move_pix(t_cube *cube);
void	draw_pov(t_cube *cube);
void	draw_line(t_cube *cube, unsigned long color);
void	raycasting_3d(t_cube *cube);
void	convert_to_3d(t_cube *cube);
void	display_mini_map(t_cube *cube);
void	draw_walls(t_cube *cube);
void	display_frames(t_cube *cube);
void	img_pix_put(t_img *img, int x, int y, int color);
void	free_details_and_map(t_cube *cube);
void	free_tab(char **tab);

#endif
