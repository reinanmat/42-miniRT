/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:14:46 by revieira          #+#    #+#             */
/*   Updated: 2023/09/23 16:54:34 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

void	*create_object(char **config)
{
	if (ft_strcmp(config[0], "cy") == 0)
		return (cylinder(config));
	else if (ft_strcmp(config[0], "sp") == 0)
		return (sphere(config));
	else if (ft_strcmp(config[0], "pl") == 0)
		return (plane(config));
	else if (ft_strcmp(config[0], "co") == 0)
		return (cone(config));
	return (NULL);
}

t_hittable	*init_objects(char **lines)
{
	int			i;
	void		*object;
	char		**config;
	t_hittable	*objects;

	i = 0;
	objects = NULL;
	while (lines[i])
	{
		config = ft_split_whitespaces(lines[i]);
		object = create_object(config);
		if (object)
			hittable_add(config[0], object, &objects);
		ft_free_matrix((void **)config);
		i++;
	}
	return (objects);
}
