/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_whitespace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:28:07 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/14 17:28:08 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

int	is_whitespace(int c)
{
	if ((c >= 11 && c <= 13) || c == 32 || c == 9)
		return (1);
	return (0);
}

int	str_is_only_white_space(char *str)
{
	while (str && *str)
	{
		if (is_whitespace(*str) != 1)
			break ;
		str++;
	}
	if (*str == '\n')
		return (1);
	return (0);
}
