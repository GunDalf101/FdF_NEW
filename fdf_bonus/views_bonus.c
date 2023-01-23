/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:53:06 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/22 23:23:04 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	isoview(int keycode, t_fdf *mats)
{
	if (keycode == 48)
	{
		mats->i->data[X][0] = (25.98 / RATIO) * mats->aaa / mats->bbb;
		mats->i->data[Y][0] = (-12.5 / RATIO) * mats->aaa / mats->bbb;
		mats->i->data[Z][0] = (-7.499966 / RATIO) * mats->aaa / mats->bbb;
		mats->j->data[X][0] = (-15.000000 / RATIO) * mats->aaa / mats->bbb;
		mats->j->data[Y][0] = (-22.500034 / RATIO) * mats->aaa / mats->bbb;
		mats->j->data[Z][0] = (-12.990321 / RATIO) * mats->aaa / mats->bbb;
		mats->k->data[X][0] = (0.000000 / RATIO) * mats->aaa / mats->bbb;
		mats->k->data[Y][0] = (2.499989 * ZRATIO / RATIO) * \
		mats->aaa / mats->bbb;
		mats->k->data[Z][0] = (-4.330134 * ZRATIO / RATIO) * \
		mats->aaa / mats->bbb;
		vector_trans(mats);
	}
	return (0);
}

int	xview(int keycode, t_fdf *mats)
{
	if (keycode == 7)
	{
		mats->i->data[X][0] = (30.0 / RATIO) * mats->aaa / mats->bbb;
		mats->i->data[Y][0] = 0;
		mats->i->data[Z][0] = 0;
		mats->j->data[X][0] = 0;
		mats->j->data[Y][0] = - (30.0 / RATIO) * mats->aaa / mats->bbb;
		mats->j->data[Z][0] = 0;
		mats->k->data[X][0] = 0;
		mats->k->data[Y][0] = 0;
		mats->k->data[Z][0] = - (5.0 * ZRATIO / RATIO) * mats->aaa / mats->bbb;
		vector_trans(mats);
	}
	return (0);
}

int	yview(int keycode, t_fdf *mats)
{
	if (keycode == 16)
	{
		mats->i->data[X][0] = (30.0 / RATIO) * mats->aaa / mats->bbb;
		mats->i->data[Y][0] = 0;
		mats->i->data[Z][0] = 0;
		mats->j->data[X][0] = 0;
		mats->j->data[Y][0] = 0;
		mats->j->data[Z][0] = (30.0 / RATIO) * mats->aaa / mats->bbb;
		mats->k->data[X][0] = 0;
		mats->k->data[Y][0] = (5.0 * ZRATIO / RATIO) * mats->aaa / mats->bbb;
		mats->k->data[Z][0] = 0;
		vector_trans(mats);
	}
	return (0);
}
