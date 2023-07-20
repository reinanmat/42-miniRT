/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:24:00 by revieira          #+#    #+#             */
/*   Updated: 2023/07/20 13:24:16 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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
