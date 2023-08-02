/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:22:10 by revieira          #+#    #+#             */
/*   Updated: 2023/08/02 17:39:03 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

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
			print_point(aux->sp->color);
		}
		else if (aux->type == 2)
		{
			print_point(aux->cy->center);
			print_point(aux->cy->vector);
			printf("%f\n", aux->cy->diameter);
			printf("%f\n", aux->cy->height);
			print_point(aux->cy->color);
		}
		else if (aux->type == 3)
		{
			print_point(aux->pl->center);
			print_point(aux->pl->vector);
			print_point(aux->pl->color);
		}
		printf("\n\n");
		aux = aux->next;
	}
}

void	print_point(t_point point)
{
	printf("%f %f %f\n", point.x, point.y, point.z);
}
