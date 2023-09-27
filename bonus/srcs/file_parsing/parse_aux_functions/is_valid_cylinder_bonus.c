/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_cylinder_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:59:12 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/27 19:47:32 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

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
	else if (ft_atof(params[3]) <= 0)
		return (ft_putstr("[CY DIAM] Should be positive integer\n", 0));
	else if (!is_number(params[4]))
		return (0);
	else if (ft_atof(params[4]) <= 0)
		return (ft_putstr("[CY HEIGHT] Should be positive integer\n", 0));
	else if (!is_valid_material_type(params[5]))
		return (ft_putstr("[CY-MTYPE] Invalid material type\n", 0));
	return (1);
}
