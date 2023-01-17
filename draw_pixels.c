/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:48:36 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/17 16:02:01 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int xi, int yi, int color)
{
	char	*dst;

	dst = data->addr + (yi * data->line_length + xi * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void put_x(t_fdf *mats)
{
	mats->drawer.x0 = mats->vecs[mats->drawer.i - 1]->data[0][0];
	mats->drawer.y0 = mats->vecs[mats->drawer.i - 1]->data[1][0];
	mats->drawer.x1 = mats->vecs[mats->drawer.i]->data[0][0];
	mats->drawer.y1 = mats->vecs[mats->drawer.i]->data[1][0];
	mats->drawer.dx = mats->drawer.x1 - mats->drawer.x0;
	mats->drawer.dy = mats->drawer.y1 - mats->drawer.y0;
	if (fabs(mats->drawer.dx) > fabs(mats->drawer.dy))
		mats->drawer.step = fabs(mats->drawer.dx);
	else
		mats->drawer.step = fabs(mats->drawer.dy);
	mats->drawer.xinc = mats->drawer.dx / mats->drawer.step;
	mats->drawer.yinc = mats->drawer.dy / mats->drawer.step;
	mats->drawer.j = -1;
	while (++mats->drawer.j <= mats->drawer.step)
	{
		if(mats->origin->data[0][0] + mats->drawer.x0 > x || mats->origin->data[0][0] + mats->drawer.x0 < 0 || mats->origin->data[1][0] - mats->drawer.y0 < 0 || mats->origin->data[1][0] - mats->drawer.y0 > y)
			return ;
		colorseve(mats->color, mats);
		mats->drawer.x0 = mats->drawer.x0 + mats->drawer.xinc;
		mats->drawer.y0 = mats->drawer.y0 + mats->drawer.yinc;
	}
	if ((mats->drawer.i + 1) % mats->width == 0)
		mats->drawer.i++;
}

void put_y(t_fdf *mats)
{
	mats->drawer.x1 = mats->vecs[mats->drawer.i - 1]->data[0][0];
	mats->drawer.y1 = mats->vecs[mats->drawer.i - 1]->data[1][0];
	mats->drawer.x0 = mats->vecs[mats->drawer.i + mats->width - 1]->data[0][0];
	mats->drawer.y0 = mats->vecs[mats->drawer.i + mats->width - 1]->data[1][0];
	mats->drawer.dx = mats->drawer.x1 - mats->drawer.x0;
	mats->drawer.dy = mats->drawer.y1 - mats->drawer.y0;
	if (fabs(mats->drawer.dx) > fabs(mats->drawer.dy))
		mats->drawer.step = fabs(mats->drawer.dx);
	else
		mats->drawer.step = fabs(mats->drawer.dy);
	mats->drawer.xinc = mats->drawer.dx / mats->drawer.step;
	mats->drawer.yinc = mats->drawer.dy / mats->drawer.step;
	mats->drawer.j = -1;
	while (++mats->drawer.j <= mats->drawer.step)
	{
		if(mats->origin->data[0][0] + mats->drawer.x0 > x || mats->origin->data[0][0] + mats->drawer.x0 < 0 || mats->origin->data[1][0] - mats->drawer.y0 < 0 || mats->origin->data[1][0] - mats->drawer.y0 > y)
			return ;
		colorseve(mats->color, mats);
		mats->drawer.x0 = mats->drawer.x0 + mats->drawer.xinc;
		mats->drawer.y0 = mats->drawer.y0 + mats->drawer.yinc;
	}
}

void draw_frame(t_fdf *mats)
{
	mlx_destroy_image(mats->mlx, mats->img.img);
	mats->img.img = mlx_new_image(mats->mlx, x, y);
	mats->img.addr = mlx_get_data_addr(mats->img.img, &mats->img.bits_per_pixel, &mats->img.line_length,
								&mats->img.endian);
	mats->drawer.i = 0;
	while (++mats->drawer.i < mats->area)
		put_x(mats);
	mats->drawer.i = 0;
	while (++mats->drawer.i < mats->area - mats->width + 1)
		put_y(mats);
	mlx_put_image_to_window(mats->mlx, mats->win, mats->img.img, 0, 0);
}