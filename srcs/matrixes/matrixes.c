/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:57:03 by fnacarel          #+#    #+#             */
/*   Updated: 2023/08/01 13:56:14 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

typedef struct s_matrix
{
	double	matr[4][4];
	int		rows;
	int		cols;
}	t_matrix;

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

int			minor(t_matrix a, int row, int col)
{
	t_matrix	sub;

	sub = submatrix(a, row, col);
	return (sub.matr[0][0] * sub.matr[1][1] - sub.matr[0][1] * sub.matr[1][0]);
}

t_matrix	transpose_matrix(t_matrix a)
{
	int			i;
	int			j;
	t_matrix	t_a;

	i = 0;
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

void	print_matrix(double matrix[4][4])
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("| ");
			printf("%d\t", (int)matrix[i][j]);
		}
		printf("|\n");
	}
}

void	print_matrix2(t_matrix matrix)
{
	for (int i = 0; i < matrix.rows; ++i) {
		for (int j = 0; j < matrix.cols; ++j) {
			printf("|\t");
			printf("%d\t", (int)(matrix.matr[i][j]));
		}
		printf("|\n");
	}
}

t_matrix	multiply_matrix(t_matrix a, t_matrix b)
{
	int			i;
	int			j;
	t_matrix	c;

	i = 0;
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

int	cofactor(t_matrix a, int row, int col)
{
	if (row + col % 2 == 0)
		return (minor(a, row, col));
	return (-minor(a, row,col));
}

int main(void)
{
	t_matrix	matrix;

	matrix.matr[0][0] = 3;
	matrix.matr[0][1] = 5;
	matrix.matr[0][2] = 0;

	matrix.matr[1][0] = 2;
	matrix.matr[1][1] = -1;
	matrix.matr[1][2] = -7;

	matrix.matr[2][0] = 6;
	matrix.matr[2][1] = -1;
	matrix.matr[2][2] = 5;

	matrix.rows = 3;
	matrix.cols = 3;
	printf("%d\n", cofactor(matrix, 0, 0));
	printf("%d\n", cofactor(matrix, 1, 0));
}
