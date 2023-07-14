/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:25:05 by revieira          #+#    #+#             */
/*   Updated: 2023/07/14 18:27:05 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	get_color(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = color.x * 255.999;
	g = color.y * 255.999;
	b = color.z * 255.999;
	return (r << 16 | g << 8 | b);
}

t_color	gradient_color(double axis, t_color a, t_color b)
{
	double	t;
	t_color	aux1;
	t_color	aux2;
	t_color	color;

	t = 0.5 * (axis + 1.0);
	aux1 = s_multiply(a, (1.0 - t));
	aux2 = s_multiply(b, t);
	color = add(aux1, aux2);
	return (color);
}
