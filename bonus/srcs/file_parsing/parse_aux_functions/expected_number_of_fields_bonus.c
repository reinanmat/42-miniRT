/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expected_number_of_fields_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:45:53 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/12 17:54:05 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

int	expected_number_of_fields(const char *str, int expected_fields)
{
	int		number_of_fields;
	char	**fields;

	fields = ft_split(str, ',');
	number_of_fields = ft_count_matrix((void **)fields);
	ft_free_matrix((void **)fields);
	if (number_of_fields != expected_fields)
		return (0);
	return (1);
}
