/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:33:03 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/11 17:09:55 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

static t_ray	get_light_ray(t_light light, t_point point)
{
	t_vec3	light_v;
	t_vec3	direction;
	t_ray	light_ray;

	light_v = sub(light.coordinate, point);
	direction = normalize(light_v);
	light_ray = ray(point, direction);
	return (light_ray);
}

double	get_light_t(t_light light, t_point point)
{
	t_vec3	light_v;
	double	light_t;

	light_v = sub(light.coordinate, point);
	light_t = magnitude(light_v);
	return (light_t);
}

int	is_shadowed(t_world world, t_point point)
{
	double			distance;
	t_ray			light_ray;
	t_intersections	*intersections;
	t_intersections	*closest_intersection;

	distance = get_light_t(world.light, point);
	light_ray = get_light_ray(world.light, point);
	intersections = intersection_calculate(light_ray, world.objects);
	closest_intersection = hit(intersections);
	if (closest_intersection && closest_intersection->t < distance)
	{
		clear_intersect(&intersections);
		return (1);
	}
	clear_intersect(&intersections);
	return (0);
}
