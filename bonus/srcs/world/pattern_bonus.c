/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:42:30 by revieira          #+#    #+#             */
/*   Updated: 2023/09/23 17:00:53 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_color	stripe_pattern(t_pattern pattern, t_point point)
{
	if ((int)floor(point.x) % 2 == 0)
		return (pattern.a);
	return (pattern.b);
}

t_color	ring_pattern(t_pattern pattern, t_point point)
{
	if ((int)floor(sqrt(point.x * point.x + point.z * point.z)) % 2 == 0)
		return (pattern.a);
	return (pattern.b);
}

t_color	checkers_pattern(t_pattern pattern, t_point point)
{
	if ((int)(floor(point.x) + floor(point.y) + floor(point.z)) % 2 == 0)
		return (pattern.a);
	return (pattern.b);
}

t_color	gradient_pattern(t_pattern pattern, t_point point)
{
	t_point	distance;
	double	fraction;
	t_color	final_color;

	distance = sub(pattern.b, pattern.a);
	fraction = point.x - floor(point.x);
	final_color = add(pattern.a, s_multiply(distance, fraction));
	return (final_color);
}

t_color	stripe_at_obj(t_pattern pattern, t_matrix inv_transform, t_point p)
{
	t_matrix	object_point;
	t_point		pattern_point;
	t_matrix	inv_by_obj_point;

	object_point = multiply_matrix(inv_transform, point_to_matrix(p));
	inv_by_obj_point = multiply_matrix(pattern.inv_transform, object_point);
	pattern_point = matrix_to_point(inv_by_obj_point);
	if (pattern.type == STRIPE_PATTERN)
		return (stripe_pattern(pattern, pattern_point));
	else if (pattern.type == GRADIENT_PATTERN)
		return (gradient_pattern(pattern, pattern_point));
	else if (pattern.type == RING_PATTERN)
		return (ring_pattern(pattern, pattern_point));
	else
		return (checkers_pattern(pattern, pattern_point));
}
