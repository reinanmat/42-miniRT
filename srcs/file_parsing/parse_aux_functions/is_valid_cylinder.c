/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:59:12 by fnacarel          #+#    #+#             */
/*   Updated: 2023/07/21 12:31:08 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt.h"

int	is_valid_cylinder(char **params, int number_of_params)
{
	if (number_of_params != 5)
		return (ft_putstr("Error\n", 0));
	else if (!is_valid_coordinates(params[1]))
		return (0);
	else if (!is_valid_3d_normalized_vec(params[2]))
		return (0);
	else if (!is_number(params[3]))
		return (0);
	else if (!is_number(params[4]))
		return (0);
	else if (!is_valid_rgb_set(params[5]))
		return (0);
	return (1);
}
