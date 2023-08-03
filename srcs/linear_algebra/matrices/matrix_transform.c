/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:12:22 by fnacarel          #+#    #+#             */
/*   Updated: 2023/08/03 15:27:15 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt.h"

t_matrix	translation_matrix(t_point x)
{
	t_matrix	a;

	a = identity_matrix();
	a.matr[0][3] = x.x;
	a.matr[1][3] = x.y;
	a.matr[2][3] = x.z;
	return (a);
}

t_matrix	scaling_matrix(t_point x)
{
	t_matrix	a;

	a = identity_matrix();
	a.matr[0][0] = x.x;
	a.matr[1][1] = x.y;
	a.matr[2][2] = x.z;
	return (a);
}

t_matrix	shearing_matrix(t_point p1, t_point p2)
{
	t_matrix	a;

	a = identity_matrix();
	a.matr[0][1] = p1.x;
	a.matr[0][2] = p2.x;
	a.matr[1][0] = p1.y;
	a.matr[1][2] = p2.y;
	a.matr[2][0] = p1.z;
	a.matr[2][1] = p2.z;
	return (a);
}

t_matrix	rotate_x_matrix(double radians)
{
	t_matrix	a;

	a = identity_matrix();
	a.matr[1][1] = cos(radians);
	a.matr[1][2] = -sin(radians);
	a.matr[2][1] = sin(radians);
	a.matr[2][2] = cos(radians);
	return (a);
}

t_matrix	rotate_y_matrix(double radians)
{
	t_matrix	a;

	a = identity_matrix();
	a.matr[0][0] = cos(radians);
	a.matr[0][2] = sin(radians);
	a.matr[2][0] = -sin(radians);
	a.matr[2][2] = cos(radians);
	return (a);
}

t_matrix	rotate_z_matrix(double radians)
{
	t_matrix	a;

	a = identity_matrix();
	a.matr[0][0] = cos(radians);
	a.matr[0][1] = -sin(radians);
	a.matr[1][0] = sin(radians);
	a.matr[1][1] = cos(radians);
	return (a);
}
