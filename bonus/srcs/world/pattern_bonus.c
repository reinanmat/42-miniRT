/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:42:30 by revieira          #+#    #+#             */
/*   Updated: 2023/09/25 15:22:00 by revieira         ###   ########.fr       */
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
