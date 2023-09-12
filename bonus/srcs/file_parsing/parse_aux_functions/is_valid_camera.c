/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:55:08 by fnacarel          #+#    #+#             */
/*   Updated: 2023/07/20 18:15:39 by fnacarel         ###   ########.fr       */
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
		if (value < 0.0 || value > 180.0)
		{
			ft_free_matrix((void **)rgb);
			return (0);
		}
		i++;
	}
	ft_free_matrix((void **)rgb);
	return (1);
}

static int	is_valid_fov(const char *str)
{
	if (!expected_number_of_fields(str, 1))
		return (ft_putstr("[FOV] Unexpected number of params\n", 0));
	else if (!set_contain_only_numbers(str))
		return (ft_putstr("[FOV] Set does not contain only numbers\n", 0));
	else if (!between_expected_range(str))
		return (ft_putstr("[FOV] Set not between expected range\n", 0));
	return (1);
}

int	is_valid_camera(char **params, int number_of_params)
{
	if (number_of_params != 3)
		return (ft_putstr("Error\n", 0));
	else if (!is_valid_coordinates(params[1]))
		return (0);
	else if (!is_valid_3d_normalized_vec(params[2]))
		return (0);
	else if (!is_valid_fov(params[3]))
		return (0);
	return (1);
}
