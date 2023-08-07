/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:11:03 by revieira          #+#    #+#             */
/*   Updated: 2023/08/07 19:32:24 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

typedef struct s_intersections
{
	double	t;
	void	*object;
	void	*next;
}	t_intersections;

typedef struct s_intersection_point
{
	int		hit_times;
	double	hit[2];
	void	*object;
}	t_intersection_point;

t_intersections	*lstlast(t_intersections *lst)
{
	if (!lst)
		return (0);
	while (lst -> next != 0)
		lst = lst -> next;
	return (lst);
}

void	lstclear(t_intersections **lst)
{
	t_intersections	*store_previous_node;

	store_previous_node = *lst;
	while (*lst != 0 && store_previous_node != 0)
	{
		store_previous_node = *lst;
		*lst = (*lst)->next;
		ft_free(store_previous_node);
	}
	lst = NULL;
}

t_intersections	*lstnew(double t, void *object)
{
	t_intersections	*new_node;

	new_node = (malloc(sizeof(t_node)));
	if (!new_node)
		return (0);
	new_node->t = t;
	new_node->object = object;
	new_node->next = NULL;
	return (new_node);
}

void	lstadd_back(t_intersections **lst, t_intersections *new)
{
	t_intersections	*last_node;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last_node = lstlast(*lst);
			last_node -> next = new;
		}
	}
}

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
	lstadd_back(intersect, lstnew(inter_p.hit[0], obj));
	lstadd_back(intersect, lstnew(inter_p.hit[1], obj));
}

void	print_intersection_pointsect(t_intersections *intersect)
{
	while (intersect)
	{
		printf("%f\n", intersect->t);
		intersect = intersect->next;
	}
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
	t_data	data;

	if (argc != 2)
		exit(1);
	else if (received_invalid_param(argv[1]))
		exit(1);
	data = init_data(argv[1]);
	render(data);
	mlx_loop(data.mlx.mlx_ptr);
}
