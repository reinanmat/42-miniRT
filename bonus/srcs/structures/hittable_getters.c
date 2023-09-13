/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_getters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:13:46 by revieira          #+#    #+#             */
/*   Updated: 2023/09/13 16:08:54 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_color	get_color(t_hittable *object, t_point point)
{
	t_color		object_color;
	t_material	m;
	
	m = get_material(object);
	if (m.has_pattern)
		object_color = stripe_at(m.pattern, point);
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
	else
		return (object->pl->material);
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
