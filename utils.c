/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 05:16:04 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/22 20:39:47 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_nbr(t_fdf *mats, int x, int y, int nbr)
{
	char	*str;

	str = ft_itoa(nbr);
	mlx_string_put(mats->mlx, mats->win, x, y, 0x000000, str);
	free (str);
}

void	print_str(t_fdf *mats, int x, int y, char *str)
{
	mlx_string_put(mats->mlx, mats->win, x, y, 0x000000, str);
}
