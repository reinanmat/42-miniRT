/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:00:43 by revieira          #+#    #+#             */
/*   Updated: 2023/09/14 13:42:18 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt_bonus.h"

t_sphere	*unit_sphere(void)
{
	char		*config[4];
	t_sphere	*sp;

	config[0] = "sp";
	config[1] = "0,0,0";
	config[2] = "2";
	config[3] = "255,255,255";
	sp = sphere(config);
	sp->transform = identity_matrix();
	return (sp);
}

t_plane	*unit_plane(void)
{
	char		*config[4];
	t_plane		*pl;

	config[0] = "sp";
	config[1] = "0,0,0";
	config[2] = "0,1,0";
	config[3] = "255,255,255";
	pl = plane(config);
	pl->transform = identity_matrix();
	return (pl);
}

t_cone	*unit_cone(void)
{
	char		*config[6];
	t_cone		*co;

	config[0] = "co";
	config[1] = "0,0,0";
	config[2] = "0, 1, 0";
	config[3] = "1";
	config[4] = "1";
	config[5] = "1, 1, 1";
	co = cone(config);
	co->transform = identity_matrix();
	co->max = INFINITY;
	co->min = -INFINITY;
	return (co);
}

t_cylinder	*unit_cylinder(void)
{
	char		*config[6];
	t_cylinder	*cy;

	config[0] = "cy";
	config[1] = "0,0,0";
	config[2] = "0, 1, 0";
	config[3] = "1";
	config[4] = "1";
	config[5] = "1, 1, 1";
	cy = cylinder(config);
	cy->transform = identity_matrix();
	cy->max = INFINITY;
	cy->min = -INFINITY;
	return (cy);
}
