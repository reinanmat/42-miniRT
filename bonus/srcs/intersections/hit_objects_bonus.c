/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_objects_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:02:37 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/23 17:03:00 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

void	hit_sp(t_ray ray, t_hittable *obj, t_intersections **inters)
{
	t_ray			tmp_ray;
	t_inter_point	inter_p;

	tmp_ray = transform_ray(ray, obj->sp->inv_transform);
	inter_p = intersect_sphere(tmp_ray, obj->sp);
	if (inter_p.hit_times != 0)
	{
		intersect_add_back(inters, new_intersect(inter_p.hit[0], obj));
		intersect_add_back(inters, new_intersect(inter_p.hit[1], obj));
	}
}

void	hit_cy(t_ray ray, t_hittable *obj, t_intersections **inters)
{
	t_ray			tmp_ray;
	t_inter_point	inter_p;

	tmp_ray = transform_ray(ray, obj->cy->inv_transform);
	inter_p = intersect_cylinder(tmp_ray, obj->cy);
	if (inter_p.hit_times != 0)
	{
		intersect_add_back(inters, new_intersect(inter_p.hit[0], obj));
		intersect_add_back(inters, new_intersect(inter_p.hit[1], obj));
	}
}

void	hit_pl(t_ray ray, t_hittable *obj, t_intersections **inters)
{
	t_ray			tmp_ray;
	t_inter_point	inter_p;

	tmp_ray = transform_ray(ray, obj->pl->inv_transform);
	inter_p = intersect_plane(tmp_ray, obj->pl);
	if (inter_p.hit_times != 0)
		intersect_add_back(inters, new_intersect(inter_p.hit[0], obj));
}

void	hit_cone(t_ray ray, t_hittable *obj, t_intersections **inters)
{
	t_ray			tmp_ray;
	t_inter_point	inter_p;

	tmp_ray = transform_ray(ray, obj->co->inv_transform);
	inter_p = intersect_cone(tmp_ray, obj->co);
	if (inter_p.hit_times != 0)
	{
		intersect_add_back(inters, new_intersect(inter_p.hit[0], obj));
		intersect_add_back(inters, new_intersect(inter_p.hit[1], obj));
	}
}
