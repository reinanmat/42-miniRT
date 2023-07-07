/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:25:59 by revieira          #+#    #+#             */
/*   Updated: 2023/07/21 12:58:53 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_point	ray_color(t_ray ray)
{
	t_point	direction;
	t_point	color;
	t_point	aux1;
	t_point	aux2;
	double	t;

	t = hit_sphere((t_point){0, 0, -1}, 0.7, ray);
	if (t > 0)
	{
		aux1 = normalize(minus(at(ray, t), (t_point){0, 0, -1}));
		color = s_multiply((t_point){aux1.x + 1, aux1.y + 1, aux1.z + 1}, 0.5);
		return (color);
	}
	direction = normalize(ray.direction);
	t = 0.5 * (direction.y + 1.0);
	aux1 = s_multiply((t_point){1.0, 1.0, 1.0}, (1.0 - t));
	aux2 = s_multiply((t_point){0.5, 0.7, 1.0}, t);
	color = add(aux1, aux2);
	return (color);
}

t_ray	get_ray(double u, double v, t_cam cam)
{
	t_ray	ray;
	t_point	aux1;
	t_point	aux2;

	aux1 = add(cam.lower_left_corner, s_multiply(cam.horizontal, u));
	aux2 = minus(s_multiply(cam.vertical, v), cam.origin);
	ray.direction = add(aux1, aux2);
	ray.origin = cam.origin;
	return (ray);
}

t_point	calculate_point_color(int x, int y, t_cam cam, int height)
{
	double	u;
	double	v;
	t_ray	ray;
	t_point	point_color;

	u = (double)x / (WIDTH - 1);
	v = (double)y / (height - 1);
	ray = get_ray(u, v, cam);
	point_color = ray_color(ray);
	return (point_color);
}

void	render_background(t_cam cam, t_mlx mlx, int height)
{
	int		x;
	int		y;
	int		i;
	int		j;
	t_point	point_color;

	j = height - 1;
	y = 0;
	while (j >= 0)
	{
		i = 0;
		x = 0;
		while (i < WIDTH - 1)
		{
			point_color = calculate_point_color(i, j, cam, height);
			mlx_img_pix_put(&mlx.img, x, y, get_color(point_color));
			x++;
			i++;
		}
		y++;
		j--;
	}
}

int	render(t_data data, int height)
{
	render_background(data.cam, data.mlx, height);
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.win_ptr,
		data.mlx.img.mlx_img, 0, 0);
	return (0);
}
