/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbogey <mbogey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:59:39 by mbogey            #+#    #+#             */
/*   Updated: 2024/10/21 14:59:10 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned int nb, char *base, size_t *count)
{
	if ((int)nb >= ft_strlen_print(base))
		ft_putnbr_base((int)nb / ft_strlen_print(base), base, count);
	if (ft_putchar(base[nb % ft_strlen_print(base)], count) == -1)
		return (-1);
	return (0);
}
