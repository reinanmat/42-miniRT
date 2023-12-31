/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_rgb_set_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:25:07 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/27 18:38:29 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

static int	between_expected_range(const char *str)
{
	int		i;
	double	value;
	char	**rgb;

	i = 0;
	rgb = ft_split(str, ',');
	while (rgb[i])
	{
		value = atof(rgb[i]);
		if (value < 0.0 || value > 255.0)
		{
			ft_free_matrix((void **)rgb);
			return (0);
		}
		i++;
	}
	ft_free_matrix((void **)rgb);
	return (1);
}

int	is_valid_rgb_set(const char *str)
{
	if (!expected_number_of_fields(str, 3))
		return (0);
	else if (!set_contain_only_numbers(str))
		return (0);
	else if (!between_expected_range(str))
		return (0);
	else if (!only_two_commas(str))
		return (0);
	return (1);
}
