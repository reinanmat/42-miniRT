/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:57:42 by revieira          #+#    #+#             */
/*   Updated: 2023/08/30 21:18:33 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

t_intersections	*hit(t_intersections *intersections)
{
	double			min;
	t_intersections	*intersect;

	intersect = NULL;
	min = INFINITY;
	while (intersections)
	{
		if (intersections->t >= 0 && intersections->t < min)
		{
			intersect = intersections;
			min = intersect->t;
		}
		intersections = intersections->next;
	}
	return (intersect);
}

void	intersection(t_ray ray, t_hittable *obj, t_intersections **intersects)
{
	t_ray			tmp_ray;
	t_inter_point	inter_p;

	if (obj->type == 1)
	{
		tmp_ray = transform_ray(ray, inverse(obj->sp->transform));
		inter_p = intersect_sphere(tmp_ray, obj->sp);
		if (inter_p.hit_times != 0)
		{
			intersect_add_back(intersects, new_intersect(inter_p.hit[0], obj));
			intersect_add_back(intersects, new_intersect(inter_p.hit[1], obj));
		}
	}
}

t_intersections	*intersection_calculate(t_ray ray, t_hittable *objects)
{
	t_intersections	*intersect;

	intersect = NULL;
	while (objects)
	{
		intersection(ray, objects, &intersect);
		objects = objects->next;
	}
	sort_lst(&intersect);
	return (intersect);
}
