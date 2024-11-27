/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pix_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:01:33 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/16 21:10:22 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->address + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}
