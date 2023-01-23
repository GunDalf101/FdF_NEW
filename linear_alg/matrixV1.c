/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixV1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:13:46 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/22 04:42:19 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_alg.h"

t_nml_mat	*nml_mat_new(unsigned int num_rows, unsigned int num_cols)
{
	int			i;
	t_nml_mat	*mat;

	i = 0;
	mat = ft_calloc(1, sizeof(*mat));
	mat->num_rows = num_rows;
	mat->num_cols = num_cols;
	if (num_rows == num_cols)
		mat->is_square = 1;
	else
		mat->is_square = 1;
	mat->data = ft_calloc(mat->num_rows, sizeof(*mat->data));
	while (i < mat->num_rows)
	{
		mat->data[i] = ft_calloc(mat->num_cols, sizeof(**mat->data));
		i++;
	}
	return (mat);
}

void	nml_mat_free(t_nml_mat *matrix)
{
	int	i;

	i = 0;
	while (i < matrix->num_rows)
	{
		free(matrix->data[i]);
		i++;
	}
	free(matrix->data);
	free(matrix);
}

void	nml_mat_printf(t_nml_mat *matrix)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("\n");
	while (i < matrix->num_rows)
	{
		while (j < matrix->num_cols)
		{
			ft_printf("%lf ", matrix->data[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

t_nml_mat	*nml_mat_cp(t_nml_mat *matrix)
{
	int			i;
	int			j;
	t_nml_mat	*r;

	i = 0;
	j = 0;
	r = nml_mat_new(matrix->num_rows, matrix->num_cols);
	while (i < matrix->num_rows)
	{
		while (j < matrix->num_cols)
		{
			r->data[i][j] = matrix->data[i][j];
			j++;
		}
		i++;
	}
	return (r);
}
