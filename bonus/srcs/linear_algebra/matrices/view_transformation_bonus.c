/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transformation_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:39:49 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/12 17:59:17 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

static void	set_values_on_given_col(t_matrix *matrix, int col, t_vec3 a)
{
	matrix->matr[col][0] = a.x;
	matrix->matr[col][1] = a.y;
	matrix->matr[col][2] = a.z;
}

t_matrix	view_transform(t_vec3 from, t_vec3 forward, t_vec3 up)
{
	t_vec3		left;
	t_vec3		true_up;
	t_vec3		negated_vec;
	t_matrix	orientation_matr;

	negated_vec = s_multiply(from, -1);
	orientation_matr = identity_matrix();
	left = cross_product(forward, normalize(up));
	true_up = cross_product(left, forward);
	set_values_on_given_col(&orientation_matr, 0, left);
	set_values_on_given_col(&orientation_matr, 1, true_up);
	set_values_on_given_col(&orientation_matr, 2, s_multiply(forward, -1));
	return (multiply_matrix(orientation_matr, translation_matrix(negated_vec)));
}
