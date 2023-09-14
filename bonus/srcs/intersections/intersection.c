/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:57:42 by revieira          #+#    #+#             */
/*   Updated: 2023/09/13 13:56:28 by revieira         ###   ########.fr       */
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

static void	hit_sp(t_ray ray, t_hittable *obj, t_intersections **inters)
{
	t_ray			tmp_ray;
	t_inter_point	inter_p;

	tmp_ray = transform_ray(ray, inverse(obj->sp->transform));
	inter_p = intersect_sphere(tmp_ray, obj->sp);
	if (inter_p.hit_times != 0)
	{
		intersect_add_back(inters, new_intersect(inter_p.hit[0], obj));
		intersect_add_back(inters, new_intersect(inter_p.hit[1], obj));
	}
}

static void	hit_cy(t_ray ray, t_hittable *obj, t_intersections **inters)
{
	t_ray			tmp_ray;
	t_inter_point	inter_p;

	tmp_ray = transform_ray(ray, inverse(obj->cy->transform));
	inter_p = intersect_cylinder(tmp_ray, obj->cy);
	if (inter_p.hit_times != 0)
	{
		intersect_add_back(inters, new_intersect(inter_p.hit[0], obj));
		intersect_add_back(inters, new_intersect(inter_p.hit[1], obj));
	}
}

static void	hit_pl(t_ray ray, t_hittable *obj, t_intersections **inters)
{
	t_ray			tmp_ray;
	t_inter_point	inter_p;

	tmp_ray = transform_ray(ray, inverse(obj->pl->transform));
	inter_p = intersect_plane(tmp_ray, obj->pl);
	if (inter_p.hit_times != 0)
		intersect_add_back(inters, new_intersect(inter_p.hit[0], obj));
}

static void	hit_cone(t_ray ray, t_hittable *obj, t_intersections **inters)
{
	t_ray			tmp_ray;
	t_inter_point	inter_p;

	tmp_ray = transform_ray(ray, inverse(obj->co->transform));
	inter_p = intersect_cone(tmp_ray, obj->co);
	if (inter_p.hit_times != 0)
	{
		intersect_add_back(inters, new_intersect(inter_p.hit[0], obj));
		intersect_add_back(inters, new_intersect(inter_p.hit[1], obj));
	}
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
