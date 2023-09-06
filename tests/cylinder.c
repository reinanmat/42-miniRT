/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:51:42 by revieira          #+#    #+#             */
/*   Updated: 2023/09/06 15:19:22 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt.h"

void	test_cylinder(void)
{
	t_world			world;
	t_cylinder		*cy;
	t_inter_point	inters;

	world.light = point_light(point(-10, 10, -10), 1);
	world.objects = NULL;
	cy = unit_cylinder();
	hittable_add("cy", cy, &world.objects);

	printf("\n===================A_RAY_MISSES_A_CYLINDER====================\n");
	t_ray	ray1 = ray(point(1, 0, -5), normalize(vec3(0, 0, 1)));
	t_ray	ray2 = ray(point(0, 0, -5), normalize(vec3(0, 0, 1)));
	t_ray	ray3 = ray(point(0.5, 0, -5), normalize(vec3(0.1, 1, 1)));
	t_ray	ray4 = ray(point(0, 1.5, -2), normalize(vec3(0, 0, 1)));

	inters = intersect_cylinder(ray1, cy);
	printf("Intersect ray1? %d >> t0: %f t1: %f\n", inters.hit_times, inters.hit[0], inters.hit[1]);
	inters = intersect_cylinder(ray2, cy);
	printf("Intersect ray2? %d >> t0: %f t1: %f\n", inters.hit_times, inters.hit[0], inters.hit[1]);
	inters = intersect_cylinder(ray3, cy);
	printf("Intersect ray3? %d >> t0: %f t1: %f\n", inters.hit_times, inters.hit[0], inters.hit[1]);
	inters = intersect_cylinder(ray4, cy);
	printf("Intersect ray4? %d >> t0: %f t1: %f\n", inters.hit_times, inters.hit[0], inters.hit[1]);

	printf("\n=====================TRUNCATED_CYLINDERS=====================\n");
	cy->min = 1;
	cy->max = 2;
	t_ray	ray5 = ray(point(0, 1.5, 0), normalize(vec3(0.1, 1, 0)));
	t_ray	ray6 = ray(point(0, 3, -5), normalize(vec3(0, 0, 1)));
	t_ray	ray7 = ray(point(0, 0, -5), normalize(vec3(0, 0, 1)));
	t_ray	ray8 = ray(point(0, 2, -5), normalize(vec3(0, 0, 1)));
	t_ray	ray9 = ray(point(0, 1, -5), normalize(vec3(0, 0, 1)));
	t_ray	ray10 = ray(point(0, 1.5, -2), normalize(vec3(0, 0, 1)));

	inters = intersect_cylinder(ray5, cy);
	printf("Intersect ray5? %d >> t0: %f t1: %f\n", inters.hit_times, inters.hit[0], inters.hit[1]);
	inters = intersect_cylinder(ray6, cy);
	printf("Intersect ray6? %d >> t0: %f t1: %f\n", inters.hit_times, inters.hit[0], inters.hit[1]);
	inters = intersect_cylinder(ray7, cy);
	printf("Intersect ray7? %d >> t0: %f t1: %f\n", inters.hit_times, inters.hit[0], inters.hit[1]);
	inters = intersect_cylinder(ray8, cy);
	printf("Intersect ray8? %d >> t0: %f t1: %f\n", inters.hit_times, inters.hit[0], inters.hit[1]);
	inters = intersect_cylinder(ray9, cy);
	printf("Intersect ray9? %d >> t0: %f t1: %f\n", inters.hit_times, inters.hit[0], inters.hit[1]);
	inters = intersect_cylinder(ray10, cy);
	printf("Intersect ray10? %d >> t0: %f t1: %f\n", inters.hit_times, inters.hit[0], inters.hit[1]);

	printf("\n=====================INTERSECT_END_CAPS======================\n");
	t_ray	ray11 = ray(point(0, 3, 0), normalize(vec3(0, -1, 0)));
	t_ray	ray12 = ray(point(0, 3, -2), normalize(vec3(0, -1, 2)));
	t_ray	ray13 = ray(point(0, 4, -2), normalize(vec3(0, -1, 1)));
	t_ray	ray14 = ray(point(0, 0, -2), normalize(vec3(0, 1, 2)));
	t_ray	ray15 = ray(point(0, -1, -2), normalize(vec3(0, 1, 2)));

	inters = intersect_cylinder(ray11, cy);
	printf("Intersect ray11? %d >> t0: %f t1: %f\n", inters.hit_times, inters.hit[0], inters.hit[1]);
	inters = intersect_cylinder(ray12, cy);
	printf("Intersect ray12? %d >> t0: %f t1: %f\n", inters.hit_times, inters.hit[0], inters.hit[1]);
	inters = intersect_cylinder(ray13, cy);
	printf("Intersect ray13? %d >> t0: %f t1: %f\n", inters.hit_times, inters.hit[0], inters.hit[1]);
	inters = intersect_cylinder(ray14, cy);
	printf("Intersect ray14? %d >> t0: %f t1: %f\n", inters.hit_times, inters.hit[0], inters.hit[1]);
	inters = intersect_cylinder(ray15, cy);
	printf("Intersect ray15? %d >> t0: %f t1: %f\n", inters.hit_times, inters.hit[0], inters.hit[1]);

	printf("\n===========COMPUTE_NORMAL_VECTOR_AT_THE_END_CAPS=============\n");
	t_vec3	normal;
	t_point	p1 = point(0, 1, 0);
	t_point	p2 = point(0.5, 1, 0);
	t_point	p3 = point(0, 1, 0.5);
	t_point	p4 = point(0, 2, 0);
	t_point	p5 = point(0.5, 2, 0);
	t_point	p6 = point(0, 2, 0.5);

	normal = local_normal_at(world.objects, p1);
	print("p1: ", &p1, " local normal: ", &normal);
	normal = local_normal_at(world.objects, p2);
	print("p1: ", &p2, " local normal: ", &normal);
	normal = local_normal_at(world.objects, p3);
	print("p1: ", &p3, " local normal: ", &normal);
	normal = local_normal_at(world.objects, p4);
	print("p1: ", &p4, " local normal: ", &normal);
	normal = local_normal_at(world.objects, p5);
	print("p1: ", &p5, " local normal: ", &normal);
	normal = local_normal_at(world.objects, p6);
	print("p1: ", &p6, " local normal: ", &normal);
	
	clean_hittable(&world.objects);
}
