/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:22:10 by revieira          #+#    #+#             */
/*   Updated: 2023/07/25 19:46:34 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

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
