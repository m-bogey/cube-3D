/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_multiple_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 22:42:36 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/20 22:44:31 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

int	is_multiple_path(char *str)
{
	int	count_word;

	count_word = 0;
	while (*str && *str != '\n')
	{
		if (is_whitespace(*str) != 1)
		{
			count_word++;
			while (*str && is_whitespace(*str) != 1)
				str++;
		}
		while (*str && is_whitespace(*str) == 1)
			str++;
	}
	if (count_word > 1)
		return (1);
	return (0);
}
