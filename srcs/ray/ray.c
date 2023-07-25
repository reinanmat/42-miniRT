/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:08:11 by revieira          #+#    #+#             */
/*   Updated: 2023/07/25 18:43:41 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_ray	get_ray(double u, double v, t_cam cam)
{
	t_point	aux1;
	t_point	aux2;
	t_vec3	direction;

	aux1 = add(cam.lower_left_corner, s_multiply(cam.horizontal, u));
	aux2 = minus(s_multiply(cam.vertical, v), cam.coordinate);
	direction = normalize(add(aux1, aux2));
	return (ray(cam.coordinate, direction));
}
