/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:05:21 by ebriere           #+#    #+#             */
/*   Updated: 2024/09/06 16:05:22 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

static int	check_file_valid(char *file);

int	parse_input(t_cube *cube, char **argv)
{
	int		fd;

	fd = check_file_valid (argv[1]);
	if (fd == -1)
		return (-1);
	cube->file = store_file_in_tab(fd, argv[1]);
	if (cube->file == NULL)
	{
		close(fd);
		return (-1);
	}
	if (close(fd) == -1)
		return (-1);
	if (store_map_info(cube, cube->file) == -1)
	{
		write(2, "Error\nWrong path or identifier\n", 31);
		return (-1);
	}
	cube->map = store_map(cube->file);
	if (cube->map == NULL)
		return (-1);
	if (check_map(cube->map, &cube->player) == -1
		|| check_map_info(cube->details) == -1)
		return (-1);
	return (0);
}

static int	check_file_valid(char *file)
{
	int		fd;
	size_t	i;

	i = 0;
	while (file && file[i])
		i++;
	if (i < 4 || (file[i - 1] != 'b' || file[i - 2] != 'u' || file[i - 3] != 'c'
			|| file[i - 4] != '.'))
	{
		write(2, "Error\nFile\n", 11);
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nOpen\n", 11);
		return (-1);
	}
	return (fd);
}
