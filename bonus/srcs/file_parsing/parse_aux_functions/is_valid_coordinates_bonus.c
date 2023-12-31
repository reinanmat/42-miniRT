/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_coordinates_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:05:14 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/27 18:38:17 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

int	is_valid_coordinates(const char *str)
{
	if (!expected_number_of_fields(str, 3))
		return (ft_putstr("[COORDS] Unexpected number of params\n", 0));
	else if (!set_contain_only_numbers(str))
		return (ft_putstr("[COORDS] Set does not contain only numbers\n", 0));
	else if (!only_two_commas(str))
		return (ft_putstr("[COORDS] X,Y,Z\n", 0));
	return (1);
}
