/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:42:30 by revieira          #+#    #+#             */
/*   Updated: 2023/09/13 19:06:18 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_pattern	stripe_pattern(t_color a, t_color b, t_matrix transform)
{
	t_pattern	pattern;
	
	pattern.a = a;
	pattern.b = b;
	pattern.transform = transform;
	pattern.inv_transform = inverse(transform);
	return (pattern);
}

t_color	stripe_at(t_pattern pattern, t_point point)
{
	if ((int)floor(point.x) % 2 == 0)
		return (pattern.a);
	return (pattern.b);
}

t_color	stripe_at_obj(t_pattern pattern, t_matrix inv_transform, t_point p)
{
	t_matrix	object_point;
	t_point		pattern_point;

	object_point = multiply_matrix(inv_transform, point_to_matrix(p));
	pattern_point = matrix_to_point(multiply_matrix(pattern.inv_transform, object_point));
	return (stripe_at(pattern, pattern_point));
}
