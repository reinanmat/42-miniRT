/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:12:22 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/12 17:59:05 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

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
