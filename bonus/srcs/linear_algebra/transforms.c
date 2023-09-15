/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:05:47 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/15 20:25:19 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

static void	apply_transformation_point(t_point *pos, t_matrix transformation)
{
	t_point		new_pos;
	t_matrix	applied;
	t_matrix	m_point;

	m_point = point_to_matrix(*pos);
	applied = multiply_matrix(transformation, m_point);
	new_pos = point(applied.matr[0][0], applied.matr[1][0], applied.matr[2][0]);
	*pos = new_pos;
}

static void	apply_transformation_vec(t_vec3 *vec, t_matrix transformation)
{
	t_point		new_pos;
	t_matrix	applied;
	t_matrix	m_vec;

	m_vec = vec3_to_matrix(*vec);
	applied = multiply_matrix(transformation, m_vec);
	new_pos = point(applied.matr[0][0], applied.matr[1][0], applied.matr[2][0]);
	*vec = new_pos;
}

t_matrix	transform_object(t_point translation, t_vec3 scale)
{
	t_matrix	transform;
	t_matrix	m_scale;
	t_matrix	m_translation;

	m_scale = scaling_matrix(scale);
	m_translation = translation_matrix(translation);
	transform = multiply_matrix(m_translation, m_scale);
	return (transform);
}

t_ray	transform_ray(t_ray	ray, t_matrix transform)
{
	t_ray	new_ray;

	new_ray = ray;
	apply_transformation_point(&new_ray.origin, transform);
	apply_transformation_vec(&new_ray.direction, transform);
	return (new_ray);
}
