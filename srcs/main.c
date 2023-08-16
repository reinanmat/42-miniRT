/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:11:03 by revieira          #+#    #+#             */
/*   Updated: 2023/08/16 19:02:54 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt.h"

t_material	default_material(void)
{
	t_material	m;

	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;
	return (m);
}

t_color	lighting(t_light light, t_point point, t_vec3 camv, t_vec3 normalv)
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
		reflect_dot_eye = dot(reflectv, camv);
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

t_vec3	normal_at(t_sphere sph, t_point world_point)
{
	t_matrix	inv_matrix;
	t_vec3		world_normal;
	t_point		object_point;
	t_vec3		object_normal;
	t_matrix	normal_as_matrix;

	inv_matrix = inverse(sph.transform);
	object_point = matrix_to_point(multiply_matrix(inv_matrix, point_to_matrix(world_point)));
	object_normal = sub(object_point, point(0, 0, 0));
	normal_as_matrix = point_to_matrix(object_normal);
	world_normal = matrix_to_point(multiply_matrix(transpose_matrix(inv_matrix), normal_as_matrix));
	return (normalize(world_normal));
}

t_light	point_light(t_point pos, double intensity)
{
	t_light	light;

	light.coordinate = pos;
	light.brightness = intensity;
	return (light);
}

t_data	init_data(char *filename)
{
	t_data	data;

	data.world = init_world(filename);
	mlx_create_window(&data.mlx);
	mlx_create_img(&data.mlx);
	mlx_hooks(&data);
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data = init_data(argv[1]);
	render(data);
	if (argc != 2)
		exit(1);
	else if (received_invalid_param(argv[1]))
		exit(1);
	mlx_loop(data.mlx.mlx_ptr);
}
