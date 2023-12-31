/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_identifier_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:26:54 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/28 17:32:17 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

static int	is_valid_environment(char *identifier)
{
	if (ft_strcmp(identifier, "A") == 0 || ft_strcmp(identifier, "C") == 0 \
		|| ft_strcmp(identifier, "L") == 0)
		return (1);
	return (0);
}

static int	is_valid_objects(char *identifier)
{
	if (ft_strcmp(identifier, "sp") == 0 || ft_strcmp(identifier, "pl") == 0 \
		|| ft_strcmp(identifier, "cy") == 0 || ft_strcmp(identifier, "co") == 0)
		return (1);
	return (0);
}

int	is_valid_identifier(char *identifier)
{
	if (!identifier)
		return (0);
	if (is_valid_environment(identifier) || is_valid_objects(identifier))
		return (1);
	return (0);
}
