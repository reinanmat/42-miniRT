/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:28:55 by revieira          #+#    #+#             */
/*   Updated: 2023/08/17 17:00:32 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_color	old_ray_color(t_ray ray, t_world world)
{
	t_color	color;
	t_range	range;
	t_hit	hit;

	hit = (t_hit){0};
	range.min = 0;
	range.max = INFINITY;
	if (hit_anything(world.objects, ray, range, &hit))
		return (hit.color);
	color = (t_color){0};
	return (color);
}
