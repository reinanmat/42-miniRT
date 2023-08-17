/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:23:43 by revieira          #+#    #+#             */
/*   Updated: 2023/08/17 15:25:33 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_color	lighting(t_light light, t_point point, t_vec3 eyev, t_vec3 normalv)
{
	t_color		color;
	t_color		effective_color;
	t_color		diffuse;
	t_color		specular;
	t_color		ambient;
	t_vec3		lightv;
	t_vec3		reflectv;
	double		reflect_dot_eye;
	double		light_dot_normal;
	double		factor;
	t_material	material;

	material = default_material();
	effective_color = s_multiply((t_color){1, 0.2, 1}, light.brightness);
	lightv = normalize(sub(light.coordinate, point));
	ambient = s_multiply(effective_color, material.ambient);
	light_dot_normal = dot(lightv, normalv);
	reflect_dot_eye = 0.0;
	if (light_dot_normal < 0)
	{
		diffuse = (t_color){0, 0, 0};
		specular = (t_color){0, 0, 0};
	}
	else
	{
		diffuse = s_multiply(effective_color, material.diffuse * light_dot_normal);
		reflectv = reflect(s_multiply(lightv , -1), normalv);
		reflect_dot_eye = dot(reflectv, eyev);
	}
	if (reflect_dot_eye <= 0)
		specular = (t_color){0, 0, 0};
	else
	{
		factor = pow(reflect_dot_eye, material.shininess);
		specular = s_multiply((t_color){1, 1, 1}, light.brightness * material.specular * factor);
	}
	color = add(ambient, add(diffuse, specular));
	return (color);
}
