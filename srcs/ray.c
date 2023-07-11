/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:28:55 by revieira          #+#    #+#             */
/*   Updated: 2023/07/11 17:42:20 by revieira         ###   ########.fr       */
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

/* t_color	ray_color(t_ray ray, t_world world) */
/* { */
/* 	double	t; */

/* 	t = hittable(&world.objects, ray); */
/* 	if (t > 0) */
/* 		return ((t_color){1, 0, 0}); */
/* 	return ((t_color){1, 1, 1}); */
/* } */

t_color	ray_color(t_ray ray, t_world world)
{
	t_sphere	s;
	t_vec3		direction;
	t_color		color;
	t_point		aux1;
	t_point		aux2;
	double		t;

	s.center = (t_point){0, 0, -1};
	s.radius = 0.7;
	t = hittable(&world.objects, ray);
	if (t > 0)
	{
		aux1 = normalize(minus(at(ray, t), (t_point){0, 0, -1}));
		color = s_multiply((t_point){aux1.x + 1, aux1.y + 1, aux1.z + 1}, 0.5);
		return (color);
	}
	direction = normalize(ray.direction);
	t = 0.5 * (direction.y + 1.0);
	aux1 = s_multiply((t_point){1.0, 1.0, 1.0}, (1.0 - t));
	aux2 = s_multiply((t_point){0.5, 0.7, 1.0}, t);
	color = add(aux1, aux2);
	return (color);
}
