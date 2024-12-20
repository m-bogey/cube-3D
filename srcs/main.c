/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:01:06 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/16 21:01:08 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

int	main(int argc, char **argv)
{
	t_cube	cube;

	(void)argc;
	ft_memset(&cube, 0, sizeof(t_cube));
	if (parse_input(&cube, argv) == -1)
	{
		free_details_and_map(&cube);
		return (-1);
	}
	if (game(&cube) == -1)
	{
		free_details_and_map(&cube);
		return (-1);
	}
	return (0);
}
