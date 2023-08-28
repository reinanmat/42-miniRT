/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:29:27 by fnacarel          #+#    #+#             */
/*   Updated: 2023/08/28 17:13:35 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

void	set_pixel_size(t_cam *camera)
{
	double	aspect;
	double	half_view;

	half_view = tan(camera->fov / 2);
	aspect = (double) WIDTH / HEIGHT;
	if (aspect >= 1)
	{
		camera->viewport_width = half_view;
		camera->viewport_height = half_view / aspect;
	}
	else
	{
		camera->viewport_width = half_view * aspect;
		camera->viewport_height = half_view;
	}
	camera->pixel_size = (camera->viewport_width * 2) / WIDTH;
}

t_cam	init_camera(char **lines)
{
	t_cam	cam;
	char	**config;

	config = get_splitted_identifier(lines, "C");
	assign_t_point(&cam.coordinate, config[1]);
	assign_t_point(&cam.orientation_vec, config[2]);
	cam.fov = degress_to_radians(ft_atof(config[3]));
	cam.fov = M_PI / 3;
	set_pixel_size(&cam);
	cam.t = view_transform(cam.coordinate, cam.orientation_vec, vec3(0, 1, 0));
	ft_free_matrix((void **)config);
	return (cam);
}
