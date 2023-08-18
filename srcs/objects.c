/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:14:46 by revieira          #+#    #+#             */
/*   Updated: 2023/08/18 18:30:49 by revieira         ###   ########.fr       */
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

t_sphere	*sphere(char **config)
{
	t_sphere	*sp;

	sp = malloc(sizeof(t_sphere));
	sp->transform = identity_matrix();
	sp->material = default_material();
	sp->radius = ft_atof(config[2]) / 2;
	assign_t_point(&sp->center, config[1]);
	assign_t_color(&sp->material.color, config[3]);
	return (sp);
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
