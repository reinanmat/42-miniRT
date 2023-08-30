/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:23:43 by revieira          #+#    #+#             */
/*   Updated: 2023/08/30 18:14:14 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt.h"

t_color	compute_specular(double reflect_dot_eye, t_comps comps, t_light light)
{
	t_material	material;
	t_color		white;
	double		factor;
	t_color		specular;

	material = get_material(comps.object);
	factor = pow(reflect_dot_eye, material.shininess);
	white = (t_color){1, 1, 1};
	specular = s_multiply(white, light.brightness * material.specular * factor);
	return (specular);
}

double	compute_reflect_dot_eye(t_light light, t_comps comps)
{
	t_vec3	lightv;
	t_vec3	reflectv;
	double	reflect_dot_eye;

	lightv = normalize(sub(light.coordinate, comps.point));
	reflectv = reflect(s_multiply(lightv , -1), comps.normalv);
	reflect_dot_eye = dot(lightv, comps.normalv);
	return (reflect_dot_eye);
}

double	compute_light_dot_normal(t_light light, t_comps comps)
{
	t_vec3	lightv;
	double	light_dot_normal;

	lightv = normalize(sub(light.coordinate, comps.point));
	light_dot_normal = dot(lightv, comps.normalv);
	return (light_dot_normal);
}

t_color	compute_diffuse(t_light light, double light_dot_normal, t_comps comps)
{
	t_color		diffuse;
	t_color		effective_color;
	t_material	material;

	material = get_material(comps.object);
	effective_color = s_multiply(get_color(comps.object), light.brightness);
	diffuse = s_multiply(effective_color, material.diffuse * light_dot_normal);
	return (diffuse);
}

t_color	compute_ambient(t_light light, t_comps comps)
{
	t_color		ambient;
	t_color		effective_color;
	t_material	material;

	material = get_material(comps.object);
	effective_color = s_multiply(get_color(comps.object), light.brightness);
	ambient = s_multiply(effective_color, material.ambient);
	return (ambient);
}

t_color	compute_final_color(t_color ambient, t_color diffuse, t_color specular)
{
	t_color	color;

	color = add(ambient, add(diffuse, specular));
	return (normalize_rgb(color));
}

t_color	lighting(t_light light, t_comps comps)
{
	t_color		diffuse;
	t_color		specular;
	t_color		ambient;
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
	return (compute_final_color(ambient, diffuse, specular));
}
