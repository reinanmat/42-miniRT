/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_normals_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:42:15 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/23 16:42:47 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_vec3	local_normal_cylinder(t_cylinder *cylinder, t_point local_point)
{
	double	distance;

	distance = local_point.x * local_point.x + local_point.z * local_point.z;
	if (distance < 1 && local_point.y >= cylinder->max - EPSILON)
		return (vec3(0, 1, 0));
	else if (distance < 1 && local_point.y <= cylinder->min + EPSILON)
		return (vec3(0, -1, 0));
	else
		return (vec3(local_point.x, 0, local_point.z));
}

t_vec3	local_normal_cone(t_point local_point)
{
	double	y;
	double	squared_x;
	double	squared_z;

	squared_x = local_point.x * local_point.x;
	squared_z = local_point.z * local_point.z;
	y = sqrt(squared_x + squared_z);
	if (local_point.y > 0)
		y *= -1;
	return (vec3(local_point.x, y, local_point.z));
}
