/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:10:06 by revieira          #+#    #+#             */
/*   Updated: 2023/09/07 12:25:17 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

t_inter_point	intersect_plane(t_ray ray, t_plane *plane)
{
	t_inter_point	intersect;

	intersect.hit_times = 0;
	if (fabs(ray.direction.y) < EPSILON)
		return (intersect);
	intersect.hit_times = 1;
	intersect.hit[0] = -ray.origin.y / ray.direction.y;
	intersect.object = plane;
	return (intersect);
}
