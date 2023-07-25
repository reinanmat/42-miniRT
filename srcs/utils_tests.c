/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:22:10 by revieira          #+#    #+#             */
/*   Updated: 2023/07/25 18:43:54 by fnacarel         ###   ########.fr       */
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
			print_point(aux->sp->color);
			printf("%f\n", aux->sp->radius);
		}
		aux = aux->next;
	}
}

void	print_point(t_point point)
{
	printf("%f %f %f\n", point.x, point.y, point.z);
}
