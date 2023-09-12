/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_contain_only_numbers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:33:55 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/12 17:55:30 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

int	set_contain_only_numbers(const char *str)
{
	int		i;
	char	**set;

	i = 0;
	set = ft_split(str, ',');
	while (set[i])
	{
		if (!is_number(set[i]))
		{
			ft_free_matrix((void **)set);
			return (0);
		}
		i++;
	}
	ft_free_matrix((void **)set);
	return (1);
}
