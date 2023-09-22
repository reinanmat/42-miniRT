/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:23:43 by revieira          #+#    #+#             */
/*   Updated: 2023/09/13 16:10:03 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

static t_color	compute_color(t_color colors[3], t_comps comps, t_amb_light amb)
{
	t_color	color;
	t_color	amb_color;
	t_color	object_color;

	object_color = get_color(comps.object, comps.over_point);
	amb_color = s_multiply(amb.color, amb.light_ratio);
	color = add(colors[AMBIENT], add(colors[DIFFUSE], colors[SPECULAR]));
	color = add(color, multiply(object_color, amb_color));
	return (color);
}

t_color	lighting(t_light light, t_comps comps, t_amb_light amb, int shadow)
{
	t_color		colors[3];
	double		reflect_dot_eye;
	double		light_dot_normal;

	reflect_dot_eye = 0.0;
	colors[DIFFUSE] = (t_color){0, 0, 0};
	colors[SPECULAR] = (t_color){0, 0, 0};
	colors[AMBIENT] = compute_ambient(light, comps);
	if (shadow)
		return (compute_color(colors, comps, amb));
	light_dot_normal = compute_light_dot_normal(light, comps);
	if (light_dot_normal >= 0)
	{
		colors[DIFFUSE] = compute_diffuse(light, light_dot_normal, comps);
		reflect_dot_eye = compute_reflect_dot_eye(light, comps);
	}
	if (reflect_dot_eye > 0)
		colors[SPECULAR] = compute_specular(reflect_dot_eye, comps, light);
	return (compute_color(colors, comps, amb));
}
