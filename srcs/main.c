/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:11:03 by revieira          #+#    #+#             */
/*   Updated: 2023/08/08 16:59:01 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt.h"
#include <mlx.h>

double hit(t_intersections *intersections)
{
	double	min;

	min = INFINITY;
	while (intersections)
	{
		if (intersections->t >= 0 && intersections->t < min)
			min = intersections->t;
		intersections = intersections->next;
	}
	return (min);
}

t_point	position(t_ray ray1, double t)
{
	return (add(ray1.origin, s_multiply(ray1.direction, t)));
}

t_intersection_point	intersect_sphere(t_ray ray, t_sphere *sphere)
{
	t_intersection_point	intersect;
	double	a;
	double	b;
	double	discriminant;
	t_vec3	point_to_sphere;

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

void	intersection_calculate(t_ray ray, void *obj, t_intersections **intersect)
{
	t_intersection_point	inter_p;

	inter_p = intersect_sphere(ray, obj);
	if (inter_p.hit_times == 0)
		return ;
	intersect_add_back(intersect, new_intersect(inter_p.hit[0], obj));
	intersect_add_back(intersect, new_intersect(inter_p.hit[1], obj));
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

int	main(int argc, char **argv)
{
	t_ray			ray1;
	t_sphere		*sph;
	t_data			data;
	t_intersections	*intersections;

	intersections = NULL;
	data = init_data(argv[1]);
	sph = data.world.objects->sp;
	ray1 = ray(point(0, 0, -5), vec3(0, 0, 1));
	intersection_calculate(ray1, sph, &intersections);
	/* ray1 = ray(point(0, 0, -1), vec3(0, 0, 1)); */
	/* intersection_calculate(ray1, sph, &intersections); */
	ray1 = ray(point(0, 0, -4), vec3(0, 0, 1));
	intersection_calculate(ray1, sph, &intersections);
	ray1 = ray(point(0, 0, 4), vec3(0, 0, 1));
	intersection_calculate(ray1, sph, &intersections);
	ray1 = ray(point(0, 0, -3), vec3(0, 0, 1));
	intersection_calculate(ray1, sph, &intersections);
	printf("\n");
	if (0)
		render(data);
	exit(1);
	if (argc != 2)
		exit(1);
	else if (received_invalid_param(argv[1]))
		exit(1);
	mlx_loop(data.mlx.mlx_ptr);
}
