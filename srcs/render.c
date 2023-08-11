/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:25:59 by revieira          #+#    #+#             */
/*   Updated: 2023/08/11 15:26:25 by revieira         ###   ########.fr       */
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

static void	render_world3(t_world world, t_mlx mlx)
{
	int				x;
	int				y;
	t_ray			r;
	t_point			pos;
	t_point			origin;
	double			pixel_size;
	double			wall_size;
	t_intersections	*intersects;

	t_hittable	*object;

	time_t	begin, end;
	begin = get_time_miliseconds();

	intersects = NULL;
	wall_size = 20.0;
	pixel_size = wall_size / HEIGHT;
	y = 0;
	origin = point(0, 0, -5);
	transform_object(world.objects, scaling_matrix(point(1.5, 1, 2)));
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pos = point(-wall_size/2 + x * pixel_size, wall_size/2 - y * pixel_size, wall_size);
			r = ray(origin, normalize(sub(pos, origin)));
			intersection_calculate(r, world.objects, &intersects);
			if (intersects != NULL)
			{
				object = intersects->object;
				mlx_img_pix_put(&mlx.img, x, y, get_color(object->sp->color));
			}
			clear_intersect(&intersects);
			intersects = NULL;
			x++;
		}
		y++;
	}
	end = get_time_miliseconds();
	printf("Rendered in %lu ms\n", end - begin);
}

int	render(t_data data)
{
	render_world3(data.world, data.mlx);
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.win_ptr,
		data.mlx.img.mlx_img, 0, 0);
	return (0);
}
