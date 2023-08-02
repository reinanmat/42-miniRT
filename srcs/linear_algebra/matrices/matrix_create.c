/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:52:06 by revieira          #+#    #+#             */
/*   Updated: 2023/08/02 18:31:19 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

t_matrix	identity_matrix(void)
{
	int			i;
	int			j;
	t_matrix	matrix;

	matrix.rows = 4;
	matrix.cols = 4;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix.matr[i][j] = 0;
			if (i == j)
				matrix.matr[i][j] = 1;
			j++;
		}
		i++;
	}
	return (matrix);
}

t_matrix	submatrix(t_matrix a, int row, int col)
{
	int			i;
	int			j;
	int			k;
	int			l;
	t_matrix	s_a;

	s_a.rows = a.rows - 1;
	s_a.cols = a.cols - 1;
	k = 0;
	i = -1;
	while (++i < a.rows)
	{
		l = 0;
		j = -1;
		if (i == row)
			continue ;
		while (++j < a.cols)
		{
			if (j == col)
				continue ;
			s_a.matr[k][l++] = a.matr[i][j];
		}
		k++;
	}
	return (s_a);
}
