/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_worlds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:53:28 by revieira          #+#    #+#             */
/*   Updated: 2023/09/05 20:24:43 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt.h"

t_world	room(void)
{
	t_world		world;
	char		*config[4];
	t_vec3		forward;
	t_vec3		up;
	t_vec3		from;
	t_plane		*floor;
	t_plane		*roof;
	t_plane		*wall;
	t_plane		*wall_right;
	t_plane		*wall_left;

	from = vec3(0, 0, -5);
	forward = vec3(0, 0, 1);
	up = vec3(0, 1, 0);
	world.cam.fov = M_PI / 2;
	set_pixel_size(&world.cam);
	world.cam.t = view_transform(from, forward, up);

	world.light = point_light(point(0, 0, 0), 1);

	world.objects = NULL;
	config[0] = "pl";
	config[1] = "0,0,0";
	config[2] = "0,1,0";
	config[3] = "255,255,255";

	floor = plane(config);
	floor->material.color = color(0, 1, 0);
	floor->transform = translation_matrix(point(0, -4, 0));

	roof = plane(config);
	roof->material.color = color(0, 0, 1);
	roof->transform = translation_matrix(point(0, 4, 0));

	wall_right = plane(config);
	wall_right->material.color = color(0, 1, 1);
	wall_right->transform = multiply_matrix(translation_matrix(point(5, 0, 0)), rotate_z_matrix(M_PI / 2));

	wall_left = plane(config);
	wall_left->material.color = color(1, 1, 0);
	wall_left->transform = multiply_matrix(translation_matrix(point(-5, 0, 0)), rotate_z_matrix(M_PI /2));

	wall = plane(config);
	wall->material.color = color(1, 0, 0);
	wall->transform = multiply_matrix(translation_matrix(point(0, 0, 5)), rotate_x_matrix(M_PI / 2));

	config[0] = "sp";
	config[1] = "0,0,0";
	config[2] = "2";
	config[3] = "255,255,255";
	t_sphere	*sp = sphere(config);
	sp->material.color = color(1, 1, 1);
	sp->transform = translation_matrix(point(0, 0, 0));
	
	hittable_add("pl", floor, &world.objects);
	hittable_add("pl", roof, &world.objects);
	hittable_add("pl", wall, &world.objects);
	hittable_add("pl", wall_left, &world.objects);
	hittable_add("pl", wall_right, &world.objects);
	/* hittable_add("sp", sp, &world.objects); */
	return (world);
}

