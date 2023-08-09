/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:58:52 by revieira          #+#    #+#             */
/*   Updated: 2023/08/09 18:19:05 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_intersection_point	intersect_sphere(t_ray ray, t_sphere *sphere)
{
	t_intersection_point	intersect;
	double					a;
	double					b;
	double					discriminant;
	t_vec3					point_to_sphere;

	intersect.hit_times = 0;
	point_to_sphere = sub(ray.origin, sphere->center);
	a = dot(ray.direction, ray.direction);
	b = 2 * dot(ray.direction, point_to_sphere);
	discriminant = (b * b) - 4 * a * (dot(point_to_sphere, point_to_sphere) - 1);
	if (discriminant < 0)
		return (intersect);
	intersect.hit_times = 2;
	intersect.hit[0] = (-b - sqrt(discriminant)) / (2 * a);
	intersect.hit[1] = (-b + sqrt(discriminant)) / (2 * a);
	intersect.object = sphere;
	return (intersect);
}
