/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:03:40 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/27 21:18:48 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

static double	get_bhask_a(t_ray ray)
{
	double	x_sqrd;
	double	y_sqrd;
	double	z_sqrd;

	x_sqrd = ray.direction.x * ray.direction.x;
	y_sqrd = ray.direction.y * ray.direction.y;
	z_sqrd = ray.direction.z * ray.direction.z;
	return (x_sqrd - y_sqrd + z_sqrd);
}

static double	get_bhask_b(t_ray ray)
{
	return (2 * ray.origin.x * ray.direction.x - \
			2 * ray.origin.y * ray.direction.y + \
			2 * ray.origin.z * ray.direction.z);
}

static double	get_bhask_c(t_ray ray)
{
	return (ray.origin.x * ray.origin.x - \
		ray.origin.y * ray.origin.y + \
		ray.origin.z * ray.origin.z);
}

static t_bhask	calculate_bhaskara(t_ray ray)
{
	double	root;
	t_bhask	bhask;

	bhask.discriminant = -1;
	bhask.a = get_bhask_a(ray);
	if (fabs(bhask.a) < EPSILON)
		return (bhask);
	bhask.b = get_bhask_b(ray);
	bhask.c = get_bhask_c(ray);
	if (bhask.a == 0 && bhask.b != 0)
	{
		bhask.s1 = -bhask.c / 2 * bhask.b;
		bhask.s2 = -bhask.c / 2 * bhask.b;
		return (bhask);
	}
	bhask.discriminant = bhask.b * bhask.b - 4 * bhask.a * bhask.c;
	if (bhask.discriminant < 0)
		return (bhask);
	root = sqrt(bhask.discriminant);
	bhask.s1 = (-bhask.b - root) / (2 * bhask.a);
	bhask.s2 = (-bhask.b + root) / (2 * bhask.a);
	return (bhask);
}

t_inter_point	intersect_cone(t_ray ray, t_cone *cone)
{
	t_inter_point	inter;
	t_bhask			bhask;
	double			y_first_inter;
	double			y_second_inter;

	inter.hit_times = 0;
	inter.hit[0] = -1;
	inter.hit[1] = -1;
	bhask = calculate_bhaskara(ray);
	if (bhask.discriminant >= 0)
	{
		if (bhask.s1 > bhask.s2)
			ft_swap(&bhask.s1, &bhask.s2);
		y_first_inter = ray.origin.y + bhask.s1 * ray.direction.y;
		if (cone->min < y_first_inter && y_first_inter < cone->max)
			inter.hit[inter.hit_times++] = bhask.s1;
		y_second_inter = ray.origin.y + bhask.s2 * ray.direction.y;
		if (cone->min < y_second_inter && y_second_inter < cone->max)
			inter.hit[inter.hit_times++] = bhask.s2;
	}
	return (inter);
}
