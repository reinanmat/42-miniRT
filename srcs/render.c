/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:25:59 by revieira          #+#    #+#             */
/*   Updated: 2023/06/20 18:06:33 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	get_ray(double u, double v, t_cam cam)
{
	t_ray	ray;
	t_point	aux1;
	t_point	aux2;

	aux1 = add(cam.lower_left_corner, multiply_n(cam.horizontal, u));
	aux2 = minus(multiply_n(cam.vertical, v), cam.origin);
	ray.direction = add(aux1, aux2);
	ray.origin = cam.origin;
	return (ray);
}

t_point	calculate_point_color(int x, int y, t_cam cam)
{
	double	u;
	double	v;
	t_ray	ray;
	t_point	point_color;

	u = (double)x / (WIDTH - 1);
	v = (double)y / (HEIGHT - 1);
	ray = get_ray(u, v, cam);
	point_color = ray_color(ray);
	return (point_color);
}

void	render_background(t_cam cam, t_mlx mlx)
{
	int		x;
	int		y;
	int		i;
	int		j;
	t_point	point_color;

	j = HEIGHT - 1;
	y = 0;
	while (j >= 0)
	{
		i = 0;
		x = 0;
		while (i < WIDTH - 1)
		{
			point_color = calculate_point_color(i, j, cam);
			mlx_img_pix_put(&mlx.img, x, y, get_color(point_color));
			x++;
			i++;
		}
		y++;
		j--;
	}
}

int	render(t_data data)
{
	render_background(data.cam, data.mlx);
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.win_ptr,
		data.mlx.img.mlx_img, 0, 0);
	return (0);
}
