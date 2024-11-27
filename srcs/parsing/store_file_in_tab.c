/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_file_in_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:28:21 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/20 21:03:48 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"
#include <stdlib.h>

static int		fill_tab(char ***tab, int fd);
static ssize_t	count_nbr_line(int fd);

char	**store_file_in_tab(int fd, char *file)
{
	ssize_t	nbr_line;
	char	**file_info;

	file_info = NULL;
	nbr_line = count_nbr_line(fd);
	if (nbr_line == -1)
		return (NULL);
	file_info = malloc((nbr_line) * sizeof(char *));
	if (file_info == NULL)
		return (NULL);
	if (close(fd) == -1)
	{
		free(file_info);
		return (NULL);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(file_info);
		return (NULL);
	}
	if (fill_tab(&file_info, fd) == -1)
		return (NULL);
	return (file_info);
}

static ssize_t	count_nbr_line(int fd)
{
	ssize_t	i;
	char	*line;

	i = 0;
	line = "test";
	while (line != NULL)
	{
		line = get_next_line(fd);
		free(line);
		++i;
	}
	if (errno == ENOMEM)
		return (-1);
	return (i);
}

static int	fill_tab(char ***tab, int fd)

{
	size_t	i;
	char	*line;

	i = 0;
	line = "test";
	while (line != NULL)
	{
		line = get_next_line(fd);
		(*tab)[i] = line;
		++i;
	}
	if (errno == ENOMEM)
	{
		free_tab(*tab);
		return (-1);
	}
	return (0);
}
