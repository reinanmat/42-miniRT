/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:00:59 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/07 12:01:49 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

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
