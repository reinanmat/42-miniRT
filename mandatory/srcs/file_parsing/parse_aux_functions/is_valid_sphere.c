/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:56:56 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/27 19:12:02 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt.h"

int	is_valid_sphere(char **params, int number_of_params)
{
	if (number_of_params != 3)
		return (ft_putstr("Error\n", 0));
	else if (!is_valid_coordinates(params[1]))
		return (0);
	else if (!is_number(params[2]))
		return (ft_putstr("[SPH DIAM] NaN\n", 0));
	else if (ft_atof(params[2]) <= 0)
		return (ft_putstr("[SPH DIAM] Should be positive integer\n", 0));
	else if (!is_valid_rgb_set(params[3]))
		return (0);
	return (1);
}
