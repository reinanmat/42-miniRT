/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:25:59 by revieira          #+#    #+#             */
/*   Updated: 2023/08/17 16:28:04 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vec3	reflect(t_vec3 in, t_vec3 normal)
{
	double	dot_product;

	dot_product = dot(in, normal);
	return (sub(in, s_multiply(normal, 2 * dot_product)));
}

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

{
}

static void	render_world(t_world world, t_mlx mlx)
{
	int				x;
	int				y;
	t_ray			r;
	t_point			pos;
	t_point			origin;
	double			pixel_size;
	double			wall_size;
	t_point			apodka;
	t_vec3			normalv;
	t_intersections	*intersects;
	t_vec3			eyev;
	t_color			kolor;

	t_hittable	*object;


	intersects = NULL;
	wall_size = 20.0;
	pixel_size = wall_size / HEIGHT;
	y = 0;
	origin = point(0, 0, -5);
	/* transform_object(world.objects, translation_matrix(point(2, 2, 2))); */
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
				sort_lst(&intersects);
				apodka = position(r, intersects->t);
				object = intersects->object;
				normalv = normal_at(*object->sp, apodka);
				eyev = s_multiply(r.direction, -1);
				kolor = lighting(world.light, origin, eyev, normalv);
				mlx_img_pix_put(&mlx.img, x, y, get_color(kolor));
			}
			clear_intersect(&intersects);
			intersects = NULL;
			x++;
		}
		y++;
	}
	printf("finished\n");
}

int	render(t_data data)
{
	render_world(data.world, data.mlx);
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.win_ptr,
		data.mlx.img.mlx_img, 0, 0);
	return (0);
}
