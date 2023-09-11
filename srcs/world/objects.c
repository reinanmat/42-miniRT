/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:14:46 by revieira          #+#    #+#             */
/*   Updated: 2023/09/11 20:02:43 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

t_sphere	*sphere(char **config)
{
	t_sphere	*sp;
	t_vec3		scale;
	t_point		translation;

	sp = malloc(sizeof(t_sphere));
	sp->center = point(0, 0, 0);
	sp->radius = ft_atof(config[2]) / 2;
	sp->material = default_material();
	assign_t_color(&sp->material.color, config[3]);
	assign_t_point(&translation, config[1]);
	scale = vec3(sp->radius, sp->radius, sp->radius);
	sp->transform = transform_object(translation, scale);
	return (sp);
}

t_matrix	get_orientation(t_vec3 a)
{
	if (check_equal_vec3(a, vec3(0, 1, 0)))
		return (identity_matrix());
	else if (check_equal_vec3(a, vec3(0, -1, 0)))
		return (rotate_x_matrix(M_PI));
	else if (check_equal_vec3(a, vec3(1, 0, 0)))
		return (rotate_z_matrix(-M_PI / 2));
	else if (check_equal_vec3(a, vec3(-1, 0, 0)))
		return (rotate_z_matrix(M_PI / 2));
	else if (check_equal_vec3(a, vec3(0, 0, 1)))
		return (rotate_x_matrix(M_PI / 2));
	else// if (check_equal_vec3(a, vec3(0, 0, -1)))
		return (rotate_x_matrix(-M_PI / 2));
}

t_cylinder	*cylinder(char **config)
{
	t_cylinder	*cy;

	cy = malloc(sizeof(t_cylinder));
	cy->height = ft_atof(config[4]);
	cy->diameter = ft_atof(config[3]);
	cy->transform = identity_matrix();
	cy->material = default_material();
	assign_t_point(&cy->center, config[1]);
	assign_t_point(&cy->vector, config[2]);
	assign_t_color(&cy->material.color, config[5]);
	return (cy);
}

t_plane	*plane(char **config)
{
	t_plane	*pl;

	pl = malloc(sizeof(t_plane));
	pl->transform = identity_matrix();
	pl->material = default_material();
	assign_t_point(&pl->center, config[1]);
	assign_t_point(&pl->vector, config[2]);
	assign_t_color(&pl->material.color, config[3]);
	return (pl);
}

void	*create_object(char **config)
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
