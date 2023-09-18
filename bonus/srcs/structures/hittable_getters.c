/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_getters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:13:46 by revieira          #+#    #+#             */
/*   Updated: 2023/09/18 18:53:09 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_color	get_color_texture(t_texture t, t_point p)
{
	double	u;
	double	v;

	double theta = atan2(p.x, p.z);
	double radius = magnitude(p);
	double phi = acos(p.y / radius);

	double raw_u = theta / (2 * M_PI);

	u = 1 - (raw_u + 0.5);
	v = 1 - phi / M_PI;
	return (uv_pattern_at(t, u, v));
}

t_color	get_color(t_hittable *object, t_point point)
{
	t_color		object_color;
	t_material	m;
	t_matrix	inv_transform;

	m = get_material(object);
	return (get_color_texture(m.texture, point));
	if (m.has_pattern)
	{
		inv_transform = get_inv_transform(object);
		object_color = stripe_at_obj(m.pattern, inv_transform, point);
	}
	else
		object_color = m.color;
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
