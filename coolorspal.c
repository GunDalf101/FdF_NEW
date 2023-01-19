/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coolorspal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:00:10 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/19 11:32:39 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void earth(t_fdf *mats)
{
	if (mats->vecs[mats->drawer.i]->data[2][0] < 4)
		my_mlx_pixel_put(&mats->img ,	mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0x2B65EC);
	else if (mats->vecs[mats->drawer.i]->data[2][0] >= 4 && mats->vecs[mats->drawer.i]->data[2][0] < 10)
		my_mlx_pixel_put(&mats->img ,	mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0xEDB32B);
	else if (mats->vecs[mats->drawer.i]->data[2][0] >= 5 && mats->vecs[mats->drawer.i]->data[2][0] < 100)
		my_mlx_pixel_put(&mats->img ,	mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0x00FF00);
	else
		my_mlx_pixel_put(&mats->img ,	mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0xfffafa);
}

void red_green(t_fdf *mats)
{
	if (mats->vecs[mats->drawer.i]->data[2][0] <= 0)
		my_mlx_pixel_put(&mats->img ,	mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0x00FF00);
	else
		my_mlx_pixel_put(&mats->img ,	mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0xFF0000);
}

void scorched_earth(t_fdf *mats)
{
	if (mats->vecs[mats->drawer.i]->data[2][0] < -250)
		my_mlx_pixel_put(&mats->img ,	mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0x860111);
	else if (mats->vecs[mats->drawer.i]->data[2][0] >= -250 && mats->vecs[mats->drawer.i]->data[2][0] < 4)
		my_mlx_pixel_put(&mats->img ,	mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0xFFD729);
	else if (mats->vecs[mats->drawer.i]->data[2][0] >= 4 && mats->vecs[mats->drawer.i]->data[2][0] < 50)
		my_mlx_pixel_put(&mats->img ,	mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0xFF4605);
	else if (mats->vecs[mats->drawer.i]->data[2][0] >= 100 && mats->vecs[mats->drawer.i]->data[2][0] < 250)
		my_mlx_pixel_put(&mats->img ,	mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0xF8A42F);
	else if (mats->vecs[mats->drawer.i]->data[2][0] >= 250 && mats->vecs[mats->drawer.i]->data[2][0] < 500)
		my_mlx_pixel_put(&mats->img ,	mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0xd25930);
	else
		my_mlx_pixel_put(&mats->img ,	mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0xFCFF4A);
}

void castelvania(t_fdf *mats)
{
	if (mats->vecs[mats->drawer.i]->data[2][0] < 4)
		my_mlx_pixel_put(&mats->img ,	mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0x880000);
	else if (mats->vecs[mats->drawer.i]->data[2][0] >= 4 && mats->vecs[mats->drawer.i]->data[2][0] < 50)
		my_mlx_pixel_put(&mats->img ,	mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0x443333);
	else if (mats->vecs[mats->drawer.i]->data[2][0] >= 100 && mats->vecs[mats->drawer.i]->data[2][0] < 250)
		my_mlx_pixel_put(&mats->img ,	mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0x665566);
	else if (mats->vecs[mats->drawer.i]->data[2][0] >= 250 && mats->vecs[mats->drawer.i]->data[2][0] < 500)
		my_mlx_pixel_put(&mats->img ,	mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0x554444);
	else
		my_mlx_pixel_put(&mats->img ,	mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0x99AAAA);
}
