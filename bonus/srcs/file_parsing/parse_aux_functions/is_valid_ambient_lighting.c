/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_ambient_lighting.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:51:36 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/12 17:54:28 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

int	is_valid_ambient_lighting(char **params, int number_of_params)
{
	if (number_of_params != 2)
		return (ft_putstr("Error\n", 0));
	else if (!is_valid_lighting_ratio(params[1]))
		return (0);
	else if (!is_valid_rgb_set(params[2]))
		return (0);
	return (1);
}
