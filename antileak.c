/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antileak.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:23:59 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/02 10:34:20 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_mats(t_fdf *mats)
{
	int 	i;
	i = 0;
	while (i < mats->area)
	{
		nml_mat_free(mats->vecs[i]);
		i++;
	}
	free(mats->vecs);
}