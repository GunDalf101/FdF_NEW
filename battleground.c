/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battleground.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 08:13:57 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/19 09:29:18 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void white_back(t_fdf *mats)
{
	int	i;
	int	j;
	
	i = -1;
	while (++i < XWIN)
	{	j = -1;
		while (++j < YWIN)
			my_mlx_pixel_put(&mats->img , i, j, 0xFFFFFF);
	}
}

void gimme_grey(t_fdf *mats)
{
	int	i;
	int	j;
	
	i = -1;
	while (++i < XWIN)
	{	j = -1;
		while (++j < YWIN)
			my_mlx_pixel_put(&mats->img , i, j, 0x808080);
	}
}

void sky_high(t_fdf *mats)
{
	int	i;
	int	j;
	
	i = -1;
	while (++i < XWIN)
	{	j = -1;
		while (++j < YWIN)
			my_mlx_pixel_put(&mats->img , i, j, 0x87CEEB);
	}
}