/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:14:46 by revieira          #+#    #+#             */
/*   Updated: 2023/08/08 18:26:01 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_sphere	*sphere(char **config)
{
	t_sphere	*sp;

	sp = malloc(sizeof(t_sphere));
	sp->radius = ft_atof(config[2]) / 2;
	assign_t_point(&sp->color, config[3]);
	assign_t_point(&sp->center, config[1]);
	sp->transform = identity_matrix();
	return (sp);
}

t_cylinder	*cylinder(char **config)
{
	t_cylinder	*cy;

	cy = malloc(sizeof(t_cylinder));
	cy->height = ft_atof(config[4]);
	cy->diameter = ft_atof(config[3]);
	assign_t_point(&cy->color, config[5]);
	assign_t_point(&cy->center, config[1]);
	assign_t_point(&cy->vector, config[2]);
	cy->transform = identity_matrix();
	return (cy);
}

t_plane	*plane(char **config)
{
	t_plane	*pl;

	pl = malloc(sizeof(t_plane));
	assign_t_point(&pl->center, config[1]);
	assign_t_point(&pl->vector, config[2]);
	assign_t_point(&pl->color, config[3]);
	pl->transform = identity_matrix();
	return (pl);
}
