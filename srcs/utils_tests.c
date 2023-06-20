/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:22:10 by revieira          #+#    #+#             */
/*   Updated: 2023/06/14 12:22:42 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	print_point(t_point point)
{
	printf("%f %f %f\n", point.x, point.y, point.z);
}

void	print_cam(t_cam cam)
{
	printf("\n");
	printf("origin: ");
	print_point(cam.origin);
	printf("horizontal: ");
	print_point(cam.horizontal);
	printf("vertical: ");
	print_point(cam.vertical);
	printf("lower_left_corner: ");
	print_point(cam.lower_left_corner);
}
