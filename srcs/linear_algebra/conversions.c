/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:42:20 by fnacarel          #+#    #+#             */
/*   Updated: 2023/08/02 18:57:55 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

t_matrix	point_to_matrix(t_point point)
{
	t_matrix	a;

	a.rows = 4;
	a.cols = 1;
	a.matr[0][0] = point.x;
	a.matr[1][0] = point.y;
	a.matr[2][0] = point.z;
	a.matr[3][0] = 1;
	return (a);
}

t_point		matrix_to_point(t_matrix a)
{
	t_point	point;

	point.x = a.matr[0][0];
	point.y = a.matr[1][0];
	point.z = a.matr[2][0];
	return (point);
}
