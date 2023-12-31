/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:17:17 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/19 15:34:51 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

static t_amb_light	init_ambient_light(char **lines)
{
	t_amb_light	amb_light;
	char		**config;

	config = get_splitted_identifier(lines, "A");
	amb_light.light_ratio = ft_atof(config[1]);
	assign_t_color(&amb_light.color, config[2]);
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

static void	*create_object(char **config)
{
	if (ft_strcmp(config[0], "cy") == 0)
		return (cylinder(config));
	else if (ft_strcmp(config[0], "sp") == 0)
		return (sphere(config));
	else if (ft_strcmp(config[0], "pl") == 0)
		return (plane(config));
	return (NULL);
}

t_hittable	*init_objects(char **lines)
{
	int			i;
	void		*object;
	char		**config;
	t_hittable	*objects;

	i = 0;
	objects = NULL;
	while (lines[i])
	{
		config = ft_split_whitespaces(lines[i]);
		object = create_object(config);
		if (object)
			hittable_add(config[0], object, &objects);
		ft_free_matrix((void **)config);
		i++;
	}
	return (objects);
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
	world.cam = init_camera(lines);
	world.ambient_light = init_ambient_light(lines);
	world.light = init_light(lines);
	world.objects = init_objects(lines);
	ft_free_matrix((void **)lines);
	return (world);
}
