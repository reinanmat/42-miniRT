/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:05:42 by revieira          #+#    #+#             */
/*   Updated: 2023/09/04 14:32:16 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

static t_vec3	local_normal_at(t_hittable *object, t_point local_point)
{
	if (object->type == 1)
		return (sub(local_point, point(0, 0, 0)));
	else
		return (vec3(0, 1, 0));
}

t_vec3	normal_at(t_hittable *object, t_point world_point)
{
	t_matrix	inv_matrix;
	t_vec3		world_normal;
	t_point		object_point;
	t_vec3		object_normal;
	t_matrix	normal_as_matrix;

	inv_matrix = inverse(get_transform(object));
	object_point = matrix_to_point(multiply_matrix(inv_matrix, point_to_matrix(world_point)));
	object_normal = local_normal_at(object, object_point);
	normal_as_matrix = point_to_matrix(object_normal);
	world_normal = matrix_to_point(multiply_matrix(transpose_matrix(inv_matrix), normal_as_matrix));
	return (normalize(world_normal));
}
