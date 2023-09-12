/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:52:06 by revieira          #+#    #+#             */
/*   Updated: 2023/09/12 17:58:47 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt_bonus.h"

t_matrix	identity_matrix(void)
{
	t_matrix	matrix;

	matrix = (t_matrix){0};
	matrix.rows = 4;
	matrix.cols = 4;
	matrix.matr[0][0] = 1;
	matrix.matr[1][1] = 1;
	matrix.matr[2][2] = 1;
	matrix.matr[3][3] = 1;
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
