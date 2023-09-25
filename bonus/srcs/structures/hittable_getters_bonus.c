/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_getters_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:13:46 by revieira          #+#    #+#             */
/*   Updated: 2023/09/25 15:08:04 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_color	get_texture_color(t_texture t, t_hittable *object, t_point point)
{
	t_matrix	object_point;
	t_point		texture_point;
	t_matrix	inv_transform;
	t_matrix	inv_by_obj_point;

	inv_transform = get_inv_transform(object);
	object_point = multiply_matrix(inv_transform, point_to_matrix(point));
	inv_by_obj_point = multiply_matrix(identity_matrix(), object_point);
	texture_point = matrix_to_point(inv_by_obj_point);
	if (object->type == 1)
		return (sphere_map(t, texture_point));
	else if (object->type == 3)
		return (plane_map(t, texture_point));
	else
		return (cylinder_and_cone_map(t, texture_point));
}

t_color	get_pattern_color(t_pattern p, t_hittable *object, t_point point)
{
	t_matrix	object_point;
	t_point		pattern_point;
	t_matrix	inv_transform;
	t_matrix	inv_by_obj_point;

	inv_transform = get_inv_transform(object);
	object_point = multiply_matrix(inv_transform, point_to_matrix(point));
	inv_by_obj_point = multiply_matrix(p.inv_transform, object_point);
	pattern_point = matrix_to_point(inv_by_obj_point);
	if (p.type == STRIPE_PATTERN)
		return (stripe_pattern(p, pattern_point));
	else if (p.type == GRADIENT_PATTERN)
		return (gradient_pattern(p, pattern_point));
	else if (p.type == RING_PATTERN)
		return (ring_pattern(p, pattern_point));
	else
		return (checkers_pattern(p, pattern_point));
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
