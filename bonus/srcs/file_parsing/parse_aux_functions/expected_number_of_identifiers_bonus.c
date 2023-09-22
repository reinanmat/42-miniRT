/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expected_number_of_identifiers_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:42:02 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/15 19:22:51 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

int	expected_number_of_identifiers(char **lines)
{
	int	i;
	int	a_identifier;
	int	c_identifier;
	int	l_identifier;

	i = 0;
	a_identifier = 0;
	c_identifier = 0;
	l_identifier = 0;
	while (lines[i])
	{
		a_identifier += lines[i][0] == 'A';
		c_identifier += lines[i][0] == 'C';
		l_identifier += lines[i][0] == 'L';
		i++;
	}
	return (a_identifier == 1 && c_identifier == 1 && l_identifier >= 1);
}
