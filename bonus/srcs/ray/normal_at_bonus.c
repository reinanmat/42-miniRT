/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:05:42 by revieira          #+#    #+#             */
/*   Updated: 2023/09/19 16:14:05 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

static t_vec3	local_normal_cylinder(t_cylinder *cylinder, t_point local_point)
{
	double	distance;

	distance = local_point.x * local_point.x + local_point.z * local_point.z;
	if (distance < 1 && local_point.y >= cylinder->max - EPSILON)
		return (vec3(0, 1, 0));
	else if (distance < 1 && local_point.y <= cylinder->min + EPSILON)
		return (vec3(0, -1, 0));
	else
		return (vec3(local_point.x, 0, local_point.z));
}

static t_vec3	local_normal_cone(t_point local_point)
{
	double	y;
	double	squared_x;
	double	squared_z;

	squared_x = local_point.x * local_point.x;
	squared_z = local_point.z * local_point.z;
	y = sqrt(squared_x + squared_z);
	if (local_point.y > 0)
		y *= -1;
	return (vec3(local_point.x, y, local_point.z));
}

t_vec3	local_normal_at(t_hittable *object, t_point local_point)
{
	if (object->type == 1)
		return (sub(local_point, point(0, 0, 0)));
	else if (object->type == 2)
		return (local_normal_cylinder(object->cy, local_point));
	else if (object->type == 3)
		return (vec3(0, 1, 0));
	else
		return (local_normal_cone(local_point));
}

t_point	get_object_point(t_matrix inv_matrix, t_point world_point)
{
	t_point		object_point;
	t_matrix	world_point_matrix;
	t_matrix	inv_by_world_point;

	world_point_matrix = point_to_matrix(world_point);
	inv_by_world_point = multiply_matrix(inv_matrix, world_point_matrix);
	object_point = matrix_to_point(inv_by_world_point);
	return (object_point);
}

t_vec3	get_world_normal(t_matrix inv_matrix, t_matrix normal_as_matrix)
{
	t_matrix	transposed_matrix;
	t_matrix	transpose_by_normal;
	t_vec3		world_normal;

	transposed_matrix = transpose_matrix(inv_matrix);
	transpose_by_normal = multiply_matrix(transposed_matrix, normal_as_matrix);
	world_normal = matrix_to_point(transpose_by_normal);
	return (world_normal);
}

t_vec3	normal_at(t_hittable *object, t_point world_point)
{
	t_matrix	inv_matrix;
	t_vec3		world_normal;
	t_point		object_point;
	t_vec3		object_normal;
	t_matrix	normal_as_matrix;

	inv_matrix = get_inv_transform(object);
	object_point = get_object_point(inv_matrix, world_point);
	object_normal = local_normal_at(object, object_point);
	normal_as_matrix = point_to_matrix(object_normal);
	world_normal = get_world_normal(inv_matrix, normal_as_matrix);
	return (normalize(world_normal));
}
