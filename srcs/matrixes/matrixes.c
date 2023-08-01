/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:57:03 by fnacarel          #+#    #+#             */
/*   Updated: 2023/08/01 16:41:39 by fnacarel         ###   ########.fr       */
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

int			determinant(t_matrix a);

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
	if (a.rows == 4 && a.cols == 4)
	{
		a = submatrix(a, row, col);
		if (row + col % 2 != 0)
			return (-determinant(a));
		return (determinant(a));
	}
	if (row + col % 2 != 0)
		return (-minor(a, row,col));
	return (minor(a, row, col));
}

int			determinant(t_matrix a)
{
	int	i;
	t_matrix	bla;
	int	det;

	i = 0;
	det = 0;
	while (i < a.cols)
	{
		if (a.rows == 4 && a.cols == 4)
		{
			bla = submatrix(a, 0, i);
			det += a.matr[0][i] * determinant(bla);
		}
		else
			det += a.matr[0][i] * cofactor(a, 0, i);
		i++;
	}
	return (det);
}

int main(void)
{
	t_matrix	matrix;
	t_matrix	matr2;

	matrix.matr[0][0] = 1;
	matrix.matr[0][1] = 2;
	matrix.matr[0][2] = 6;

	matrix.matr[1][0] = -5;
	matrix.matr[1][1] = 8;
	matrix.matr[1][2] = -4;

	matrix.matr[2][0] = 2;
	matrix.matr[2][1] = 6;
	matrix.matr[2][2] = 4;

	matrix.rows = 3;
	matrix.cols = 3;
	printf("---TEST 00----\n");
	printf("%d\n", cofactor(matrix, 0, 0));
	printf("%d\n", cofactor(matrix, 0, 1));
	printf("%d\n", cofactor(matrix, 0, 2));
	printf("determinant: %d\n", determinant(matrix));
	printf("\n\n");

	matr2.matr[0][0] = -2;
	matr2.matr[0][1] = -8;
	matr2.matr[0][2] = 3;
	matr2.matr[0][3] = 5;

	matr2.matr[1][0] = -3;
	matr2.matr[1][1] = 1;
	matr2.matr[1][2] = 7;
	matr2.matr[1][3] = 3;

	matr2.matr[2][0] = 1;
	matr2.matr[2][1] = 2;
	matr2.matr[2][2] = -9;
	matr2.matr[2][3] = 6;

	matr2.matr[3][0] = -6;
	matr2.matr[3][1] = 7;
	matr2.matr[3][2] = 7;
	matr2.matr[3][3] = -9;

	matr2.rows = 4;
	matr2.cols = 4;
	printf("---TEST 01----\n");
	printf("%d\n", cofactor(matr2, 0, 0));
	printf("%d\n", cofactor(matr2, 0, 1));
	printf("%d\n", cofactor(matr2, 0, 2));
	printf("%d\n", cofactor(matr2, 0, 3));
	printf("determinant: %d\n", determinant(matr2));
}
