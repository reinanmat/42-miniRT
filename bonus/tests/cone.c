/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:13:41 by revieira          #+#    #+#             */
/*   Updated: 2023/09/13 14:04:18 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt_bonus.h"

void	test_cone()
{
	t_cone			*cone;
	t_inter_point	inter;
	t_world			world;

	cone = unit_cone();
	cone->max = INFINITY;
	cone->min = -INFINITY;
	
	printf("\n======================INTERSECT_A_CONE=======================\n");
	inter = intersect_cone(ray((t_point){0, 0, -5}, vec3(0, 0, 1)), cone);
	printf("hit count: %d => %f %f\n", inter.hit_times, inter.hit_times ? inter.hit[0] : 0, inter.hit_times ? inter.hit[1] : 0);
	inter = intersect_cone(ray((t_point){0, 0, -5}, normalize(vec3(1, 1, 1))), cone);
	printf("hit count: %d => %f %f\n", inter.hit_times, inter.hit_times ? inter.hit[0] : 0, inter.hit_times ? inter.hit[1] : 0);
	inter = intersect_cone(ray((t_point){1, 1, -5}, normalize(vec3(-0.5, -1, 1))), cone);
	printf("hit count: %d => %f %f\n", inter.hit_times, inter.hit_times ? inter.hit[0] : 0, inter.hit_times ? inter.hit[1] : 0);

	
	printf("\n===============INTERSECT_A_CONE_RAY_PARALLEL=================\n");
	inter = intersect_cone(ray((t_point){0, 0, -1}, normalize(vec3(0, 1, 1))), cone);
	printf("hit count: %d => %f %f\n", inter.hit_times, inter.hit_times ? inter.hit[0] : 0, inter.hit_times ? inter.hit[1] : 0);

	printf("\n=================INTERSECT_A_CONE_END_CAPS===================\n");
	cone->max = 0.5;
	cone->min = -0.5;
	inter = intersect_cone(ray((t_point){0, 0, -5}, vec3(0, 1, 0)), cone);
	printf("hit count: %d => %f %f\n", inter.hit_times, inter.hit_times ? inter.hit[0] : 0, inter.hit_times ? inter.hit[1] : 0);
	inter = intersect_cone(ray((t_point){0, 0, -0.25}, normalize(vec3(0, 1, 1))), cone);
	printf("hit count: %d => %f %f\n", inter.hit_times, inter.hit_times ? inter.hit[0] : 0, inter.hit_times ? inter.hit[1] : 0);
	inter = intersect_cone(ray((t_point){0, 0, -0.25}, normalize(vec3(0, 1, 0))), cone);
	printf("hit count: %d => %f %f\n", inter.hit_times, inter.hit_times ? inter.hit[0] : 0, inter.hit_times ? inter.hit[1] : 0);

	printf("\n=============COMPUTE_NORMAL_VECTOR_ON_A_CONE=================\n");
	cone->max = INFINITY;
	cone->min = -INFINITY;

	t_vec3	normal;
	t_point	p1 = point(0, 0, 0);
	t_point	p2 = point(1, 1, 1);
	t_point	p3 = point(-1, -1, 0);
	world.objects = NULL;
	hittable_add("co", cone, &world.objects);

	normal = local_normal_at(world.objects, p1);
	print("p1: ", &p1, "	|	local normal: ", &normal);
	normal = local_normal_at(world.objects, p2);
	print("p2: ", &p2, "	|	local normal: ", &normal);
	normal = local_normal_at(world.objects, p3);
	print("p3: ", &p3, "	|	local normal: ", &normal);
	
	clean_hittable(&world.objects);
}

