/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:12:09 by revieira          #+#    #+#             */
/*   Updated: 2023/06/20 17:12:21 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double	hit_sphere(t_point center, double radius, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	t_point	oc;

	oc = minus(ray.origin, center);
	a = lenght_square(ray.direction);
	b = dot(oc, ray.direction);
	c = lenght_square(oc) - radius * radius;
	discriminant = b * b - a * c;
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / a);
}
