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
