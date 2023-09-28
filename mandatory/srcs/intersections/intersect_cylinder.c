/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:52:26 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/27 21:15:29 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

static t_bhask	calculate_bhaskara(t_ray ray)
{
	double	root;
	t_bhask	bhask;

	bhask.discriminant = -1;
	bhask.a = (ray.direction.x * ray.direction.x) + \
				(ray.direction.z * ray.direction.z);
	if (fabs(bhask.a) < EPSILON)
		return (bhask);
	bhask.b = (2 * ray.origin.x * ray.direction.x) + \
				(2 * ray.origin.z * ray.direction.z);
	bhask.c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1;
	bhask.discriminant = bhask.b * bhask.b - 4 * bhask.a * bhask.c;
	if (bhask.discriminant < 0)
		return (bhask);
	root = sqrt(bhask.discriminant);
	bhask.s1 = (-bhask.b - root) / (2 * bhask.a);
	bhask.s2 = (-bhask.b + root) / (2 * bhask.a);
	return (bhask);
}

int	check_cap(t_ray ray, double t)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	if ((x * x) + (z * z) <= 1)
		return (1);
	return (0);
}

void	intersect_caps(t_ray ray, t_cylinder *cylinder, t_inter_point *inters)
{
	double	t;

	if (fabs(ray.direction.y) < EPSILON)
		return ;
	t = (cylinder->min - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
		inters->hit[inters->hit_times++] = t;
	t = (cylinder->max - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
		inters->hit[inters->hit_times++] = t;
}

t_inter_point	intersect_cylinder(t_ray ray, t_cylinder *cylinder)
{
	t_inter_point	inter;
	t_bhask			bhask;
	double			y_first_inter;
	double			y_second_inter;

	inter.hit_times = 0;
	bhask = calculate_bhaskara(ray);
	if (bhask.discriminant >= 0)
	{
		if (bhask.s1 > bhask.s2)
			ft_swap(&bhask.s1, &bhask.s2);
		y_first_inter = ray.origin.y + bhask.s1 * ray.direction.y;
		if (cylinder->min < y_first_inter && y_first_inter < cylinder->max)
			inter.hit[inter.hit_times++] = bhask.s1;
		y_second_inter = ray.origin.y + bhask.s2 * ray.direction.y;
		if (cylinder->min < y_second_inter && y_second_inter < cylinder->max)
			inter.hit[inter.hit_times++] = bhask.s2;
	}
	intersect_caps(ray, cylinder, &inter);
	return (inter);
}
