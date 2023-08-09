/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:43:39 by revieira          #+#    #+#             */
/*   Updated: 2023/08/09 18:22:49 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

typedef struct s_bhask
{
	double	a;
	double	b;
	double	c;
	double	dscr;
}	t_bhask;

static t_vec3	set_face_normal(t_ray ray, t_point intersection, t_sphere sp)
{
	t_vec3	face;

	face = s_division(sub(intersection, sp.center), sp.radius);
	if (dot(ray.direction, face) > 0.0)
		return (s_multiply(face, -1));
	return (face);
}

int	hit_sphere(t_sphere sphere, t_ray ray, t_range range, t_hit *hit)
{
	double	root;
	double	sqrtd;
	t_bhask	bhask;
	t_vec3	oc;

	oc = sub(ray.origin, sphere.center);
	bhask.a = length_square(ray.direction);
	bhask.b = dot(oc, ray.direction);
	bhask.c = length_square(oc) - sphere.radius * sphere.radius;
	bhask.dscr = bhask.b * bhask.b - bhask.a * bhask.c;
	if (bhask.dscr < 0)
		return (0);
	sqrtd = sqrt(bhask.dscr);
	root = (-bhask.b - sqrtd) / bhask.a;
	if (root < range.min || root > range.max)
	{
		root = (-bhask.b + sqrtd) / bhask.a;
		if (root < range.min || root > range.max)
			return (0);
	}
	hit->t = root;
	hit->point = position(ray, root);
	hit->normal = set_face_normal(ray, hit->point, sphere);
	hit->color = sphere.color;
	return (1);
}
