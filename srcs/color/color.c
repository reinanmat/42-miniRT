/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:25:05 by revieira          #+#    #+#             */
/*   Updated: 2023/08/28 11:58:47 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

t_color	normalize_color(t_color	color)
{
	t_color	normalized_color;

	normalized_color.x = color.x / 255;
	normalized_color.y = color.y / 255;
	normalized_color.z = color.z / 255;
	return (normalized_color);
}

static void	fix_colors(t_color *color)
{
	if (color->x > 1)
		color->x = 1;
	if (color->y > 1)
		color->y = 1;
	if (color->z > 1)
		color->z = 1;
}

int	rgb_color(t_color color)
{
	int	r;
	int	g;
	int	b;

	fix_colors(&color);
	color.x *= 255.999;
	color.y *= 255.999;
	color.z *= 255.999;
	r = color.x;
	g = color.y;
	b = color.z;
	return (r << 16 | g << 8 | b);
}
