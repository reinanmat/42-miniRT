/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:58:52 by revieira          #+#    #+#             */
/*   Updated: 2023/08/21 18:53:10 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

static t_bhask	calculate_bhaskara(t_ray ray, t_sphere *sphere)
{
	double	root;
	t_bhask	bhask;
	t_vec3	point_to_sphere;

	point_to_sphere = sub(ray.origin, sphere->center);
	bhask.a = dot(ray.direction, ray.direction);
	bhask.b = 2 * dot(ray.direction, point_to_sphere);
	bhask.c = dot(point_to_sphere, point_to_sphere) - 1;
	bhask.discriminant = (bhask.b * bhask.b) - 4 * bhask.a * bhask.c;
	if (bhask.discriminant < 0)
		return (bhask);
	root = sqrt(bhask.discriminant);
	bhask.s1 = (-bhask.b - root) / (2 * bhask.a);
	bhask.s2 = (-bhask.b + root) / (2 * bhask.a);
	return (bhask);
}

t_inter_point	intersect_sphere(t_ray ray, t_sphere *sphere)
{
	t_inter_point	intersect;
	t_bhask			bhask;

	intersect.hit_times = 0;
	bhask = calculate_bhaskara(ray, sphere);
	if (bhask.discriminant < 0)
		return (intersect);
	intersect.hit_times = 2;
	intersect.hit[0] = bhask.s1;
	intersect.hit[1] = bhask.s2;
	intersect.object = sphere;
	return (intersect);
}
