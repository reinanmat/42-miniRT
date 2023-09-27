/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_two_commas_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:37:05 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/27 18:37:30 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

int	only_two_commas(const char *str)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma++;
		i++;
	}
	if (comma == 2)
		return (1);
	return (0);
}
