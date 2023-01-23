/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:33:38 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/22 23:22:46 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	rotationx(int keycode, t_fdf *mats)
{
	t_nml_mat	*tempi;
	t_nml_mat	*tempj;
	t_nml_mat	*tempk;

	mats->angle += M_PI;
	if (keycode == 13)
		mats->angle = -ROTANGLE;
	if (keycode == 1)
		mats->angle = ROTANGLE;
	rotx_init(mats);
	tempi = nml_mat_dot(mats->rotmatx, mats->i);
	tempj = nml_mat_dot(mats->rotmatx, mats->j);
	tempk = nml_mat_dot(mats->rotmatx, mats->k);
	mats->angle -= 3.14159;
	mats->i = tempi;
	mats->j = tempj;
	mats->k = tempk;
	return (0);
}

int	rotationy(int keycode, t_fdf *mats)
{
	t_nml_mat	*tempi;
	t_nml_mat	*tempj;
	t_nml_mat	*tempk;

	if (keycode == 2)
		mats->angle = -ROTANGLE;
	if (keycode == 0)
		mats->angle = ROTANGLE;
	roty_init(mats);
	tempi = nml_mat_dot(mats->rotmaty, mats->i);
	tempj = nml_mat_dot(mats->rotmaty, mats->j);
	tempk = nml_mat_dot(mats->rotmaty, mats->k);
	mats->i = tempi;
	mats->j = tempj;
	mats->k = tempk;
	return (0);
}

int	rotationz(int keycode, t_fdf *mats)
{
	t_nml_mat	*tempi;
	t_nml_mat	*tempj;
	t_nml_mat	*tempk;

	if (keycode == 12)
		mats->angle = -ROTANGLE;
	if (keycode == 14)
		mats->angle = ROTANGLE;
	rotz_init(mats);
	tempi = nml_mat_dot(mats->rotmatz, mats->i);
	tempj = nml_mat_dot(mats->rotmatz, mats->j);
	tempk = nml_mat_dot(mats->rotmatz, mats->k);
	mats->i = tempi;
	mats->j = tempj;
	mats->k = tempk;
	return (0);
}

int	translation(int keycode, t_fdf *mats)
{
	if (keycode == 125)
		mats->origin->data[Y][0] -= TRANSLATION;
	if (keycode == 126)
		mats->origin->data[Y][0] += TRANSLATION;
	if (keycode == 123)
		mats->origin->data[X][0] += TRANSLATION;
	if (keycode == 124)
		mats->origin->data[X][0] -= TRANSLATION;
	return (0);
}

int	zoom(int keycode, t_fdf *mats)
{
	int	i;

	i = 0;
	if (keycode == 6)
	{
		while (i < 3)
		{
			mats->i->data[i][0] *= ZOOM;
			mats->j->data[i][0] *= ZOOM;
			mats->k->data[i][0] *= ZOOM;
			i++;
		}
	}
	i = 0;
	if (keycode == 8)
	{
		while (i < 3)
		{
			mats->i->data[i][0] /= ZOOM;
			mats->j->data[i][0] /= ZOOM;
			mats->k->data[i][0] /= ZOOM;
			i++;
		}
	}
	return (0);
}
