/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:39:46 by revieira          #+#    #+#             */
/*   Updated: 2023/08/03 14:56:32 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

typedef struct s_matrix
{
	double	matr[4][4];
	int		rows;
	int		cols;
}	t_matrix;

int			is_invertible(t_matrix a);
double		determinant(t_matrix a);
double		minor(t_matrix a, int row, int col);
double		cofactor(t_matrix a, int row, int col);
t_matrix	inverse(t_matrix a);
t_matrix	submatrix(t_matrix a, int row, int col);
t_matrix	transpose_matrix(t_matrix a);
t_matrix	multiply_matrix(t_matrix a, t_matrix b);
t_matrix	identity_matrix(void);

#endif
