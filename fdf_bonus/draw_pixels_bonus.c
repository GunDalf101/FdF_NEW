/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:48:36 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/22 23:23:17 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_mlx_pixel_put(t_data *data, int xi, int yi, int color)
{
	char	*dst;

	dst = data->addr + (yi * data->line_length + \
	xi * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_x(t_fdf *mats)
{
	mats->drawer.x0 = mats->vecs[mats->drawer.i - 1]->data[X][0];
	mats->drawer.y0 = mats->vecs[mats->drawer.i - 1]->data[Y][0];
	mats->drawer.x1 = mats->vecs[mats->drawer.i]->data[X][0];
	mats->drawer.y1 = mats->vecs[mats->drawer.i]->data[Y][0];
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
		if (mats->origin->data[X][0] + mats->drawer.x0 > XWIN || mats->origin->\
		data[X][0] + mats->drawer.x0 < 0 || mats->origin->data[Y][0] - mats->\
		drawer.y0 < 0 || mats->origin->data[Y][0] - mats->drawer.y0 > YWIN)
			return ;
		colorseve(mats->color, mats);
		mats->drawer.x0 = mats->drawer.x0 + mats->drawer.xinc;
		mats->drawer.y0 = mats->drawer.y0 + mats->drawer.yinc;
	}
	if ((mats->drawer.i + 1) % mats->width == 0)
		mats->drawer.i++;
}

void	put_y(t_fdf *mats)
{
	mats->drawer.x1 = mats->vecs[mats->drawer.i - 1]->data[X][0];
	mats->drawer.y1 = mats->vecs[mats->drawer.i - 1]->data[Y][0];
	mats->drawer.x0 = mats->vecs[mats->drawer.i + mats->width - 1]->data[X][0];
	mats->drawer.y0 = mats->vecs[mats->drawer.i + mats->width - 1]->data[Y][0];
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
		if (mats->origin->data[X][0] + mats->drawer.x0 > XWIN || mats->origin->\
		data[X][0] + mats->drawer.x0 < 0 || mats->origin->data[Y][0] - mats->\
		drawer.y0 < 0 || mats->origin->data[Y][0] - mats->drawer.y0 > YWIN)
			return ;
		colorseve(mats->color, mats);
		mats->drawer.x0 = mats->drawer.x0 + mats->drawer.xinc;
		mats->drawer.y0 = mats->drawer.y0 + mats->drawer.yinc;
	}
}

void	backgroundc(t_fdf *mats)
{
	if (mats->background == 0)
		return ;
	else if (mats->background == 1)
		white_back(mats);
	else if (mats->background == 2)
		gimme_grey(mats);
	else if (mats->background == 3)
		sky_high(mats);
}

void	draw_frame(t_fdf *mats)
{
	mlx_destroy_image(mats->mlx, mats->img.img);
	mats->img.img = mlx_new_image(mats->mlx, XWIN, YWIN);
	mats->img.addr = mlx_get_data_addr(mats->img.img, &mats->img.\
	bits_per_pixel, &mats->img.line_length, &mats->img.endian);
	backgroundc(mats);
	mats->drawer.i = 0;
	while (++mats->drawer.i < mats->area)
		put_x(mats);
	mats->drawer.i = 0;
	while (++mats->drawer.i < mats->area - mats->width + 1)
		put_y(mats);
	mlx_put_image_to_window(mats->mlx, mats->win, mats->img.img, 0, 0);
	epic_spellbook(mats);
	mlx_string_put(mats->mlx, mats->win, 150, 437, \
	0xFF0000, "!! MORE FEATURES WILL BE ADDED NEXT RELEASE !!");
	mlx_string_put(mats->mlx, mats->win, XWIN - 300, \
	YWIN - 30, 0xFFFF00, "Y0U SHAAAALL N00T PAAASSS!!");
}
