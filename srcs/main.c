/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:11:03 by revieira          #+#    #+#             */
/*   Updated: 2023/07/21 17:59:01 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_point	get_lower_left_corner(t_cam cam)
{
	t_point	lower_left_corner;
	t_point	half_vertical;
	t_point	half_horizontal;
	t_point	aux;

	half_vertical = s_division(cam.vertical, 2);
	half_horizontal = s_division(cam.horizontal, 2);
	aux = minus(minus(cam.origin, half_horizontal), half_vertical);
	lower_left_corner = minus(aux, (t_point){0, 0, cam.focal_length});
	return (lower_left_corner);
}

t_cam	init_cam(void)
{
	t_cam	cam;
	double	aspect_ratio;
	double	vertical_fov;
	double	vertical_fov_radians;

	vertical_fov = 120.0;
	vertical_fov_radians = vertical_fov * PI / 180.0;
	aspect_ratio = 16.0 / 9.0;
	cam.viewport_height = 2.0 * tan(vertical_fov_radians / 2.0);
	cam.viewport_width = cam.viewport_height * aspect_ratio;
	cam.focal_length = 1.0;
	cam.viewport_height = 4.0;
	cam.origin = (t_point){0, 0, 0};
	cam.horizontal = (t_point){cam.viewport_width, 0, 0};
	cam.vertical = (t_point){0, cam.viewport_height, 0};
	cam.lower_left_corner = get_lower_left_corner(cam);
	return (cam);
}

t_mlx	init_mlx(void)
{
	t_mlx	mlx;

	mlx_create_window(&mlx);
	mlx_create_img(&mlx);
	mlx_hooks(&mlx);
	return (mlx);
}

t_light	init_light(t_color color)
{
	t_light	light;

	light.position = (t_point){0, 0, 0};
	light.color = color;
	light.brightness = 0.5;
	return (light);
}

t_hittable	*add_objects(void)
{
	t_hittable	*objects;
	t_sphere	*sp1;
	t_sphere	*floor;

	objects = NULL;
	sp1 = sp((t_point){0, 0, -1}, 0.75, (t_color){0, 0, 1});
	floor = sp((t_point){0, -1000.5, 0}, 999.5, (t_color){0, 0, 1});
	hittable_add(1, sp1, &objects);
	hittable_add(1, floor, &objects);
	return (objects);
}

t_world	init_world(void)
{
	t_world		world;

	world.cam = init_cam();
	world.light = init_light((t_point){1, 1, 1});
	world.ambient_light = init_light((t_point){0, 1, 1});
	world.objects = add_objects();
	return (world);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		height;

	if (argc != 2)
		exit (1);
	else if (received_invalid_param(argv[1]))
		exit(1);
	printf("Success\n");
	exit(0);
	height = (WIDTH / 16) * 9;
	data.mlx = init_mlx();
	data.world = init_world();
	render(data);
	mlx_loop(data.mlx.mlx_ptr);
}
