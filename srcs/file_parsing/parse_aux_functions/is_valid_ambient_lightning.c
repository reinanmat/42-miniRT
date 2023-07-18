/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_ambient_lightning.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:51:36 by fnacarel          #+#    #+#             */
/*   Updated: 2023/07/18 19:08:43 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt.h"

int	is_valid_ambient_lightning(char **params, int number_of_params)
{
	if (number_of_params != 2)
		return (ft_putstr("Error\n", 1));
	if (!is_valid_rgb_set(params[2]))
		return (0);
	return (1);
}
