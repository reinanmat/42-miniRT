/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:38:15 by revieira          #+#    #+#             */
/*   Updated: 2023/09/25 15:11:09 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

static t_color	uv_texture_at(t_texture texture, double u, double v)
{
	int	x;
	int	y;

	if (u > 1 || u < 0 || v > 1 || v < 0)
	{
		printf("error\nu:%f	v:%f\n", u, v);
		exit(1);
	}
	v = 1 - v;
	x = floor(u * (texture.width - 1));
	y = floor(v * (texture.height - 1));
	return (texture.map_texture[y][x]);
}

t_color	sphere_map(t_texture texture, t_point point)
{
	double	u;
	double	v;
	double	radius;
	double	phi;
	double	raw_u;

	raw_u = atan2(point.x, point.z) / (2 * M_PI);
	radius = magnitude(point);
	phi = acos(point.y / radius);
	u = 1 - (raw_u + 0.5);
	v = 1 - phi / M_PI;
	return (uv_texture_at(texture, u, v));
}

t_color	plane_map(t_texture texture, t_point point)
{
	double	u;
	double	v;

	point.x = point.x - floor(point.x);
	point.z = point.z - floor(point.z);
	u = fmod(point.x, 1.0);
	v = fmod(point.z, 1.0);
	return (uv_texture_at(texture, u, v));
}

t_color	cylinder_and_cone_map(t_texture texture, t_point point)
{
	double	u;
	double	v;
	double	theta;
	double	raw_u;

	theta = atan2(point.x, point.z);
	raw_u = theta / (2 * M_PI);
	u = 1 - (raw_u + 0.5);
	point.y = point.y - floor(point.y);
	v = fmod(point.y, 1);
	return (uv_texture_at(texture, u, v));
}
