/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_cone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:56:57 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/21 18:58:02 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

int	is_valid_cone(char **params, int number_of_params)
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
	else if (!is_valid_material_type(params[5]))
		return (0);
	return (1);
}
