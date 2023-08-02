/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:57:03 by fnacarel          #+#    #+#             */
/*   Updated: 2023/08/02 18:31:34 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

int	minor(t_matrix a, int row, int col)
{
	t_matrix	sub;

	sub = submatrix(a, row, col);
	return (sub.matr[0][0] * sub.matr[1][1] - sub.matr[0][1] * sub.matr[1][0]);
}

int	cofactor(t_matrix a, int row, int col)
{
	if (a.rows == 4 && a.cols == 4)
	{
		a = submatrix(a, row, col);
		if ((row + col) % 2 != 0)
			return (-determinant(a));
		return (determinant(a));
	}
	if ((row + col) % 2 != 0)
		return (-minor(a, row, col));
	return (minor(a, row, col));
}

int	is_invertible(t_matrix a)
{
	int	det;

	det = determinant(a);
	if (det != 0)
		return (1);
	return (0);
}

int	determinant(t_matrix a)
{
	int	i;
	int	cof;
	int	det;

	i = -1;
	det = 0;
	while (++i < a.cols)
	{
		cof = cofactor(a, 0, i);
		det += a.matr[0][i] * cof;
	}
	return (det);
}
