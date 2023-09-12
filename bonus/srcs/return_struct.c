/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:29:54 by revieira          #+#    #+#             */
/*   Updated: 2023/08/21 18:55:14 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt.h"

t_color	color(double r, double g, double b)
{
	return ((t_color){r, g, b});
}

t_point	point(double x, double y, double z)
{
	return ((t_point){x, y, z});
}

t_vec3	vec3(double x, double y, double z)
{
	return ((t_vec3){x, y, z});
}

t_ray	ray(t_point origin, t_vec3 direction)
{
	return ((t_ray){origin, direction});
}
