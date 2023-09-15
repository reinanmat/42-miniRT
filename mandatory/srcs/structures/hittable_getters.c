/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_getters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:13:46 by revieira          #+#    #+#             */
/*   Updated: 2023/09/15 19:18:42 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

t_color	get_color(t_hittable *object)
{
	if (object->type == 1)
		return (object->sp->material.color);
	else if (object->type == 2)
		return (object->cy->material.color);
	else
		return (object->pl->material.color);
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
	else
		return (object->pl->transform);
}

t_matrix	get_inv_transform(t_hittable *object)
{
	if (object->type == 1)
		return (object->sp->inv_transform);
	else if (object->type == 2)
		return (object->cy->inv_transform);
	else
		return (object->pl->inv_transform);
}
