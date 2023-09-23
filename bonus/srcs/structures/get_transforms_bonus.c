/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_transforms_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:06:19 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/23 17:06:33 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_matrix	get_inv_transform(t_hittable *object)
{
	if (object->type == 1)
		return (object->sp->inv_transform);
	else if (object->type == 2)
		return (object->cy->inv_transform);
	else if (object->type == 3)
		return (object->pl->inv_transform);
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
	return (object->co->transform);
}
