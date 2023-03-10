/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:45:14 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/22 23:23:12 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	maps_dims(t_fdf *mats)
{
	char	*line;
	char	**line2d;
	int		i;

	mats->width = 0;
	mats->height = 0;
	line = get_next_line(mats->fd);
	line2d = ft_split (line, ' ');
	while (line2d[mats->width])
		mats->width++;
	while (line)
	{
		free(line);
		line = get_next_line(mats->fd);
		i = -1;
		while (line2d[++i])
			free(line2d[i]);
		if (i != mats->width)
			return (ft_printf("Error 2: Inconsistent Dimensions"), exit(1));
		free(line2d);
		line2d = ft_split (line, ' ');
		mats->height++;
	}
}

int	**map_reader(t_fdf *mats)
{
	char	*line;
	char	**line2d;
	int		**map;
	int		i;
	int		j;

	line = get_next_line(mats->fd);
	line2d = ft_split (line, ' ');
	map = ft_calloc(mats->height, sizeof(int *));
	i = -1;
	while (line)
	{
		j = -1;
		map[++i] = ft_calloc(mats->width, sizeof(int));
		while (++j < mats->width)
		{
			map[i][j] = ft_atoi(line2d[j]);
			free(line2d[j]);
		}
		free(line);
		line = get_next_line(mats->fd);
		free(line2d);
		line2d = ft_split (line, ' ');
	}
	return (map);
}

t_nml_mat	**vector_maker(t_fdf *mats)
{
	t_nml_mat	**vectors;
	int			i;
	int			j;

	vectors = ft_calloc(mats->area, sizeof(t_nml_mat *));
	i = 0;
	while (i < mats->height)
	{
		j = 0;
		while (j < mats->width)
		{
			vectors[i * mats->width + j] = nml_mat_new(3, 1);
			vectors[i * mats->width + j]->data[X][0] = j * mats->i->data[X][0] \
			+ i * mats->j->data[X][0] + mats->map[i][j] * mats->k->data[X][0];
			vectors[i * mats->width + j]->data[Y][0] = j * mats->i->data[Y][0] \
			+ i * mats->j->data[Y][0] + mats->map[i][j] * mats->k->data[Y][0];
			vectors[i * mats->width + j]->data[Z][0] = mats->map[i][j];
			j++;
		}
		i++;
	}
	return (vectors);
}

void	vector_trans(t_fdf *mats)
{
	int		i;
	int		j;

	i = 0;
	while (i < mats->height)
	{
		j = 0;
		while (j < mats->width)
		{
			mats->vecs[i * mats->width + j]->data[X][0] = (j - mats->\
			width / 2) * mats->i->data[X][0] + (i - mats->height / 2) * \
			mats->j->data[X][0] + mats->map[i][j] * mats->k->data[X][0];
			mats->vecs[i * mats->width + j]->data[Y][0] = (j - mats->\
			width / 2) * mats->i->data[Y][0] + (i - mats->height / 2) * \
			mats->j->data[Y][0] + mats->map[i][j] * mats->k->data[Y][0];
			mats->vecs[i * mats->width + j]->data[Z][0] = mats->map[i][j];
			j++;
		}
		i++;
	}
}
