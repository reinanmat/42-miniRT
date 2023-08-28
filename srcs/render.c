/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:25:59 by revieira          #+#    #+#             */
/*   Updated: 2023/08/28 15:42:27 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt.h"

t_comps	prepare_computations(t_intersections *intersects, t_ray ray)
{
	t_comps comps;

	comps.t = intersects->t;
	comps.point = position(ray, intersects->t);
	comps.eyev = s_multiply(ray.direction, -1);
	comps.normalv = normal_at(intersects->object, comps.point);
	comps.object = intersects->object;
	if (dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = 1;
		comps.normalv = s_multiply(comps.normalv, -1);
	}
	else
		comps.inside = 0;
	return (comps);
}

t_color	shade_hit(t_world world, t_comps comps)
{
	t_color	color;

	color = lighting(world.light, comps);
	return (color);
}

t_color	color_at(t_ray ray, t_world world)
{
	t_color			color;
	t_comps			comps;
	t_intersections	*intersects;

	intersects = intersection_calculate(ray, world.objects);
	if (intersects == NULL)
		return ((t_color){0, 0, 0});
	comps = prepare_computations(intersects, ray);
	clear_intersect(&intersects);
	color = shade_hit(world, comps);
	return (color);
}

static void	render_world(t_world world, t_mlx mlx)
{
	int		x;
	int		y;
	t_ray	ray;
	t_color	color;

	y = 0;
	timer();
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = ray_for_pixel(world.cam, x, y);
			color = color_at(ray, world);
			mlx_img_pix_put(&mlx.img, x, y, rgb_color(color));
			x++;
		}
		y++;
	}
	timer();
	printf("finished\n");
}

t_world	default_world()
{
	t_world		world;
	char		*config[4];
	t_sphere	*sp1;
	t_sphere	*sp2;

	world.light = point_light(point(-10, 10, -10), 1);
	world.objects = NULL;
	config[0] = "sp";
	config[1] = "0,0,0";
	config[2] = "2";
	config[3] = "204, 255, 153";
	sp1 = sphere(config);
	sp1->material.diffuse = 0.7;
	sp1->material.specular = 0.2;
	config[0] = "sp";
	config[1] = "0,0,0";
	config[2] = "2";
	config[3] = "255, 255, 255";
	sp2 = sphere(config);
	sp2->transform = scaling_matrix(point(0.5, 0.5, 0.5));
	hittable_add("sp", sp1, &world.objects);
	hittable_add("sp", sp2, &world.objects);
	return (world);
}

t_world	test_scene(void)
{
	t_world		world;
	t_vec3		to;
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
	to = vec3(0, 1, 0);
	up = vec3(0, 1, 0);
	world.cam.fov = M_PI / 3;
	set_pixel_size(&world.cam);
	world.cam.t = view_transform(from, to, up);

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

	hittable_add("sp", floor, &world.objects);
	hittable_add("sp", left_wall, &world.objects);
	hittable_add("sp", right_wall, &world.objects);
	hittable_add("sp", sp_middle, &world.objects);
	hittable_add("sp", sp_right, &world.objects);
	hittable_add("sp", sp_left, &world.objects);
	return (world);
}

int	render(t_data data)
{
	t_world	world;

	world = test_scene();
	render_world(world, data.mlx);
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.win_ptr,
		data.mlx.img.mlx_img, 0, 0);
	return (0);
}
