/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:33:32 by revieira          #+#    #+#             */
/*   Updated: 2023/09/19 14:41:25 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt.h"

double	magnitude(t_vec3 a)
{
	return (sqrt(length_square(a)));
}

t_vec3	normalize(t_vec3 a)
{
	return (s_division(a, magnitude(a)));
}

double	dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_point	position(t_ray ray, double t)
{
	return (add(ray.origin, s_multiply(ray.direction, t)));
}

t_vec3	cross_product(t_vec3 a, t_vec3 b)
{
	t_vec3	c;

	c.x = (a.y * b.z) - (a.z * b.y);
	c.y = (a.z * b.x) - (a.x * b.z);
	c.z = (a.x * b.y) - (a.y * b.x);
	return (c);
}
