/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_rgb_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:25:07 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/27 18:31:58 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt.h"

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
		return (ft_putstr("[RGB] Unexpected number of params\n", 0));
	else if (!set_contain_only_numbers(str))
		return (ft_putstr("[RGB] Set does not contain only numbers\n", 0));
	else if (!between_expected_range(str))
		return (ft_putstr("[RGB] Set not between expected range\n", 0));
	else if (!only_two_commas(str))
		return (ft_putstr("[RGB]: R,G,B\n", 0));
	return (1);
}
