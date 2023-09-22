/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_operations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:33:32 by revieira          #+#    #+#             */
/*   Updated: 2023/09/12 17:59:33 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

double	length_square(t_vec3 a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}

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
