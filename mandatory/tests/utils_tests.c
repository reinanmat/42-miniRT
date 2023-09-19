/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:22:10 by revieira          #+#    #+#             */
/*   Updated: 2023/09/19 14:09:35 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt.h"

//remove that file after finishing the project
#include <sys/time.h>
time_t	get_time_miliseconds(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}

void	timer()
{
	static int state = 0;
	static long long init;

	if (state == 0)
		init = get_time_miliseconds();
	else
		printf("%lld ms\n", get_time_miliseconds() - init);
	state = !state;
}

t_light	point_light(t_point pos, double intensity)
{
	t_light	light;

	light.coordinate = pos;
	light.brightness = intensity;
	return (light);
}

void	print_matrix(double matrix[4][4])
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("| ");
			printf("%d\t", (int)matrix[i][j]);
		}
		printf("|\n");
	}
}

void	print_matrix2(t_matrix matrix)
{
	for (int i = 0; i < matrix.rows; ++i) {
		for (int j = 0; j < matrix.cols; ++j) {
			printf("| ");
			printf("%.5f ", (matrix.matr[i][j]));
		}
		printf("|\n");
	}
}

void	print_hittable(t_hittable **hittable)
{
	t_hittable	*aux;

	aux = *hittable;
	while (aux)
	{
		if (aux->type == 1)
		{
			print_point(aux->sp->center);
			printf("%f\n", aux->sp->radius * 2);
			print_point(aux->sp->material.color);
		}
		else if (aux->type == 2)
		{
			print_point(aux->cy->center);
			print_point(aux->cy->vector);
			printf("%f\n", aux->cy->diameter);
			printf("%f\n", aux->cy->height);
			print_point(aux->cy->material.color);
		}
		else if (aux->type == 3)
		{
			print_point(aux->pl->center);
			print_point(aux->pl->vector);
			print_point(aux->pl->material.color);
		}
		printf("\n\n");
		aux = aux->next;
	}
}

void	print_intersects(t_intersections *intersections)
{
	while (intersections)
	{
		printf("%f\n", intersections->t);
		intersections = intersections->next;
	}
}

void	print(char *str1, t_point *p1, char *str2, t_point *p2)
{
	if (str1)
		printf("%s", str1);
	if (p1)
		printf("(%f %f %f)", p1->x, p1->y, p1->z);
	if (str2)
		printf("%s", str2);
	if (p2)
		printf("(%f %f %f)", p2->x, p2->y, p2->z);
	printf("\n");
}

void	print_point(t_point point)
{
	printf("%f %f %f\n", point.x, point.y, point.z);
}
