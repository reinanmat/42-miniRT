/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_getters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:13:46 by revieira          #+#    #+#             */
/*   Updated: 2023/09/14 13:34:15 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_color	get_color(t_hittable *object)
{
	if (object->type == 1)
		return (object->sp->material.color);
	else if (object->type == 2)
		return (object->cy->material.color);
	else if (object->type == 3)
		return (object->pl->material.color);
	else
		return (object->co->material.color);
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
