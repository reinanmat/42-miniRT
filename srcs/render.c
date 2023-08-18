/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:25:59 by revieira          #+#    #+#             */
/*   Updated: 2023/08/18 17:42:11 by revieira         ###   ########.fr       */
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
	return (comps);
}

t_color	calculate_color(t_world world, t_ray ray, t_intersections *intersects)
{
	t_color	color;
	t_comps	comps;

	comps = prepare_computations(intersects, ray);
	color = lighting(world.light, ray.origin, comps);
	return (color);
}

t_color	ray_color(t_ray ray, t_world world)
{
	t_color			color;
	t_intersections	*intersects;

	color = point(0, 0, 0);
	intersects = intersection_calculate(ray, world.objects);
	if (intersects != NULL)
		color = calculate_color(world, ray, intersects);
	clear_intersect(&intersects);
	return (color);
}

static t_ray	get_ray(int x, int y, t_point origin)
{
	t_ray	ray;
	t_point	pos;
	double	pixel_size;
	double	wall_size;

	wall_size = 20.0;
	pixel_size = wall_size / HEIGHT;
	pos = point(-wall_size/2 + x * pixel_size, wall_size/2 - y * pixel_size, wall_size);
	ray.origin = origin;
	ray.direction = normalize(sub(pos, origin));
	return (ray);
}

static void	render_world(t_world world, t_mlx mlx)
{
	int		x;
	int		y;
	t_ray	ray;
	t_point	origin;
	t_color	color;

	y = 0;
	origin = point(0, 0, -5);
	timer();
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = get_ray(x, y, origin);
			color = ray_color(ray, world);
			mlx_img_pix_put(&mlx.img, x, y, rgb_color(color));
			x++;
		}
		y++;
	}
	timer();
	printf("finished\n");
}

int	render(t_data data)
{
	render_world(data.world, data.mlx);
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.win_ptr,
		data.mlx.img.mlx_img, 0, 0);
	return (0);
}
