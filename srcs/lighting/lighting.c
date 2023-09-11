/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:23:43 by revieira          #+#    #+#             */
/*   Updated: 2023/09/11 15:56:36 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

static t_color	compute_color(t_color colors[3], t_comps comps, t_amb_light amb)
{
	t_color	color;
	t_color	amb_color;

	amb_color = s_multiply(amb.color, amb.light_ratio);
	color = add(colors[AMBIENT], add(colors[DIFFUSE], colors[SPECULAR]));
	color = add(color, multiply(get_color(comps.object), amb_color));
	return (color);
}

t_color	lighting(t_light light, t_comps comps, t_world world, int is_shadowed)
{
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	double		reflect_dot_eye;
	double		light_dot_normal;

	reflect_dot_eye = 0.0;
	diffuse = (t_color){0, 0, 0};
	specular = (t_color){0, 0, 0};
	ambient = compute_ambient(light, comps);
	if (is_shadowed)
		return (compute_color(ambient, diffuse, specular, comps, world));
	light_dot_normal = compute_light_dot_normal(light, comps);
	if (light_dot_normal >= 0)
	{
		diffuse = compute_diffuse(light, light_dot_normal, comps);
		reflect_dot_eye = compute_reflect_dot_eye(light, comps);
	}
	if (reflect_dot_eye > 0)
		specular = compute_specular(reflect_dot_eye, comps, light);
	return (compute_color(ambient, diffuse, specular, comps, world));
}
