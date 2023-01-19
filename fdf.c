/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 06:00:06 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/19 11:23:33 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int changeback(int keycode,t_fdf *mats)
{
	if	(keycode == 82)
		mats->background = 0;
	else if(keycode == 83)
		mats->background = 1;
	else if (keycode == 84)
		mats->background = 2;
	else if (keycode == 85)
		mats->background = 3;
	return (keycode);
}

int colorseve(int keycode,t_fdf *mats)
{
	mats->color = keycode;
	if	(keycode == 18)
		my_mlx_pixel_put(&mats->img , mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0xfffafa);
	else if(keycode == 19)
		red_green(mats);
	else if (keycode == 20)
		earth(mats);
	else if (keycode == 21)
		scorched_earth(mats);
	else if (keycode == 22)
		my_mlx_pixel_put(&mats->img , mats->origin->data[0][0] + mats->drawer.x0, mats->origin->data[1][0] - mats->drawer.y0 , 0x000000);
	else if (keycode == 23)
		castelvania(mats);
	return (keycode);
}

int key_hooks(int keycode, t_fdf *mats)
{
	if (keycode == 13 || keycode == 1)
		rotationx(keycode, mats);
	if (keycode == 2 || keycode == 0)
		rotationy(keycode, mats);
	if (keycode == 14 || keycode == 12)
		rotationz(keycode, mats);
	if (keycode >= 123 && keycode <= 126)
		translation(keycode, mats);
	if (keycode == 6 || keycode == 8)
		zoom(keycode, mats);
	if (keycode == 48)
		isoview(keycode, mats);
	if (keycode == 7)
		xview(keycode, mats);
	if (keycode == 16)
		yview(keycode, mats);
	if (keycode > 81 && keycode <= 89)
		changeback(keycode, mats);	
	if (keycode > 17 && keycode < 24)
		colorseve(keycode, mats);
	if (keycode == 53)
		exit (0);
	vector_trans(mats);
	draw_frame(mats);
	return (0);
}

void val_init(t_fdf *mats)
{
	maps_dims(mats);
	mats->background = 0; 
	mats->color = 18;
	mats->area = mats->width * mats->height;
	mats->origin = nml_mat_new(3, 1);
	mats->i = nml_mat_new(3, 1);
	mats->j = nml_mat_new(3, 1);
	mats->k = nml_mat_new(3, 1);
	mats->origin->data[0][0] = XWIN / 2;
	mats->origin->data[1][0] = YWIN / 2;
	mats->origin->data[2][0] = 0;
	mats->A = XWIN;
	mats->B = mats->width;
	if (XWIN > YWIN)
		mats->A = YWIN;
	if(mats->width < mats->height)
		mats->B = mats->height;
	rotx_init(mats);
	roty_init(mats);
	rotz_init(mats);
}

int main (int ac, char **av)
{
	t_fdf		mats;

	if(ac == 2)
	{
		mats.fd = open(av[1], O_RDONLY, 777);
		if (mats.fd == -1)
			return (ft_printf("Error 1: File Error\n"), 1);
		mats.mlx = mlx_init();
		mats.win =  mlx_new_window(mats.mlx, XWIN, YWIN, "EPIC 3D PROJECT");
		mats.img.img = mlx_new_image(mats.mlx, XWIN, YWIN);
		mats.img.addr = mlx_get_data_addr(mats.img.img, &mats.img.bits_per_pixel, 
								&mats.img.line_length, &mats.img.endian);
		val_init(&mats);
		close(mats.fd);
		mats.fd = open(av[1], O_RDONLY, 777);
		mats.map = map_reader(&mats);
		mats.vecs = vector_maker(&mats);
		isoview(48, &mats);
		draw_frame(&mats);
		mlx_hook(mats.win, 2, 0, key_hooks, &mats);
		close(mats.fd);
		mlx_loop(mats.mlx);
	}
	return (0);
}
