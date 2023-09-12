/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:03:40 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/12 19:14:32 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

static t_bhask	calculate_bhaskara(t_ray ray)
{
	double	root;
	t_bhask	bhask;

	bhask.discriminant = -1;
	bhask.a = (ray.direction.x * ray.direction.x) - (ray.direction.y * ray.direction.y) + (ray.direction.z * ray.direction.z);
	if (fabs(bhask.a) < EPSILON)
		return (bhask);
	bhask.b = (2 * ray.origin.x * ray.direction.x) - (2 * ray.origin.y * ray.direction.y) + (2 * ray.origin.z * ray.direction.z);
	bhask.c = (ray.origin.x * ray.origin.x) - (ray.origin.y * ray.origin.y) + (ray.origin.z * ray.origin.z);
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

static int	check_cap(t_ray ray, double t)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	if ((x * x) + (z * z) <= 1)
		return (1);
	return (0);
}

static void	intersect_caps(t_ray ray, t_cone *cone, t_inter_point *inters)
{
	double	t;

	if (fabs(ray.direction.y) < EPSILON)
		return ;
	t = (cone->min - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
		inters->hit[inters->hit_times++] = t;
	t = (cone->max - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
		inters->hit[inters->hit_times++] = t;
}

t_inter_point	intersect_cone(t_ray ray, t_cone *cone)
{
	t_inter_point	inter;
	t_bhask			bhask;
	double			y_first_inter;
	double			y_second_inter;

	inter.object = cylinder;
	inter.hit_times = 0;
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
	intersect_caps(ray, cone, &inter);
	return (inter);
}
