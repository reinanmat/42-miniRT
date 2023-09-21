/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:00:43 by revieira          #+#    #+#             */
/*   Updated: 2023/09/20 16:54:20 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt_bonus.h"

t_sphere	*unit_sphere(void)
{
	char		**config;
	t_sphere	*sp;

	config = ft_calloc(sizeof(char *), 5);
	config[0] = ft_strdup("sp");
	config[1] = ft_strdup("0,0,0");
	config[2] = ft_strdup("2");
	config[3] = ft_strdup("255,255,255");
	sp = sphere(config);
	sp->transform = identity_matrix();
	sp->inv_transform = identity_matrix();
	return (sp);
}

t_plane	*unit_plane(void)
{
	char		**config;
	t_plane		*pl;

	config = ft_calloc(sizeof(char *), 5);
	config[0] = ft_strdup("pl");
	config[1] = ft_strdup("0,0,0");
	config[2] = ft_strdup("0,1,0");
	config[3] = ft_strdup("255,255,255");
	pl = plane(config);
	pl->transform = identity_matrix();
	pl->inv_transform = identity_matrix();
	return (pl);
}

t_cone	*unit_cone(void)
{
	char		**config;
	t_cone		*co;

	config = ft_calloc(sizeof(char *), 7);
	config[0] = ft_strdup("co");
	config[1] = ft_strdup("0,0,0");
	config[2] = ft_strdup("0,1,0");
	config[3] = ft_strdup("1");
	config[4] = ft_strdup("1");
	config[5] = ft_strdup("255,255,255");
	co = cone(config);
	co->transform = identity_matrix();
	co->inv_transform = identity_matrix();
	co->max = INFINITY;
	co->min = -INFINITY;
	return (co);
}

t_cylinder	*unit_cylinder(void)
{
	char		**config;
	t_cylinder	*cy;

	config = ft_calloc(sizeof(char *), 7);
	config[0] = ft_strdup("cy");
	config[1] = ft_strdup("0,0,0");
	config[2] = ft_strdup("0,1,0");
	config[3] = ft_strdup("1");
	config[4] = ft_strdup("1");
	config[5] = ft_strdup("255,255,255");
	cy = cylinder(config);
	cy->transform = identity_matrix();
	cy->inv_transform = identity_matrix();
	cy->max = INFINITY;
	cy->min = -INFINITY;
	return (cy);
}
