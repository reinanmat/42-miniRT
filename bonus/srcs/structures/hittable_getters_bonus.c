/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_getters_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:13:46 by revieira          #+#    #+#             */
/*   Updated: 2023/09/23 17:06:12 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_color	get_texture_color(t_texture t, t_point point)
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
		object_color = get_texture_color(material.texture, point);
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
