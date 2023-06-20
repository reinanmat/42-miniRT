/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:33:32 by revieira          #+#    #+#             */
/*   Updated: 2023/06/20 17:37:43 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_point	add(t_point a, t_point b)
{
	return ((t_point){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_point	minus(t_point a, t_point b)
{
	return ((t_point){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_point	multiply(t_point a, t_point b)
{
	return ((t_point){a.x * b.x, a.y * b.y, a.z * b.z});
}

t_point	multiply_n(t_point a, double n)
{
	return ((t_point){a.x * n, a.y * n, a.z * n});
}

t_point	division(t_point a, t_point b)
{
	return ((t_point){a.x / b.x, a.y / b.y, a.z / b.z});
}

t_point	division_n(t_point a, double n)
{
	return (multiply_n(a, 1/n));
}

double	lenght_square(t_point a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}

double	lenght(t_point a)
{
	return (sqrt(lenght_square(a)));
}

t_point	unit_vector(t_point a)
{
	return (division_n(a, lenght(a)));
}

double	dot(t_point a, t_point b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_point	at(t_ray ray, double t)
{
	return (add(ray.origin, multiply_n(ray.direction, t)));
}
