/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:05:42 by revieira          #+#    #+#             */
/*   Updated: 2023/08/31 19:11:26 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

t_vec3	normal_at(t_hittable *object, t_point world_point)
{
	t_matrix	inv_matrix;
	t_vec3		world_normal;
	t_point		object_point;
	t_vec3		object_normal;
	t_matrix	normal_as_matrix;

	inv_matrix = inverse(get_transform(object));
	object_point = matrix_to_point(multiply_matrix(inv_matrix, point_to_matrix(world_point)));
	object_normal = sub(object_point, point(0, 0, 0));
	normal_as_matrix = point_to_matrix(object_normal);
	world_normal = matrix_to_point(multiply_matrix(transpose_matrix(inv_matrix), normal_as_matrix));
	return (normalize(world_normal));
}
