/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_3d_normalized_vec.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:43:53 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/27 18:34:47 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt.h"

static int	between_expected_range(const char *str)
{
	int		i;
	double	value;
	char	**vec;

	i = 0;
	vec = ft_split(str, ',');
	while (vec[i])
	{
		value = atof(vec[i]);
		if (value < -1.0 || value > 1.0)
		{
			ft_free_matrix((void **)vec);
			return (0);
		}
		i++;
	}
	ft_free_matrix((void **)vec);
	return (1);
}

static int	vec_is_normalized(const char *str)
{
	char	**vec;
	double	x;
	double	y;
	double	z;
	double	mag;

	vec = ft_split(str, ',');
	x = atof(vec[0]);
	y = atof(vec[1]);
	z = atof(vec[2]);
	ft_free_matrix((void **)vec);
	mag = magnitude(vec3(x, y, z));
	if (double_equals(mag, 1))
		return (1);
	return (0);
}

int	is_valid_3d_normalized_vec(const char *str)
{
	if (!expected_number_of_fields(str, 3))
		return (ft_putstr("[3DVEC] Unexpected number of params\n", 0));
	else if (!set_contain_only_numbers(str))
		return (ft_putstr("[3DVEC] Set does not contain only numbers\n", 0));
	else if (!between_expected_range(str))
		return (ft_putstr("[3DVEC] Set not between expected range\n", 0));
	else if (!vec_is_normalized(str))
		return (ft_putstr("[3DVEC] Set not normalized\n", 0));
	else if (!only_two_commas(str))
		return (ft_putstr("[3DVEC] X,Y,Z\n", 0));
	return (1);
}
