/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_lighting_ratio.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:22:05 by fnacarel          #+#    #+#             */
/*   Updated: 2023/07/20 17:03:43 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt.h"

int	is_valid_lighting_ratio(const char *str)
{
	double	ratio;

	if (!is_number(str))
		return (ft_putstr("[LIGHT RATIO] Not a number\n", 0));
	ratio = ft_atof(str);
	if (ratio < 0.0 || ratio > 1.0)
		return (ft_putstr("[LIGHT RATIO] Not between expected range\n", 0));
	return (1);
}
