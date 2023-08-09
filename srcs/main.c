/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:11:03 by revieira          #+#    #+#             */
/*   Updated: 2023/08/09 18:18:37 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt.h"

t_data	init_data(char *filename)
{
	t_data	data;

	data.world = init_world(filename);
	mlx_create_window(&data.mlx);
	mlx_create_img(&data.mlx);
	mlx_hooks(&data);
	return (data);
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

	intersects = NULL;
	wall_size = 20.0;
	pixel_size = wall_size / HEIGHT;
	y = 0;
	origin = point(0, 0, -5);
	/* set_transform(world.objects, translation_matrix(point(2, 0, 2))); */
	/* set_transform(world.objects, rotate_x_matrix(M_PI / 4)); */
	/* set_transform(world.objects, rotate_y_matrix(M_PI / 4)); */
	/* set_transform(world.objects->next, translation_matrix(point(-2, 0, 2))); */
	/* set_transform(world.objects->next, inverse(rotate_y_matrix(M_PI / 4))); */
	/* set_transform(world.objects->next, inverse(rotate_x_matrix(M_PI / 4))); */
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pos = point(-wall_size/2 + x * pixel_size, wall_size/2 - y * pixel_size, wall_size);
			r = ray(origin, normalize(minus(pos, origin)));
			intersection_calculate(r, world.objects, &intersects);
			if (intersects != NULL)
			{
				object = hit(intersects)->object;
				mlx_img_pix_put(&mlx.img, x, y, get_color(object->sp->color));
			}
			clear_intersect(&intersects);
			intersects = NULL;
			x++;
		}
		y++;
	}
	printf("Rendered\n");
}

int	render(t_data data)
{
	render_world3(data.world, data.mlx);
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.win_ptr,
		data.mlx.img.mlx_img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;

	data = init_data(argv[1]);
	render(data);
	if (argc != 2)
		exit(1);
	else if (received_invalid_param(argv[1]))
		exit(1);
	mlx_loop(data.mlx.mlx_ptr);
}
