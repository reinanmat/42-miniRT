/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:11:03 by revieira          #+#    #+#             */
/*   Updated: 2023/06/26 18:16:45 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_point	get_lower_left_corner(t_cam cam)
{
	t_point	lower_left_corner;
	t_point	half_vertical;
	t_point	half_horizontal;
	t_point	aux;

	half_vertical = division_n(cam.vertical, 2);
	half_horizontal = division_n(cam.horizontal, 2);
	aux = minus(minus(cam.origin, half_horizontal), half_vertical);
	lower_left_corner = minus(aux, (t_point){0, 0, cam.focal_length});
	return (lower_left_corner);
}

t_cam	init_cam(void)
{
	t_cam	cam;
	float	aspect_ratio;

	aspect_ratio = 16.0 / 9.0;
	cam.viewport_height = 4.0;
	cam.viemport_width = cam.viewport_height * aspect_ratio;
	cam.focal_length = 1.0;
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

int	main(void)
{
	t_data	data;

	data.mlx = init_mlx();
	data.cam = init_cam();
	render(data);
	mlx_loop(data.mlx.mlx_ptr);
}
