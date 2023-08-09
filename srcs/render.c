/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:25:59 by revieira          #+#    #+#             */
/*   Updated: 2023/08/08 19:54:03 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_color	calculate_ray_color(int x, int y, t_world world)
{
	double	u;
	double	v;
	t_ray	ray;
	t_color	color;

	u = (double)x / WIDTH;
	v = (double)y / HEIGHT;
	ray = get_ray(u, v, world.cam);
	color = ray_color(ray, world);
	return (color);
}
