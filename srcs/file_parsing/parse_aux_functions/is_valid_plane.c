/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:58:35 by fnacarel          #+#    #+#             */
/*   Updated: 2023/07/21 12:14:44 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt.h"

int	is_valid_plane(char **params, int number_of_params)
{
	if (number_of_params != 3)
		return (ft_putstr("Error\n", 0));
	else if (!is_valid_coordinates(params[1]))
		return (0);
	else if (!is_valid_3d_normalized_vec(params[2]))
		return (0);
	else if (!is_valid_rgb_set(params[3]))
		return (0);
	return (1);
}
