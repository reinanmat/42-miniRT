/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_getters_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:13:46 by revieira          #+#    #+#             */
/*   Updated: 2023/09/25 14:08:52 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_color	sphere_map(t_texture t, t_point point)
{
	double	u;
	double	v;
	double	radius;
	double	phi;
	double	raw_u;

	raw_u = atan2(point.x, point.z) / (2 * M_PI);
	radius = magnitude(point);
	phi = acos(point.y / radius);
	u = 1 - (raw_u + 0.5);
	v = 1 - phi / M_PI;
	return (uv_pattern_at(t, u, v));
}

t_color	 plane_map(t_texture t, t_point point)
{
	double u;
	double v;

	point.x = point.x - floor(point.x);
	point.z = point.z - floor(point.z);
	u = fmod(point.x, 1.0);
	v = fmod(point.z, 1.0);
	return (uv_pattern_at(t, u, v));
}

t_color	cylinder_map(t_texture t, t_point point)
{
	double	u;
	double	v;
	double	theta;
	double	raw_u;

	theta = atan2(point.x, point.z);
	raw_u = theta / (2 * M_PI);
	u = 1 - (raw_u + 0.5);
	point.y = point.y - floor(point.y);
	v = fmod(point.y, 1);
	return (uv_pattern_at(t, u, v));
}

t_color	get_texture_color(t_texture t, t_hittable *object, t_point point)
{
	t_matrix	object_point;
	t_point		texture_point;
	t_matrix	inv_by_obj_point;

	object_point = multiply_matrix(get_inv_transform(object), point_to_matrix(point));
	inv_by_obj_point = multiply_matrix(identity_matrix(), object_point);
	texture_point = matrix_to_point(inv_by_obj_point);
	if (object->type == 1)
		return (sphere_map(t, texture_point));
	else if (object->type == 2)
		return (cylinder_map(t, texture_point));
	else
		return (plane_map(t, texture_point));
}

t_color	get_pattern_color(t_pattern p, t_hittable *object, t_point point)
{
	t_matrix	inv_transform;

	inv_transform = get_inv_transform(object);
	return (stripe_at_obj(p, inv_transform, point));
}

t_color	get_color(t_hittable *object, t_point point)
{
	t_color		object_color;
	t_material	material;

	material = get_material(object);
	if (material.type_material == PATTERN)
		object_color = get_pattern_color(material.pattern, object, point);
	else if (material.type_material == TEXTURE)
		object_color = get_texture_color(material.texture, object, point);
	else
		object_color = material.color;
	return (object_color);
}

t_material	get_material(t_hittable *object)
{
	if (object->type == 1)
		return (object->sp->material);
	else if (object->type == 2)
		return (object->cy->material);
	else if (object->type == 3)
		return (object->pl->material);
	return (object->co->material);
}
