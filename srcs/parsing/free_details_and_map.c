/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_details_and_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:28:03 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/14 17:28:04 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

void	free_details_and_map(t_cube *cube)
{
	size_t	i;

	i = 0;
	while (i < 6)
	{
		if (cube->details[i].str != NULL)
			free(cube->details[i].str);
		i++;
	}
	if (cube->map != NULL)
	{
		free_tab(cube->map);
	}
	if (cube->file != NULL)
	{
		free_tab(cube->file);
	}
}