t_world	default_world(void)
{
	t_world		world;
	char		*config[6];
	t_cylinder	*cyl1;
	t_ray		ray1;
	t_ray		ray2;
	t_ray		ray3;
	t_ray		ray4;
	t_ray		ray5;
	t_ray		ray6;
	t_ray		ray7;
	t_ray		ray8;
	t_ray		ray9;
	t_ray		ray10;
	t_ray		ray11;
	t_ray		ray12;
	t_ray		ray13;
	t_ray		ray14;
	t_ray		ray15;
	t_inter_point	in1;

	ray1 = ray(point(1, 0, -5), normalize(vec3(0, 0, 1)));
	ray2 = ray(point(0, 0, -5), normalize(vec3(0, 0, 1)));
	ray3 = ray(point(0.5, 0, -5), normalize(vec3(0.1, 1, 1)));
	ray4 = ray(point(0, 1.5, -2), normalize(vec3(0, 0, 1)));

	ray5 = ray(point(0, 1.5, 0), normalize(vec3(0.1, 1, 0)));
	ray6 = ray(point(0, 3, -5), normalize(vec3(0, 0, 1)));
	ray7 = ray(point(0, 0, -5), normalize(vec3(0, 0, 1)));
	ray8 = ray(point(0, 2, -5), normalize(vec3(0, 0, 1)));
	ray9 = ray(point(0, 1, -5), normalize(vec3(0, 0, 1)));
	ray10 = ray(point(0, 1.5, -2), normalize(vec3(0, 0, 1)));

	ray11 = ray(point(0, 3, 0), normalize(vec3(0, -1, 0)));
	ray12 = ray(point(0, 3, -2), normalize(vec3(0, -1, 2)));
	ray13 = ray(point(0, 4, -2), normalize(vec3(0, -1, 1)));
	ray14 = ray(point(0, 0, -2), normalize(vec3(0, 1, 2)));
	ray15 = ray(point(0, -1, -2), normalize(vec3(0, 1, 2)));

	world.light = point_light(point(-10, 10, -10), 1);
	world.objects = NULL;
	config[0] = "cy";
	config[1] = "0,0,0";
	config[2] = "0, 1, 0";
	config[3] = "1";
	config[4] = "1";
	config[5] = "1, 1, 1";
	cyl1 = cylinder(config);
	cyl1->min = 1;
	cyl1->max = 2;
	cyl1->material.diffuse = 0.7;
	cyl1->material.specular = 0.2;
	cyl1->transform = identity_matrix();
	hittable_add("cy", cyl1, &world.objects);
	in1 = intersect_cylinder(ray1, cyl1); printf("Intersect ray1? %d >> t0: %f t1: %f\n", in1.hit_times, in1.hit[0], in1.hit[1]);
	in1 = intersect_cylinder(ray2, cyl1);
	printf("Intersect ray2? %d >> t0: %f t1: %f\n", in1.hit_times, in1.hit[0], in1.hit[1]);
	in1 = intersect_cylinder(ray3, cyl1);
	printf("Intersect ray3? %d >> t0: %f t1: %f\n", in1.hit_times, in1.hit[0], in1.hit[1]);
	in1 = intersect_cylinder(ray4, cyl1);
	printf("Intersect ray4? %d >> t0: %f t1: %f\n", in1.hit_times, in1.hit[0], in1.hit[1]);

	printf("====================================\n");

	in1 = intersect_cylinder(ray5, cyl1);
	printf("Intersect ray5? %d >> t0: %f t1: %f\n", in1.hit_times, in1.hit[0], in1.hit[1]);
	in1 = intersect_cylinder(ray6, cyl1);
	printf("Intersect ray6? %d >> t0: %f t1: %f\n", in1.hit_times, in1.hit[0], in1.hit[1]);
	in1 = intersect_cylinder(ray7, cyl1);
	printf("Intersect ray7? %d >> t0: %f t1: %f\n", in1.hit_times, in1.hit[0], in1.hit[1]);
	in1 = intersect_cylinder(ray8, cyl1);
	printf("Intersect ray8? %d >> t0: %f t1: %f\n", in1.hit_times, in1.hit[0], in1.hit[1]);
	in1 = intersect_cylinder(ray9, cyl1);
	printf("Intersect ray9? %d >> t0: %f t1: %f\n", in1.hit_times, in1.hit[0], in1.hit[1]);
	in1 = intersect_cylinder(ray10, cyl1);
	printf("Intersect ray10? %d >> t0: %f t1: %f\n", in1.hit_times, in1.hit[0], in1.hit[1]);

	printf("====================================\n");

	in1 = intersect_cylinder(ray11, cyl1);
	printf("Intersect ray11? %d >> t0: %f t1: %f\n", in1.hit_times, in1.hit[0], in1.hit[1]);
	in1 = intersect_cylinder(ray12, cyl1);
	printf("Intersect ray12? %d >> t0: %f t1: %f\n", in1.hit_times, in1.hit[0], in1.hit[1]);
	in1 = intersect_cylinder(ray13, cyl1);
	printf("Intersect ray13? %d >> t0: %f t1: %f\n", in1.hit_times, in1.hit[0], in1.hit[1]);
	in1 = intersect_cylinder(ray14, cyl1);
	printf("Intersect ray14? %d >> t0: %f t1: %f\n", in1.hit_times, in1.hit[0], in1.hit[1]);
	in1 = intersect_cylinder(ray15, cyl1);
	printf("Intersect ray15? %d >> t0: %f t1: %f\n", in1.hit_times, in1.hit[0], in1.hit[1]);

	return (world);
}

