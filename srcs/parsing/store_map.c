/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:28:46 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/14 17:28:47 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

static ssize_t	get_map_length(char **file);

char	**store_map(char **file)
{
	char	**map;
	size_t	i;
	ssize_t	length;

	while (check_if_reach_map(*file) != 1)
		file++;
	length = get_map_length(file);
	if (length == -1)
		return (NULL);
	map = malloc((length + 1) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (*file != NULL && str_is_only_white_space(*file) != 1)
	{
		map[i] = malloc((ft_strlen(*file) + 1) * sizeof(char));
		if (map[i] == NULL)
			return (NULL);
		ft_strlcpy(map[i], *file, ft_strlen(*file));
		file++;
		i++;
	}
	map[i] = NULL;
	return (map);
}

static ssize_t	get_map_length(char **file)
{
	ssize_t	length;

	length = 0;
	while (*file != NULL)
	{
		length++;
		file++;
	}
	return (length);
}
