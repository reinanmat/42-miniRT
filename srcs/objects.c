/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:14:46 by revieira          #+#    #+#             */
/*   Updated: 2023/07/11 17:41:31 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_sphere	*sp(t_point center, double radius, t_color color)
{
	t_sphere	*sp;

	sp = ft_calloc(sizeof(t_sphere), 1);
	sp->center = center;
	sp->radius = radius;
	sp->color = color;
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
