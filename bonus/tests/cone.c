/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:13:41 by revieira          #+#    #+#             */
/*   Updated: 2023/09/21 17:11:00 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt_bonus.h"

t_world	cone_world(void)
{
	t_world		world;
	t_vec3		forward;
	t_vec3		up;
	t_vec3		from;
	t_cone	*cone;

	from = vec3(0, 0, -5);
	forward = vec3(0, 0, 1);
	up = vec3(0, 1, 0);
	world.cam.fov = M_PI / 2;
	set_pixel_size(&world.cam);

	world.cam.t = view_transform(from, forward, up);

	world.ambient_light.color = color(1, 1, 1);
	world.ambient_light.light_ratio = 0.1;

	world.amount_of_lights = 1;
	world.light = point_light(point(0, 0, -5), 1);
	world.objects = NULL;

	cone = unit_cone();
	cone->material.color = color(1, 0, 0);
	cone->max = 2;
	cone->min = -2;
	
	hittable_add("co", cone, &world.objects);
	return (world);
}

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

