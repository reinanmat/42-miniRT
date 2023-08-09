/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:05:47 by fnacarel          #+#    #+#             */
/*   Updated: 2023/08/08 18:20:30 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

void	apply_transformation_point(t_point *pos, t_matrix transformation)
{
	t_point		new_pos;
	t_matrix	applied;
	t_matrix	m_point;

	m_point = point_to_matrix(*pos);
	applied = multiply_matrix(transformation, m_point);
	new_pos = point(applied.matr[0][0], applied.matr[1][0], applied.matr[2][0]);
	*pos = new_pos;
}

void	apply_transformation_vec(t_vec3 *vec, t_matrix transformation)
{
	t_point		new_pos;
	t_matrix	applied;
	t_matrix	m_point;

	m_point = vec3_to_matrix(*vec);
	applied = multiply_matrix(transformation, m_point);
	new_pos = point(applied.matr[0][0], applied.matr[1][0], applied.matr[2][0]);
	*vec = new_pos;
}
