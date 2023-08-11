/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:57:04 by revieira          #+#    #+#             */
/*   Updated: 2023/08/11 19:07:05 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

t_matrix	multiply_matrix(t_matrix a, t_matrix b)
{
	int			i;
	int			j;
	t_matrix	c;

	i = 0;
	c.rows = a.rows;
	c.cols = b.cols;
	while (i < a.rows)
	{
		j = 0;
		while (j < b.cols)
		{
			c.matr[i][j] = (a.matr[i][0] * b.matr[0][j]) + \
					(a.matr[i][1] * b.matr[1][j]) + \
					(a.matr[i][2] * b.matr[2][j]) + \
					(a.matr[i][3] * b.matr[3][j]);
			j++;
		}
		i++;
	}
	return (c);
}

t_matrix	inverse(t_matrix a)
{
	int			i;
	int			j;
	double		det;
	double		cof;
	t_matrix	a_inv;

	i = -1;
	det = determinant(a);
	a_inv.rows = a.rows;
	a_inv.cols = a.cols;
	while (++i < a.rows)
	{
		j = -1;
		while (++j < a.cols)
		{
			cof = cofactor(a, i, j);
			a_inv.matr[j][i] = ((double) cof) / det;
		}
	}
	return (a_inv);
}

t_matrix	transpose_matrix(t_matrix a)
{
	int			i;
	int			j;
	t_matrix	t_a;

	i = 0;
	t_a.rows = a.rows;
	t_a.cols = a.cols;
	while (i < a.rows)
	{
		j = 0;
		while (j < a.cols)
		{
			t_a.matr[i][j] = a.matr[j][i];
			j++;
		}
		i++;
	}
	return (t_a);
}