t_world	complex_world(void)
{
	t_world		world;
	t_vec3		forward;
	t_vec3		up;
	t_vec3		from;
	char		*config[6];
	t_sphere	*floor;
	t_sphere	*left_wall;
	t_sphere	*right_wall;
	t_sphere	*sp_middle;
	t_sphere	*sp_right;
	t_sphere	*sp_left;

	t_cylinder	*cy;

	from = vec3(0, 0, -5);
	forward = vec3(0, 0.1, 1);
	/* forward = normalize(sub(vec3(0, 0, 1), from)); */
	up = vec3(0, 1, 0);
	world.cam.fov = M_PI / 3;
	set_pixel_size(&world.cam);
	world.cam.t = view_transform(from, forward, up);

	world.light = point_light(point(0, 0, -5), 1);
	world.objects = NULL;

	config[0] = "sp";
	config[1] = "0,0,0";
	config[2] = "2";
	config[3] = "255, 255, 255";
	floor = sphere(config);
	left_wall = sphere(config);
	right_wall = sphere(config);
	sp_middle = sphere(config);
	sp_left = sphere(config);
	sp_right = sphere(config);

	config[0] = "cy";
	config[1] = "0,0,0";
	config[2] = "0, 1, 0";
	config[3] = "1";
	config[4] = "1";
	config[5] = "1, 1, 1";
	cy = cylinder(config);
	cy->min = 1;
	cy->max = 2;
	cy->transform = identity_matrix();
	cy->material.color = color(0, 1, 0);

	floor->transform = scaling_matrix(point(10, 0.01, 10));
	floor->material.specular = 0;
	floor->material.color = color(1, 0.9, 0.9);

	left_wall->transform = multiply_matrix(multiply_matrix(multiply_matrix(translation_matrix(point(0, 0, 5)), rotate_y_matrix(-M_PI/4)), rotate_x_matrix(M_PI/2)), scaling_matrix(point(10, 0.01, 10)));
	left_wall->material = floor->material;

	right_wall->transform = multiply_matrix(multiply_matrix(multiply_matrix(translation_matrix(point(0, 0, 5)), rotate_y_matrix(M_PI/4)), rotate_x_matrix(M_PI/2)), scaling_matrix(point(10, 0.01, 10)));
	right_wall->material = floor->material;

	sp_middle->transform = translation_matrix(point(-0.5, 1, 0.5));
	sp_middle->material.color = color(0.1, 1, 0.5);
	sp_middle->material.diffuse = 0.7;
	sp_middle->material.specular = 0.3;

	sp_right->transform = multiply_matrix(translation_matrix(point(1.5, 0.5, -0.5)), scaling_matrix(point(0.5, 0.5, 0.5)));
	sp_right->material.color = color(0.5, 1, 0.1);
	sp_right->material.diffuse = 0.7;
	sp_right->material.specular = 0.3;

	sp_left->transform = multiply_matrix(translation_matrix(point(-1.5, 0.33, -0.75)), scaling_matrix(point(0.33, 0.33, 0.33)));
	sp_left->material.color = color(1, 0.8, 0.1);
	sp_left->material.diffuse = 0.7;
	sp_left->material.specular = 0.3;

	hittable_add("cy", cy, &world.objects);
	/* hittable_add("sp", floor, &world.objects); */
	/* hittable_add("sp", left_wall, &world.objects); */
	/* hittable_add("sp", right_wall, &world.objects); */
	/* hittable_add("sp", sp_middle, &world.objects); */
	/* hittable_add("sp", sp_right, &world.objects); */
	/* hittable_add("sp", sp_left, &world.objects); */
	return (world);
}
