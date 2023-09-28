/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_cone_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:56:57 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/27 19:51:34 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

int	is_valid_cone(char **params, int number_of_params)
{
	if (number_of_params != 6)
		return (ft_putstr("Error\n", 0));
	else if (!is_valid_coordinates(params[1]))
		return (0);
	else if (!is_valid_3d_normalized_vec(params[2]))
		return (0);
	else if (!is_number(params[3]))
		return (0);
	else if (ft_atof(params[3]) <= 0)
		return (ft_putstr("[CONE DIAM] Should be positive integer\n", 0));
	else if (!is_number(params[4]))
		return (0);
	else if (ft_atof(params[4]) < 0)
		return (ft_putstr("[CONE MIN] Should not be negative\n", 0));
	else if (!is_number(params[5]))
		return (0);
	else if (ft_atof(params[5]) < 0)
		return (ft_putstr("[CONE MAX] Should not be negative\n", 0));
	else if (ft_atof(params[4]) == 0 && ft_atof(params[5]) == 0)
		return (ft_putstr("[CONE MAX-MIN] One should be positive\n", 0));
	else if (!is_valid_material_type(params[6]))
		return (ft_putstr("[CO-MTYPE] Invalid material type\n", 0));
	return (1);
}
