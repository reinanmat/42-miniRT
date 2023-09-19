/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:48:34 by revieira          #+#    #+#             */
/*   Updated: 2023/09/19 14:49:21 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

t_color	shade_hit(t_world world, t_comps comps)
{
	t_color	color;
	int		shadowed;

	shadowed = is_shadowed(world, comps.over_point);
	color = lighting(world.light, comps, world.ambient_light, shadowed);
	return (color);
}
