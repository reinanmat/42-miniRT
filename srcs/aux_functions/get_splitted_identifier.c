/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_splitted_identifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:10:07 by fnacarel          #+#    #+#             */
/*   Updated: 2023/07/24 19:02:57 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

char	**get_splitted_identifier(char **lines, char *identifier)
{
	int		i;
	char	**splitted_identifier;

	i = 0;
	while (lines[i])
	{
		splitted_identifier = ft_split_whitespaces(lines[i]);
		if (ft_strcmp(splitted_identifier[0], identifier) == 0)
		{
			ft_free_matrix((void **)splitted_identifier);
			return (ft_split_whitespaces(lines[i]));
		}
		ft_free_matrix((void **)splitted_identifier);
		i++;
	}
	return (NULL);
}
