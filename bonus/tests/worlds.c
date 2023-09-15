/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worlds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:53:28 by revieira          #+#    #+#             */
/*   Updated: 2023/09/15 16:29:17 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt_bonus.h"

t_world	chess2()
{
	t_world	world;

	t_vec3	forward;
	t_vec3	up;
	t_vec3	from;

	t_plane		*pl;
	t_sphere	*sp;
	t_cylinder	*cy;
	t_cone		*co;

	from = vec3(0, 2, -5);
	forward = normalize(vec3(0, -2, 5));
	up = vec3(0, 1, 0);
	world.cam.fov = M_PI / 2;
	set_pixel_size(&world.cam);
	world.cam.t = view_transform(from, forward, up);
	world.light = point_light(point(-3, 7, -5), 1);
	world.ambient_light.color = color(1, 1, 1);
	world.ambient_light.light_ratio = 0.1;

	world.objects = NULL;

	pl = unit_plane();
	pl->transform = translation_matrix(point(0, -1, 0));
	pl->inv_transform = inverse(pl->transform);
	pl->material.has_pattern = 1;
	pl->material.pattern = set_pattern(4, color(1, 1, 1), color(0, 0, 0), identity_matrix());

	sp = unit_sphere();
	sp->transform = translation_matrix(point(-3, 0, 0));
	sp->inv_transform = inverse(sp->transform);
	sp->material.has_pattern = 1;
	sp->material.pattern = set_pattern(4, color(1, 1, 1), color(0, 1, 0), scaling_matrix(point(0.3, 0.3, 0.3)));

	cy = unit_cylinder();
	cy->transform = translation_matrix(point(3, 0, 0));
	cy->inv_transform = inverse(cy->transform);
	cy->max = 1;
	cy->min = -1;
	cy->material.has_pattern = 1;
	cy->material.pattern = set_pattern(4, color(1, 1, 1), color(0, 0, 1), scaling_matrix(point(0.3, 0.3, 0.3)));

	co = unit_cone();
	co->transform = translation_matrix(point(0, 0, -1));
	co->inv_transform = inverse(co->transform);
	co->max = 1;
	co->min = -1;
	co->material.has_pattern = 1;
	co->material.pattern = set_pattern(4, color(1, 1, 1), color(1, 0, 0), scaling_matrix(point(0.3, 0.3, 0.3)));

	hittable_add("pl", pl, &world.objects);
	hittable_add("sp", sp, &world.objects);
	hittable_add("cy", cy, &world.objects);
	hittable_add("co", co, &world.objects);
	return (world);
}

t_world	test_multiple_objects()
{
	t_world		world;
	t_vec3		forward;
	t_vec3		up;
	t_vec3		from;

	t_sphere	*sp1;
	t_sphere	*sp2;
	t_sphere	*sp3;
	t_sphere	*sp4;
	t_sphere	*sp5;

	from = vec3(0, 0, -5);
	forward = vec3(0, 0, 1);
	up = vec3(0, 1, 0);
	world.cam.fov = M_PI / 2;
	set_pixel_size(&world.cam);
	world.cam.t = view_transform(from, forward, up);
	world.light = point_light(point(0, 0, -5), 1);

	world.objects = NULL;

	sp1 = unit_sphere();
	sp1->material.color = color(1, 0, 0);
	sp1->transform = multiply_matrix(translation_matrix(point(0, 0, 0)), scaling_matrix(point(0.5, 0.5, 0.5)));
	sp1->inv_transform = inverse(sp1->transform);
	sp1->inv_transform = inverse(sp1->inv_transform);

	sp2 = unit_sphere();
	sp2->material.color = color(0, 1, 0);
	sp2->transform = multiply_matrix(translation_matrix(point(0, 0, 2)), scaling_matrix(point(0.5, 2, 1)));
	sp2->inv_transform = inverse(sp2->inv_transform);

	sp3 = unit_sphere();
	sp3->material.color = color(0, 0, 1);
	sp3->transform = multiply_matrix(translation_matrix(point(0, 0, 3)), scaling_matrix(point(2, 0.5, 1)));
	sp3->inv_transform = inverse(sp3->inv_transform);

	sp4 = unit_sphere();
	sp4->material.color = color(0, 1, 1);
	sp4->transform = multiply_matrix(translation_matrix(point(0, 0, 5)), scaling_matrix(point(3, 3, 1)));
	sp4->inv_transform = inverse(sp4->inv_transform);

	sp5 = unit_sphere();
	sp5->material.color = color(1, 1, 0);
	sp5->transform = multiply_matrix(translation_matrix(point(0, 0, 8)), scaling_matrix(point(5, 5, 1)));
	sp5->inv_transform = inverse(sp5->inv_transform);

	hittable_add("sp", sp1, &world.objects);
	hittable_add("sp", sp2, &world.objects);
	hittable_add("sp", sp3, &world.objects);
	hittable_add("sp", sp4, &world.objects);
	hittable_add("sp", sp5, &world.objects);

	return (world);
}

t_world	room(void)
{
	t_world		world;
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
	/* forward = normalize(vec3(2, -2, 2)); */
	up = vec3(0, 1, 0);
	world.cam.fov = M_PI / 2;
	set_pixel_size(&world.cam);
	world.ambient_light.light_ratio = 0.2;
	world.ambient_light.color = (t_color){1, 1, 1};
	world.cam.t = view_transform(from, forward, up);

	world.light = point_light(point(-10, 10, -10), 1);

	world.objects = NULL;

	floor = unit_plane();
	floor->material.color = color(0, 1, 0);
	floor->transform = translation_matrix(point(0, -1, 0));
	floor->inv_transform = inverse(floor->transform);

	roof = unit_plane();
	roof->material.color = color(0, 0, 1);
	roof->transform = translation_matrix(point(0, 4, 0));
	roof->inv_transform = inverse(roof->transform);

	wall_right = unit_plane();
	wall_right->material.color = color(0, 1, 1);
	wall_right->transform = multiply_matrix(translation_matrix(point(5, 0, 0)), rotate_z_matrix(M_PI / 2));
	wall_right->inv_transform = inverse(wall_right->transform);

	wall_left = unit_plane();
	wall_left->material.color = color(1, 1, 0);
	wall_left->transform = multiply_matrix(translation_matrix(point(-5, 0, 0)), rotate_z_matrix(M_PI /2));
	wall_left->inv_transform = inverse(wall_left->transform);

	wall = unit_plane();
	wall->material.color = color(1, 1, 1);
	wall->transform = multiply_matrix(translation_matrix(point(0, 0, 5)), rotate_x_matrix(M_PI / 2));
	wall->inv_transform = inverse(wall->transform);

	t_sphere	*sp = unit_sphere();
	sp->material.color = color(1, 0, 0);
	sp->transform = scaling_matrix(point(1, 1, 1));
	sp->inv_transform = inverse(sp->transform);

	hittable_add("pl", floor, &world.objects);
	hittable_add("pl", roof, &world.objects);
	hittable_add("pl", wall, &world.objects);
	hittable_add("pl", wall_left, &world.objects);
	hittable_add("pl", wall_right, &world.objects);
	hittable_add("sp", sp, &world.objects);
	return (world);
}

