/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:25:59 by revieira          #+#    #+#             */
/*   Updated: 2023/08/28 15:33:12 by revieira         ###   ########.fr       */
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
	if (dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = 1;
		comps.normalv = s_multiply(comps.normalv, -1);
	}
	else
		comps.inside = 0;
	return (comps);
}

t_color	shade_hit(t_world world, t_comps comps)
{
	t_color	color;

	color = lighting(world.light, comps);
	return (color);
}

t_color	color_at(t_ray ray, t_world world)
{
	t_color			color;
	t_comps			comps;
	t_intersections	*intersects;

	intersects = intersection_calculate(ray, world.objects);
	if (intersects == NULL)
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

int	render(t_data data)
{
	render_world(data.world, data.mlx);
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.win_ptr,
		data.mlx.img.mlx_img, 0, 0);
	return (0);
}
