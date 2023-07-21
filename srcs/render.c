/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:25:59 by revieira          #+#    #+#             */
/*   Updated: 2023/07/21 18:34:45 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_color	calculate_ray_color(int x, int y, t_world world)
{
	double	u;
	double	v;
	t_ray	ray;
	t_color	color;

	u = (double)x / WIDTH;
	v = (double)y / HEIGHT;
	ray = get_ray(u, v, world.cam);
	color = ray_color(ray, world);
	return (color);
}

void	render_world(t_world world, t_mlx mlx)
{
	int		x;
	int		y;
	t_color	ray_color;

	y = HEIGHT;
	while (y >= 0)
	{
		x = 0;
		while (x <= WIDTH)
		{
			ray_color = calculate_ray_color(x, y, world);
			mlx_img_pix_put(&mlx.img, x, HEIGHT - y, get_color(ray_color));
			x++;
		}
		y--;
	}
}

int	render(t_data data)
{
	render_world(data.world, data.mlx);
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.win_ptr,
		data.mlx.img.mlx_img, 0, 0);
	return (0);
}
