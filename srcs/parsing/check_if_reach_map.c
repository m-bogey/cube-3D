/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_reach_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:27:37 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/14 17:27:39 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

int	check_if_reach_map(char *str)
{
	size_t	i;

	i = 0;
	if (str && str_is_only_white_space(str) == 1)
		return (0);
	while (str && str[i])
	{
		if (str[i] != '1' && is_whitespace(str[i]) != 1)
			break ;
		i++;
	}
	if (str == NULL || str[i] == '\n')
	{
		return (1);
	}
	return (0);
}
