/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:25:59 by revieira          #+#    #+#             */
/*   Updated: 2023/09/15 20:28:38 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt_bonus.h"

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
	int		i;
	int		shadowed;
	t_color	final_color;
	t_color	color;

	i = 0;
	final_color = (t_color){0, 0, 0};
	while (i < world.amount_of_lights)
	{
		shadowed = is_shadowed(world, world.light[i], comps.over_point);
		color = lighting(world.light[i], comps, world.ambient_light, shadowed);
		final_color = add(final_color, color);
		i++;
	}
	return (final_color);
}

t_color	color_at(t_ray ray, t_world world)
{
	t_color			color;
	t_comps			comps;
	t_intersections	*intersects;

	intersects = intersection_calculate(ray, world.objects);
	if (intersects == NULL || hit(intersects) == NULL)
	{
		clear_intersect(&intersects);
		return ((t_color){0, 0, 0});
	}
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
	render_world(data.world, data.mlx);
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.win_ptr,
		data.mlx.img.mlx_img, 0, 0);
	return (0);
}
