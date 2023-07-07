/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:12:09 by revieira          #+#    #+#             */
/*   Updated: 2023/07/21 18:23:23 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	hit_anything(t_hittable *objects, t_ray ray, t_range range, t_hit *hit)
{
	int		hit_anything;
	t_hit	tmp_hit;

	hit_anything = 0;
	while (objects)
	{
		if (objects->type == 1 && hit_sphere(*objects->sp, ray, range, &tmp_hit))
		{
			hit_anything = 1;
			range.max = tmp_hit.t;
			*hit = tmp_hit;
		}
		objects = objects->next;
	}
	return (hit_anything);
}
