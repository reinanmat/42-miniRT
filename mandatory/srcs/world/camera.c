/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:29:27 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/28 19:00:14 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

void	set_pixel_size(t_cam *camera)
{
	double	aspect;
	double	half_view;

	half_view = tan(camera->fov / 2);
	aspect = (double) WIDTH / HEIGHT;
	camera->viewport_width = half_view * aspect;
	camera->viewport_height = half_view;
	if (aspect >= 1)
	{
		camera->viewport_width = half_view;
		camera->viewport_height = half_view / aspect;
	}
	camera->pixel_size = (camera->viewport_width * 2) / WIDTH;
}

static double	degrees_to_radians(double degress)
{
	double	radians;

	radians = degress / 180.0 * M_PI;
	return (radians);
}

static t_vec3	get_correct_up(t_vec3 orientation_vec)
{
	t_vec3	up;
	double	dot_prod;

	up = vec3(0, 1, 0);
	dot_prod = dot(orientation_vec, up);
	if (double_equals(dot_prod, 1))
		up = vec3(1, 0, 0);
	else if (double_equals(dot_prod, -1))
		up = vec3(-1, 0, 0);
	return (up);
}

t_cam	init_camera(char **lines)
{
	t_vec3	up;
	t_cam	cam;
	char	**config;

	config = get_splitted_identifier(lines, "C");
	assign_t_point(&cam.coordinate, config[1]);
	assign_t_point(&cam.orientation_vec, config[2]);
	cam.fov = degrees_to_radians(ft_atof(config[3]));
	set_pixel_size(&cam);
	up = get_correct_up(cam.orientation_vec);
	cam.transform = view_transform(cam.coordinate, cam.orientation_vec, up);
	cam.inv_transform = inverse(cam.transform);
	ft_free_matrix((void **)config);
	return (cam);
}
