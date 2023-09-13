/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:42:30 by revieira          #+#    #+#             */
/*   Updated: 2023/09/13 15:31:54 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_pattern	stripe_pattern(t_color a, t_color b)
{
	t_pattern	pattern;
	
	pattern.a = a;
	pattern.b = b;
	return (pattern);
}

t_color	stripe_at(t_pattern pattern, t_point point)
{
	if ((int)floor(point.x) % 2 == 0)
		return (pattern.a);
	return (pattern.b);
}
