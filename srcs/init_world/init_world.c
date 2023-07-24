/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:17:17 by fnacarel          #+#    #+#             */
/*   Updated: 2023/07/24 19:23:29 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

static t_point	get_lower_left_corner(t_cam cam)
{
	t_point	lower_left_corner;
	t_point	half_vertical;
	t_point	half_horizontal;
	t_point	aux;

	half_vertical = s_division(cam.vertical, 2);
	half_horizontal = s_division(cam.horizontal, 2);
	aux = minus(minus(cam.coordinate, half_horizontal), half_vertical);
	lower_left_corner = minus(aux, (t_point){0, 0, cam.focal_length});
	return (lower_left_corner);
}

static t_cam	init_cam(char **lines)
{
	t_cam	cam;
	char	**config;
	double	aspect_ratio;
	double	vertical_fov;
	double	vertical_fov_radians;

	config = get_splitted_identifier(lines, "C");
	vertical_fov = ft_atof(config[3]);;
	vertical_fov_radians = vertical_fov * PI / 180.0;
	aspect_ratio = 16.0 / 9.0;
	cam.viewport_height = 2.0 * tan(vertical_fov_radians / 2.0);
	cam.viewport_width = cam.viewport_height * aspect_ratio;
	cam.focal_length = 1.0;
	assign_t_point(&cam.coordinate, config[1]);
	cam.horizontal = (t_point){cam.viewport_width, 0, 0};
	cam.vertical = (t_point){0, cam.viewport_height, 0};
	cam.lower_left_corner = get_lower_left_corner(cam);
	ft_free_matrix((void **)config);
	return (cam);
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
	ft_free_matrix((void **)lines);
	return (world);
}
