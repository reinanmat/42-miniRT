/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:29:24 by revieira          #+#    #+#             */
/*   Updated: 2023/09/28 19:02:15 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

static double	get_world_x(t_cam camera, int x)
{
	double	x_offset;

	x_offset = (x + 0.5) * camera.pixel_size;
	return (camera.viewport_width - x_offset);
}

static double	get_world_y(t_cam camera, int y)
{
	double	y_offset;

	y_offset = (y + 0.5) * camera.pixel_size;
	return (camera.viewport_height - y_offset);
}

static t_point	matr_product_to_point(t_matrix a, t_point b)
{
	t_matrix	product;
	t_matrix	b_to_matr;

	b_to_matr = point_to_matrix(b);
	product = multiply_matrix(a, b_to_matr);
	return (matrix_to_point(product));
}

t_ray	ray_for_pixel(t_cam cam, int x, int y)
{
	t_point		pixel;
	t_point		origin;
	t_vec3		direction;
	t_point		canvas_point;

	canvas_point = point(get_world_x(cam, x), get_world_y(cam, y), -1);
	pixel = matr_product_to_point(cam.inv_transform, canvas_point);
	origin = matr_product_to_point(cam.inv_transform, point(0, 0, 0));
	direction = normalize(sub(pixel, origin));
	return (ray(origin, direction));
}