t_world	complex_world(void)
{
	t_world		world;
	t_vec3		forward;
	t_vec3		up;
	t_vec3		from;
	char		*config[4];
	t_sphere	*floor;
	t_sphere	*left_wall;
	t_sphere	*right_wall;
	t_sphere	*sp_middle;
	t_sphere	*sp_right;
	t_sphere	*sp_left;

	from = vec3(0, 1.5, -5);
	forward = normalize(sub(vec3(0, 1, 0), from));
	up = vec3(0, 1, 0);
	world.cam.fov = M_PI / 3;
	set_pixel_size(&world.cam);
	world.cam.t = view_transform(from, forward, up);

	world.light = point_light(point(-10, 10, -10), 1);
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

	floor->transform = scaling_matrix(point(10, 0.01, 10));
	floor->inv_transform = inverse(floor->transform);
	floor->material.specular = 0;
	floor->material.color = color(1, 0.9, 0.9);

	left_wall->transform = multiply_matrix(multiply_matrix(multiply_matrix(translation_matrix(point(0, 0, 5)), rotate_y_matrix(-M_PI/4)), rotate_x_matrix(M_PI/2)), scaling_matrix(point(10, 0.01, 10)));
	left_wall->inv_transform = inverse(left_wall->transform);
	left_wall->material = floor->material;

	right_wall->transform = multiply_matrix(multiply_matrix(multiply_matrix(translation_matrix(point(0, 0, 5)), rotate_y_matrix(M_PI/4)), rotate_x_matrix(M_PI/2)), scaling_matrix(point(10, 0.01, 10)));
	right_wall->inv_transform = inverse(right_wall->transform);
	right_wall->material = floor->material;

	sp_middle->transform = translation_matrix(point(-0.5, 1, 0.5));
	sp_middle->inv_transform = inverse(sp_middle->transform);
	sp_middle->material.color = color(0.1, 1, 0.5);
	sp_middle->material.diffuse = 0.7;
	sp_middle->material.specular = 0.3;

	sp_right->transform = multiply_matrix(translation_matrix(point(1.5, 0.5, -0.5)), scaling_matrix(point(0.5, 0.5, 0.5)));
	sp_right->inv_transform = inverse(sp_right->transform);
	sp_right->material.color = color(0.5, 1, 0.1);
	sp_right->material.diffuse = 0.7;
	sp_right->material.specular = 0.3;

	sp_left->transform = multiply_matrix(translation_matrix(point(-1.5, 0.33, -0.75)), scaling_matrix(point(0.33, 0.33, 0.33)));
	sp_left->inv_transform = inverse(sp_left->transform);
	sp_left->material.color = color(1, 0.8, 0.1);
	sp_left->material.diffuse = 0.7;
	sp_left->material.specular = 0.3;

	hittable_add("sp", floor, &world.objects);
	hittable_add("sp", left_wall, &world.objects);
	hittable_add("sp", right_wall, &world.objects);
	hittable_add("sp", sp_middle, &world.objects);
	hittable_add("sp", sp_right, &world.objects);
	hittable_add("sp", sp_left, &world.objects);
	return (world);
}
