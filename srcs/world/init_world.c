/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:17:17 by fnacarel          #+#    #+#             */
/*   Updated: 2023/08/28 16:58:58 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

static t_cam	init_cam(char **lines)
{
	t_cam	cam;
	char	**config;
	double	aspect_ratio;
	double	vertical_fov;
	double	vertical_fov_radians;

	config = get_splitted_identifier(lines, "C");
	vertical_fov = ft_atof(config[3]);
	vertical_fov_radians = vertical_fov * M_PI / 180.0;
	aspect_ratio = 16.0 / 9.0;
	cam.viewport_height = 2.0 * tan(vertical_fov_radians / 2.0);
	cam.viewport_width = cam.viewport_height * aspect_ratio;
	cam.focal_length = 1.0;
	assign_t_point(&cam.coordinate, config[1]);
	assign_t_point(&cam.orientation_vec, config[2]);
	cam.horizontal = (t_point){cam.viewport_width, 0, 0};
	cam.vertical = (t_point){0, cam.viewport_height, 0};
	cam.lower_left_corner = get_lower_left_corner(cam);
	ft_free_matrix((void **)config);
	return (cam);
}

static t_amb_light	init_ambient_light(char **lines)
{
	t_amb_light	amb_light;
	char		**config;

	config = get_splitted_identifier(lines, "A");
	amb_light.light_ratio = ft_atof(config[1]);
	assign_t_point(&amb_light.color, config[2]);
	ft_free_matrix((void **)config);
	return (amb_light);
}

static t_light	init_light(char **lines)
{
	t_light	light;
	char	**config;

	config = get_splitted_identifier(lines, "L");
	light.brightness = ft_atof(config[2]);
	assign_t_point(&light.coordinate, config[1]);
	ft_free_matrix((void **)config);
	return (light);
}

t_world	init_world(char *filename)
{
	int			fd;
	char		*file_content;
	char		**lines;
	t_world		world;

	fd = open(filename, O_RDONLY);
	file_content = get_file_content(fd, filename);
	lines = ft_split(file_content, '\n');
	free(file_content);
	trim_lines(lines);
	world.cam = init_cam(lines);
	world.ambient_light = init_ambient_light(lines);
	world.light = init_light(lines);
	world.objects = init_objects(lines);
	ft_free_matrix((void **)lines);
	return (world);
}
