/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:39:52 by revieira          #+#    #+#             */
/*   Updated: 2023/09/22 16:40:08 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_color	shade_hit(t_world world, t_comps comps)
{
	int		i;
	int		shadowed;
	t_color	final_color;
	t_color	color;

	i = 0;
	final_color = (t_color){0, 0, 0};
	while (i < world.amount_of_lights)
	{
		shadowed = is_shadowed(world, world.light[i], comps.over_point);
		color = lighting(world.light[i], comps, world.ambient_light, shadowed);
		final_color = add(final_color, color);
		i++;
	}
	return (final_color);
}
