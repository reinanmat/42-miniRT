/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:12:09 by revieira          #+#    #+#             */
/*   Updated: 2023/07/11 17:44:44 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	hit_sphere(t_sphere sphere, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	t_point	oc;

	oc = minus(ray.origin, sphere.center);
	a = length_square(ray.direction);
	b = dot(oc, ray.direction);
	c = length_square(oc) - sphere.radius * sphere.radius;
	discriminant = b * b - a * c;
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / a);
}

double	hittable(t_hittable **objects, t_ray ray)
{
	double		t;
	t_hittable	*aux;

	t = -1.0;
	aux = *objects;
	while (aux)
	{
		if (aux->type == 1)
			t = hit_sphere(*aux->sp, ray);
		if (t > 0)
			break ;
		aux = aux->next;
	}
	return (t);
}
