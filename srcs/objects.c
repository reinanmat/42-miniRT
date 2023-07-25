/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:14:46 by revieira          #+#    #+#             */
/*   Updated: 2023/07/25 19:38:37 by fnacarel         ###   ########.fr       */
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
	return (sp);
}

t_cylinder	*cy(void)
{
	t_cylinder	*cy;

	cy = NULL;
	return (cy);
}

t_plane	*pl(void)
{
	t_plane	*pl;

	pl = NULL;
	return (pl);
}
