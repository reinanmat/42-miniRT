/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_light_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:56:19 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/27 18:40:09 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

int	is_valid_light(char **params, int number_of_params)
{
	if (number_of_params != 3)
		return (ft_putstr("Error\n", 0));
	else if (!is_valid_coordinates(params[1]))
		return (0);
	else if (!is_valid_lighting_ratio(params[2]))
		return (0);
	else if (!is_valid_rgb_set(params[3]))
		return (ft_putstr("[LIGHT-RGB] R,G,B\n", 0));
	return (1);
}
