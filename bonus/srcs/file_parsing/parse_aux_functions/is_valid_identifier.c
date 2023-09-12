/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:26:54 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/12 17:55:01 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

int	is_valid_identifier(char *identifier)
{
	if (ft_strcmp(identifier, "A") == 0 || ft_strcmp(identifier, "C") == 0 \
		|| ft_strcmp(identifier, "L") == 0 || ft_strcmp(identifier, "sp") == 0 \
		|| ft_strcmp(identifier, "pl") == 0 || ft_strcmp(identifier, "cy") == 0)
		return (1);
	return (0);
}
