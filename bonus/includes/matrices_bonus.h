/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:39:46 by revieira          #+#    #+#             */
/*   Updated: 2023/09/12 17:41:47 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_BONUS_H
# define MATRICES_BONUS_H

# include "vec3_bonus.h"

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
t_matrix	point_to_matrix(t_point point);
t_matrix	vec3_to_matrix(t_vec3 vec);
t_point		matrix_to_point(t_matrix a);

//matrices transforms
t_matrix	transform_object(t_point translation, t_vec3 scale);
t_matrix	translation_matrix(t_point x);
t_matrix	scaling_matrix(t_point x);
t_matrix	shearing_matrix(t_point p1, t_point p2);
t_matrix	rotate_x_matrix(double radians);
t_matrix	rotate_y_matrix(double radians);
t_matrix	rotate_z_matrix(double radians);
t_matrix	view_transform(t_vec3 from, t_vec3 to, t_vec3 up);

#endif
