/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbogey <mbogey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:06:10 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/16 15:13:00 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum s_type
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	CEILING,
	FLOOR,
}				t_type;

typedef struct s_tab
{
	t_type			type;
	char			*str;
	long long		color;
}				t_tab;

typedef struct s_player
{
	ssize_t	x;
	ssize_t	y;
	double	px;
	double	py;
	double	pdx;
	double	pdy;
	double	pa;
	char	player_orientation_start;
}				t_player;

typedef struct s_img
{
	void	*ptr_img;
	char	*address;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}			t_img;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_window;
	double	range_to_wall;
	double	pov;
	double	theta;
}				t_mlx_data;

typedef struct s_coord
{
	double	x;
	double	y;
	double	x_3d;
	double	y_3d;
	double	x_end;
	double	y_end;
}			t_coord;

typedef struct s_2d
{
	double	x;
	double	y;
	double	x_player;
	double	y_player;
	double	height;
	double	width;
	double	y_limit;
	double	x_limit;
}			t_2d;

typedef struct s_raycast
{
	double	range_to_wall;
	double	ray_angle;
	double	ray_x;
	double	ray_y;
	double	x;
	bool	hit;
	double	theta;
	int		texture_id;
	int		map_x;
	int		map_y;
}				t_raycast;

typedef struct s_conv3d
{
	int		wall_height;
	int		wall_start;
	int		wall_end;
	int		y;
	double	tex_pos;
	double	step;
	int		y_tex;
	int		x_tex;
	double	hit_x;
}				t_conv3d;

typedef struct s_line
{
	double	incre_x;
	double	incre_y;
	double	steps;
}				t_line;

typedef struct s_movement
{
	double	inc_plr_maplimit_x;
	double	inc_plr_maplimit_y;
	double	inc_map_x;
	double	inc_map_y;
}				t_movement;

typedef struct s_cube
{
	int			x;
	int			y;
	int			x_eye;
	int			y_eye;
	t_player	player;
	t_coord		coord;
	t_mlx_data	data;
	t_img		img;
	char		**file;
	t_tab		details[6];
	t_2d		mini_map;
	char		**map;
	int			tile_size;
	int			tile_size_3d;
	t_img		texture[4];
	long long	colors[2];
	t_raycast	r;
	t_conv3d	c;
	int			keys[70000];
}				t_cube;

#endif
