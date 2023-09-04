/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:25:59 by revieira          #+#    #+#             */
/*   Updated: 2023/09/04 19:33:38 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt.h"

t_comps	prepare_computations(t_intersections *intersects, t_ray ray)
{
	t_comps			comps;
	t_intersections	*tmp_inter;

	tmp_inter = hit(intersects);
	comps.t = tmp_inter->t;
	comps.point = position(ray, tmp_inter->t);
	comps.eyev = s_multiply(ray.direction, -1);
	comps.normalv = normal_at(tmp_inter->object, comps.point);
	comps.object = tmp_inter->object;
	if (dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = 1;
		comps.normalv = s_multiply(comps.normalv, -1);
	}
	else
		comps.inside = 0;
	comps.over_point = add(comps.point, s_multiply(comps.normalv, EPSILON));
	return (comps);
}

t_color	shade_hit(t_world world, t_comps comps)
{
	t_color	color;
	int		shadowed;

	shadowed = is_shadowed(world, comps.over_point);
	if (shadowed)
		return ((t_color){0.1, 0.1, 0.1});
	color = lighting(world.light, comps);
	return (color);
}

t_color	color_at(t_ray ray, t_world world)
{
	t_color			color;
	t_comps			comps;
	t_intersections	*intersects;

	intersects = intersection_calculate(ray, world.objects);
	if (intersects == NULL || hit(intersects) == NULL)
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

t_world	test(void)
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

	from = vec3(0, 0.1, 0);
	forward = vec3(-1, 0, 0);
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
	wall_right->transform = multiply_matrix(translation_matrix(point(0, 0, 5)), rotate_x_matrix(M_PI/2));

	wall_left = plane(config);
	wall_left->material.color = color(1, 1, 0);
	wall_left->transform = multiply_matrix(translation_matrix(point(0, 0, -5)), rotate_x_matrix(M_PI/2));

	wall = plane(config);
	wall->material.color = color(1, 0, 0);
	wall->transform = multiply_matrix(rotate_x_matrix(M_PI/2), rotate_y_matrix(M_PI/2));
	/* wall->transform = multiply_matrix(multiply_matrix(rotate_x_matrix(M_PI/2), rotate_y_matrix(M_PI/2)), translation_matrix(point(1, 0, 0))); */
	/* wall->transform = multiply_matrix(multiply_matrix(translation_matrix(point(10, 0, 0)), rotate_x_matrix(M_PI/2)), rotate_y_matrix(M_PI/2)); */

	config[0] = "sp";
	config[1] = "0,0,0";
	config[2] = "2";
	config[3] = "255,255,255";
	t_sphere	*sp = sphere(config);
	sp->material.color = color(1, 0, 0);
	sp->transform = translation_matrix(point(0, 0, -5));
	
	hittable_add("pl", floor, &world.objects);
	hittable_add("pl", roof, &world.objects);
	/* hittable_add("pl", wall, &world.objects); */
	hittable_add("pl", wall_left, &world.objects);
	hittable_add("pl", wall_right, &world.objects);
	/* hittable_add("sp", sp, &world.objects); */
	return (world);
}

int	render(t_data data)
{
	render_world(test(), data.mlx);
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.win_ptr,
		data.mlx.img.mlx_img, 0, 0);
	return (0);
}
