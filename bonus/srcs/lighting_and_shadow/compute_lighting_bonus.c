/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:00:59 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/25 16:43:08 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_color	compute_specular(double reflect_dot_eye, t_comps comps, t_light light)
{
	t_material	m;
	double		factor;
	t_color		specular;

	m = get_material(comps.object);
	factor = pow(reflect_dot_eye, m.shininess);
	specular = s_multiply(light.color, light.brightness * m.specular * factor);
	return (specular);
}

double	compute_reflect_dot_eye(t_light light, t_comps comps)
{
	t_vec3	lightv;
	t_vec3	reflectv;
	double	reflect_dot_eye;

	lightv = normalize(sub(light.coordinate, comps.over_point));
	reflectv = reflect(s_multiply(lightv, -1), comps.normalv);
	reflect_dot_eye = dot(reflectv, comps.eyev);
	return (reflect_dot_eye);
}

double	compute_light_dot_normal(t_light light, t_comps comps)
{
	t_vec3	lightv;
	double	light_dot_normal;

	lightv = normalize(sub(light.coordinate, comps.over_point));
	light_dot_normal = dot(lightv, comps.normalv);
	return (light_dot_normal);
}

t_color	compute_diffuse(t_light light, double light_dot_normal, t_comps comps)
{
	t_color		diffuse;
	t_color		effective_color;
	t_color		object_color;
	t_color		light_color;
	t_material	m;

	m = get_material(comps.object);
	object_color = get_color(comps.object, comps.over_point);
	light_color = s_multiply(light.color, light.brightness);
	effective_color = multiply(object_color, light_color);
	diffuse = s_multiply(effective_color, m.diffuse * light_dot_normal);
	return (diffuse);
}

t_color	compute_ambient(t_light light, t_comps comps)
{
	t_color		ambient;
	t_color		effective_color;
	t_color		object_color;
	t_color		light_color;
	t_material	m;

	m = get_material(comps.object);
	object_color = get_color(comps.object, comps.over_point);
	light_color = s_multiply(light.color, light.brightness);
	effective_color = multiply(object_color, light_color);
	ambient = s_multiply(effective_color, m.ambient);
	return (ambient);
}
