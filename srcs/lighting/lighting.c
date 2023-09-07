/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:23:43 by revieira          #+#    #+#             */
/*   Updated: 2023/09/07 12:05:35 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

static t_color	compute_color(t_color amb, t_color diffuse, t_color specular)
{
	t_color	color;

	color = add(amb, add(diffuse, specular));
	return (color);
}

t_color	lighting(t_light light, t_comps comps)
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
	light_dot_normal = compute_light_dot_normal(light, comps);
	if (light_dot_normal >= 0)
	{
		diffuse = compute_diffuse(light, light_dot_normal, comps);
		reflect_dot_eye = compute_reflect_dot_eye(light, comps);
	}
	if (reflect_dot_eye > 0)
		specular = compute_specular(reflect_dot_eye, comps, light);
	return (compute_color(ambient, diffuse, specular));
}
