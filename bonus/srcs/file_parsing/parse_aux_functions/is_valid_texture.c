/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:31:24 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/21 18:35:58 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

int	is_valid_texture(char *str)
{
	if (ft_strcmp(str, "DOGUINHO") == 0)
		return (1);
	else if (ft_strcmp(str, "WORLD") == 0)
		return (1);
	return (0);
}
