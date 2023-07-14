/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:28:55 by revieira          #+#    #+#             */
/*   Updated: 2023/07/14 18:55:41 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	get_ray(double u, double v, t_cam cam)
{
	t_ray	ray;
	t_point	aux1;
	t_point	aux2;

	aux1 = add(cam.lower_left_corner, s_multiply(cam.horizontal, u));
	aux2 = minus(s_multiply(cam.vertical, v), cam.origin);
	ray.direction = normalize(add(aux1, aux2));
	ray.origin = cam.origin;
	return (ray);
}

t_color	ray_color(t_ray ray, t_world world)
{
	t_color	color;
	t_range	range;
	t_hit	hit;

	range.min = 0;
	range.max = INFINITY;
	if (hit_anything(world.objects, ray, range, &hit))
		return (s_multiply(add(hit.normal, (t_color){1.0, 1.0, 1.0}), 0.5));
	color = gradient_color(ray.direction.y, (t_color){1.0, 1.0, 1.0},
			(t_color){0.5, 0.7, 1.0});
	return (color);
}

/* t_vec3	reflection(t_vec3 direction, t_vec3 normal) */
/* { */
/* 	double	aux; */
/* 	t_vec3	reflect; */

/* 	aux = -2 * dot(direction, normal); */
/* 	reflect = s_multiply(normal, aux); */
/* 	return (reflect); */
/* } */

/* t_color	ray_color(t_ray ray, t_world world, int depth) */
/* { */
/* 	t_ray	new_ray; */
/* 	t_color	color; */
/* 	t_point	target; */
/* 	t_hit	hit; */

/* 	if (depth == 0) */
/* 		return ((t_color){0, 0, 0}); */
/* 	if (hit_anything(world.objects, ray, 0.01, INFINITY, &hit)) */
/* 	{ */
/* 		target = add(add(hit.point, hit.normal), vec_rand()); */
/* 		new_ray.origin = hit.point; */
/* 		new_ray.direction = normalize(minus(target, hit.point)); */
/* 		return (s_multiply(ray_color(new_ray, world, depth - 1), 0.5)); */
/* 	} */
/* 	color = gradient_color(ray.direction.y, (t_color){1.0, 1.0, 1.0}, */
/* 			(t_color){0.5, 0.7, 1.0}); */
/* 	return (color); */
/* } */

/* t_color	ray_color(t_ray ray, t_world world) */
/* { */
/* 	t_ray	new_ray; */
/* 	t_color	color; */
/* 	t_hit	hit; */

/* 	new_ray.origin = ray.origin; */
/* 	new_ray.direction = ray.direction; */
/* 	while (hit_anything(world.objects, new_ray, 0.01, INFINITY, &hit)) */
/* 	{ */
/* 		new_ray.origin = hit.point; */
/* 		new_ray.direction = normalize(reflection(ray.direction, hit.normal)); */
/* 	} */
/* 	color = gradient_color(new_ray.direction.y, (t_color){1.0, 1.0, 1.0}, */
/* 			(t_color){0.5, 0.7, 1.0}); */
/* 	return (color); */
/* } */
