/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:28:51 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/14 17:28:52 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

static int		get_type(t_tab *details, char *str);
static int		is_identifier(char **str);
static char		*get_path_or_color(char *str);
static size_t	get_nbr_info(char **file_info);

int	store_map_info(t_cube *cube, char **file_info)
{
	size_t	nbr_line;
	size_t	i;
	size_t	j;

	nbr_line = get_nbr_info(file_info);
	if (nbr_line != 6)
		return (-1);
	i = 0;
	j = 0;
	while (check_if_reach_map(file_info[i]) != 1)
	{
		if (str_is_only_white_space(file_info[i]) != 1)
		{
			if (get_type(&cube->details[j], file_info[i]) != -1)
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

static size_t	get_nbr_info(char **file_info)
{
	size_t	i;
	size_t	line;

	i = 0;
	line = 0;
	while (check_if_reach_map(file_info[i]) != 1)
	{
		if (str_is_only_white_space(file_info[i]) != 1)
			line++;
		i++;
	}
	return (line);
}

static int	get_type(t_tab *details, char *str)
{
	ssize_t	type;

	while (*str)
	{
		if (is_whitespace(*str) != 1)
		{
			type = is_identifier(&str);
			if (type == -1)
				return (-1);
			details->type = type;
			details->str = get_path_or_color(str);
			if (details->str == NULL)
			{
				return (-1);
			}
			break ;
		}
		str++;
	}
	return (0);
}

static int	is_identifier(char **str)
{
	ssize_t				j;
	static const char	*type_list[] = {
	[NORTH] = "NO",
	[SOUTH] = "SO",
	[EAST] = "EA",
	[WEST] = "WE",
	[CEILING] = "C",
	[FLOOR] = "F"
	};

	j = 0;
	while (j <= FLOOR)
	{
		if (ft_strncmp(*str, type_list[j], ft_strlen(type_list[j])) == 0)
		{
			*str += ft_strlen(type_list[j]);
			return (j);
		}
		j++;
	}
	return (-1);
}

static char	*get_path_or_color(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	if (str_is_only_white_space(str) == 1 || is_multiple_path(str) == 1)
		return (NULL);
	while (is_whitespace(str[i]) == 1)
		i++;
	j = i;
	while (is_whitespace(str[j]) != 1 && str[j] != '\n')
		j++;
	new_str = malloc((j + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	j = 0;
	while (is_whitespace(str[i]) != 1 && str[i] != '\n')
	{
		new_str[j] = str[i];
		j++;
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}
