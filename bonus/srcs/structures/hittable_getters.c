/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_getters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:13:46 by revieira          #+#    #+#             */
/*   Updated: 2023/09/20 15:44:37 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_color	get_texture_color(t_texture t, t_point point)
{
	double	u;
	double	v;

	double theta = atan2(point.x, point.z);
	double radius = magnitude(point);
	double phi = acos(point.y / radius);

	double raw_u = theta / (2 * M_PI);

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
	else
		return (object->co->material);
}

t_matrix	get_inv_transform(t_hittable *object)
{
	if (object->type == 1)
		return (object->sp->inv_transform);
	else if (object->type == 2)
		return (object->cy->inv_transform);
	else if (object->type == 3)
		return (object->pl->inv_transform);
	else
		return (object->co->inv_transform);
}

t_matrix	get_transform(t_hittable *object)
{
	if (object->type == 1)
		return (object->sp->transform);
	else if (object->type == 2)
		return (object->cy->transform);
	else if (object->type == 3)
		return (object->pl->transform);
	else
		return (object->co->transform);
}
