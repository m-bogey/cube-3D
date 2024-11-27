/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:04:12 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/14 19:04:13 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

static int	check_if_clone_type(t_tab *details);
static int	is_texture_path_valid(char *path);

int	check_map_info(t_tab *details)
{
	size_t	i;

	if (check_if_clone_type(details) == 1)
		return (-1);
	i = 0;
	while (i < 6)
	{
		if (details[i].type != CEILING && details[i].type != FLOOR)
		{
			if (is_texture_path_valid(details[i].str) == -1)
				return (-1);
		}
		else
		{
			details[i].color = convert_rgb_to_hexa(details[i].str);
			if (details[i].color == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

static int	check_if_clone_type(t_tab *details)
{
	int	j;
	int	i;
	int	type;

	i = 0;
	j = 0;
	while (j < 6)
	{
		type = (int)details[j].type;
		while (i < 6)
		{
			if ((int)details[i].type == type && i != j)
			{
				write(2, "Error\nWrong identifier\n", 23);
				return (1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

static int	is_texture_path_valid(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nTexture path not valid\n", 29);
		return (-1);
	}
	if (close(fd) == -1)
		return (-1);
	return (0);
}
