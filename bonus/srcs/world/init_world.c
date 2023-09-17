/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:17:17 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/17 19:23:55 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

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

static int	get_amount_of_lights(char **config)
{
	int	i;
	int	amount;

	i = 0;
	amount = 0;
	while (config[i])
	{
		if (config[i][0] == 'L')
			amount++;
		i++;
	}
	return (amount);
}

static t_light	*init_light(int number_of_lights, char **lines)
{
	int		i;
	int		j;
	t_light	*lights;
	char	**config;

	lights = ft_calloc(sizeof(t_light), number_of_lights + 1);
	i = 0;
	j = 0;
	while (lines[i] && j < number_of_lights)
	{
		if (lines[i][0] == 'L')
		{
			config = get_splitted_identifier(&lines[i], "L");
			lights[j].brightness = ft_atof(config[2]);
			assign_t_point(&lights[j].coordinate, config[1]);
			ft_free_matrix((void **)config);
			j++;
		}
		i++;
	}
	return (lights);
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
	world.amount_of_lights = get_amount_of_lights(lines);
	world.light = init_light(world.amount_of_lights, lines);
	world.objects = init_objects(lines);
	ft_free_matrix((void **)lines);
	return (world);
}
