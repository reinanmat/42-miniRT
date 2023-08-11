/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_3d_normalized_vec.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:43:53 by fnacarel          #+#    #+#             */
/*   Updated: 2023/08/11 15:31:12 by revieira         ###   ########.fr       */
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
		if (value < -1.0 || value > 1.0)
		{
			ft_free_matrix((void **)rgb);
			return (0);
		}
		i++;
	}
	ft_free_matrix((void **)rgb);
	return (1);
}

int	is_valid_3d_normalized_vec(const char *str)
{
	if (!expected_number_of_fields(str, 3))
		return (ft_putstr("[3DVEC] Unexpected number of params\n", 0));
	else if (!set_contain_only_numbers(str))
		return (ft_putstr("[3DVEC] Set does not contain only numbers\n", 0));
	else if (!between_expected_range(str))
		return (ft_putstr("[3DVEC] Set not between expected range\n", 0));
	return (1);
}
