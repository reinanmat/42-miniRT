/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:57:42 by revieira          #+#    #+#             */
/*   Updated: 2023/08/11 15:03:57 by revieira         ###   ########.fr       */
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
			intersect = intersections;
		intersections = intersections->next;
	}
	return (intersect);
}

void	intersection_calculate(t_ray ray, t_hittable *objects, t_intersections **intersect)
{
	t_ray			tmp_ray;
	t_inter_point	inter_p;

	while (objects)
	{
		if (objects->type == 1)
		{
			tmp_ray = transform_ray(ray, inverse(objects->sp->transform));
			inter_p = intersect_sphere(tmp_ray, objects->sp);
			if (inter_p.hit_times != 0)
			{
				intersect_add_back(intersect, new_intersect(inter_p.hit[0], objects));
				intersect_add_back(intersect, new_intersect(inter_p.hit[1], objects));
			}
		}
		objects = objects->next;
	}
}
