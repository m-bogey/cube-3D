/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb_to_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:27:54 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/14 17:27:55 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

static int	check_str(char *str);
static void	convert_str_to_int(char *str, int *rgb);

long long	convert_rgb_to_hexa(char *str)
{
	long long	hexa_color;
	int			rgb[3];

	if (check_str(str) == -1)
	{
		write(2, "Error\nWrong color", 17);
		return (-1);
	}
	convert_str_to_int(str, rgb);
	if (rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255)
	{
		write(2, "Error\nWrong color", 17);
		return (-1);
	}
	hexa_color = ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
	return (hexa_color);
}

static int	check_str(char *str)
{
	size_t	i;
	int		count;

	count = 0;
	while (*str)
	{
		i = 0;
		while (str[i])
		{
			if (i > 2 || (str[i] < '0' || str[i] > '9'))
				break ;
			i++;
		}
		if (str[i] == '\0')
			break ;
		if (i == 0 || str[i] != ',' || str[i + 1] == '\0')
			return (-1);
		str = str + i + 1;
		count++;
	}
	if (count != 2)
		return (-1);
	return (0);
}

static void	convert_str_to_int(char *str, int *rgb)
{
	char	tmp[4];
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (*str != ',' && *str != '\0')
		{
			tmp[j] = *str;
			str++;
			j++;
		}
		tmp[j] = '\0';
		if (*str != '\0')
			str++;
		rgb[i] = ft_atoi(tmp);
		i++;
	}
}
