/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_pattern.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:37:27 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/21 18:45:40 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

int	is_valid_pattern(char *str)
{
	if (ft_strcmp(str, "GRADIENT") == 0)
		return (1);
	else if (ft_strcmp(str, "STRIPE") == 0)
		return (1);
	else if (ft_strcmp(str, "RING") == 0)
		return (1);
	else if (ft_strcmp(str, "CHECK") == 0)
		return (1);
	return (0);
}
