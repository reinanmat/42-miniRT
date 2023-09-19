/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:23:43 by revieira          #+#    #+#             */
/*   Updated: 2023/09/19 13:56:24 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

static t_color	compute_color(t_color colors[2], t_comps comps, t_amb_light amb)
{
	t_color	color;
	t_color	amb_color;

	amb_color = s_multiply(amb.color, amb.light_ratio);
	color = add(colors[AMBIENT], colors[DIFFUSE]);
	color = add(color, multiply(get_color(comps.object), amb_color));
	return (color);
}

t_color	lighting(t_light light, t_comps comps, t_amb_light amb, int shadow)
{
	t_color		colors[2];
	double		light_dot_normal;

	colors[DIFFUSE] = (t_color){0, 0, 0};
	colors[AMBIENT] = compute_ambient(light, comps);
	if (shadow)
		return (compute_color(colors, comps, amb));
	light_dot_normal = compute_light_dot_normal(light, comps);
	if (light_dot_normal >= 0)
		colors[DIFFUSE] = compute_diffuse(light, light_dot_normal, comps);
	return (compute_color(colors, comps, amb));
}
