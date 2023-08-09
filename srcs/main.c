/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:11:03 by revieira          #+#    #+#             */
/*   Updated: 2023/08/09 17:12:55 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt.h"

t_intersections	*hit(t_intersections *intersections)
{
	double			min;
	t_intersections	*intersect;

	intersect = NULL;
	min = INFINITY;
	while (intersections)
	{
		if (intersections->t >= 0 && intersections->t < min)
			intersect = intersections;
		intersections = intersections->next;
	}
	return (intersect);
}

t_point	position(t_ray ray1, double t)
{
	return (add(ray1.origin, s_multiply(ray1.direction, t)));
}

t_intersection_point	intersect_sphere(t_ray ray, t_sphere *sphere)
{
	t_intersection_point	intersect;
	double					a;
	double					b;
	double					discriminant;
	t_vec3					point_to_sphere;

	intersect.hit_times = 0;
	point_to_sphere = minus(ray.origin, sphere->center);
	a = dot(ray.direction, ray.direction);
	b = 2 * dot(ray.direction, point_to_sphere);
	discriminant = (b * b) - 4 * a * (dot(point_to_sphere, point_to_sphere) - 1);
	if (discriminant < 0)
		return (intersect);
	intersect.hit_times = 2;
	intersect.hit[0] = (-b - sqrt(discriminant)) / (2 * a);
	intersect.hit[1] = (-b + sqrt(discriminant)) / (2 * a);
	intersect.object = sphere;
	return (intersect);
}

t_data	init_data(char *filename)
{
	t_data	data;

	data.world = init_world(filename);
	mlx_create_window(&data.mlx);
	mlx_create_img(&data.mlx);
	mlx_hooks(&data);
	return (data);
}

void	set_transform(t_hittable *object, t_matrix new_transform)
{
	if (object->type == 1)
		object->sp->transform = multiply_matrix(object->sp->transform, new_transform);
	if (object->type == 2)
		object->cy->transform = multiply_matrix(object->cy->transform, new_transform);
	if (object->type == 3)
		object->pl->transform = multiply_matrix(object->pl->transform, new_transform);
}

void	print_intersects(t_intersections *intersections)
{
	while (intersections)
	{
		printf("%f\n", intersections->t);
		intersections = intersections->next;
	}
}

t_ray	transform_ray(t_ray	ray, t_matrix transform)
{
	t_ray	new_ray;

	new_ray = ray;
	apply_transformation_point(&new_ray.origin, transform);
	apply_transformation_vec(&new_ray.direction, transform);
	return (new_ray);
}

void	intersection_calculate(t_ray ray, t_hittable *objects, t_intersections **intersect)
{
	t_ray					tmp_ray;
	t_intersection_point	inter_p;

	while (objects)
	{
		if (objects->type == 1)
		{
			tmp_ray = transform_ray(ray, inverse(objects->sp->transform));
			inter_p = intersect_sphere(tmp_ray, objects->sp);
			if (inter_p.hit_times != 0)
			{
				intersect_add_back(intersect, new_intersect(inter_p.hit[0], objects));
				intersect_add_back(intersect, new_intersect(inter_p.hit[1], objects));
			}
		}
		objects = objects->next;
	}
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
