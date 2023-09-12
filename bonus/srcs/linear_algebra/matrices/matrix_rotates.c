/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:37:37 by revieira          #+#    #+#             */
/*   Updated: 2023/09/12 17:59:00 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt_bonus.h"

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
