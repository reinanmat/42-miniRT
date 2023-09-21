/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:31:39 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/21 18:56:32 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

int	parse_element(char *identifier, char **element)
{
	int	number_of_params;

	number_of_params = ft_count_matrix((void **) element + 1);
	if (ft_strcmp(identifier, "A") == 0)
		return (is_valid_ambient_lighting(element, number_of_params));
	else if (ft_strcmp(identifier, "C") == 0)
		return (is_valid_camera(element, number_of_params));
	else if (ft_strcmp(identifier, "L") == 0)
		return (is_valid_light(element, number_of_params));
	else if (ft_strcmp(identifier, "sp") == 0)
		return (is_valid_sphere(element, number_of_params));
	else if (ft_strcmp(identifier, "pl") == 0)
		return (is_valid_plane(element, number_of_params));
	else if (ft_strcmp(identifier, "cy") == 0)
		return (is_valid_cylinder(element, number_of_params));
	else
		return (is_valid_cone(element, number_of_params));
}

int	map_parsed_successfully(char **lines)
{
	int		i;
	char	*identifier;
	char	**line_to_parse;

	i = 0;
	while (lines[i])
	{
		line_to_parse = ft_split_whitespaces(lines[i]);
		identifier = line_to_parse[0];
		if (!parse_element(identifier, line_to_parse))
		{
			ft_free_matrix((void **)line_to_parse);
			return (0);
		}
		ft_free_matrix((void **)line_to_parse);
		i++;
	}
	return (1);
}
