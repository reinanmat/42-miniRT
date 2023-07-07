/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:11:03 by revieira          #+#    #+#             */
/*   Updated: 2023/07/21 12:58:34 by fnacarel         ###   ########.fr       */
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

	vertical_fov = 90.0;
	vertical_fov_radians = vertical_fov * PI / 180.0;
	aspect_ratio = 16.0 / 9.0;
	cam.viewport_height = 2.0 * tan(vertical_fov_radians / 2.0);
	cam.viemport_width = cam.viewport_height * aspect_ratio;
	cam.focal_length = 0.5;
	cam.origin = (t_point){0, 0, 0};
	cam.horizontal = (t_point){cam.viemport_width, 0, 0};
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
	data.cam = init_cam();
	render(data, height);
	mlx_loop(data.mlx.mlx_ptr);
}
