/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:25:05 by revieira          #+#    #+#             */
/*   Updated: 2023/08/17 15:55:56 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	fix_colors(t_color *color)
{
	if (color->x > 1)
		color->x = 1;
	if (color->y > 1)
		color->y = 1;
	if (color->z > 1)
		color->z = 1;
}

int	get_color(t_color color)
{
	int	r;
	int	g;
	int	b;

	fix_colors(&color);
	r = color.x;
	g = color.y;
	b = color.z;
	return (r << 16 | g << 8 | b);
}
