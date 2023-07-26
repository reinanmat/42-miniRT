/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:25:05 by revieira          #+#    #+#             */
/*   Updated: 2023/07/26 15:31:23 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	get_color(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = color.x;
	g = color.y;
	b = color.z;
	return (r << 16 | g << 8 | b);
}
