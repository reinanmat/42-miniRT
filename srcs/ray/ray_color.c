/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:28:55 by revieira          #+#    #+#             */
/*   Updated: 2023/07/20 15:20:29 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_color	ray_color(t_ray ray, t_world world)
{
	t_color	color;
	t_range	range;
	t_hit	hit;

	hit = (t_hit){0};
	range.min = 0;
	range.max = INFINITY;
	if (hit_anything(world.objects, ray, range, &hit))
		return (s_multiply(add(hit.normal, (t_color){1.0, 1.0, 1.0}), 0.5));
	color = gradient_color(ray.direction.y, (t_color){1.0, 1.0, 1.0},
			(t_color){0.5, 0.7, 1.0});
	return (color);
}
