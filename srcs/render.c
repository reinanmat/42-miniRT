/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:25:59 by revieira          #+#    #+#             */
/*   Updated: 2023/09/11 12:08:47 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt.h"

t_comps	prepare_computations(t_intersections *intersects, t_ray ray)
{
	t_comps			comps;
	t_intersections	*tmp_inter;

	tmp_inter = hit(intersects);
	comps.t = tmp_inter->t;
	comps.point = position(ray, tmp_inter->t);
	comps.eyev = s_multiply(ray.direction, -1);
	comps.normalv = normal_at(tmp_inter->object, comps.point);
	comps.object = tmp_inter->object;
	if (dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = 1;
		comps.normalv = s_multiply(comps.normalv, -1);
	}
	else
		comps.inside = 0;
	comps.over_point = add(comps.point, s_multiply(comps.normalv, EPSILON));
	return (comps);
}

t_color	shade_hit(t_world world, t_comps comps)
{
	t_color	color;
	int		shadowed;

	shadowed = is_shadowed(world, comps.over_point);
	if (shadowed)
		return ((t_color){0.1, 0.1, 0.1});
	color = lighting(world.light, comps, world);
	return (color);
}

t_color	color_at(t_ray ray, t_world world)
{
	t_color			color;
	t_comps			comps;
	t_intersections	*intersects;

	intersects = intersection_calculate(ray, world.objects);
	if (intersects == NULL || hit(intersects) == NULL)
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
	t_color	color;

	y = 0;
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
	data.world = room();
	render_world(data.world, data.mlx);
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.win_ptr,
		data.mlx.img.mlx_img, 0, 0);
	return (0);
}
