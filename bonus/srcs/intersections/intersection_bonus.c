/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:57:42 by revieira          #+#    #+#             */
/*   Updated: 2023/09/23 17:02:23 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_intersections	*hit(t_intersections *intersections)
{
	while (intersections)
	{
		if (intersections->t >= 0)
			return (intersections);
		intersections = intersections->next;
	}
	return (NULL);
}

t_intersections	*intersection_calculate(t_ray ray, t_hittable *objects)
{
	t_intersections	*intersect;

	intersect = NULL;
	while (objects)
	{
		if (objects->type == 1)
			hit_sp(ray, objects, &intersect);
		else if (objects->type == 2)
			hit_cy(ray, objects, &intersect);
		else if (objects->type == 3)
			hit_pl(ray, objects, &intersect);
		else
			hit_cone(ray, objects, &intersect);
		objects = objects->next;
	}
	sort_lst(&intersect);
	return (intersect);
}
