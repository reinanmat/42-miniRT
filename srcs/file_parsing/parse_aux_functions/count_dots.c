/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_dots.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:21:01 by fnacarel          #+#    #+#             */
/*   Updated: 2023/08/11 15:31:34 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt.h"

int	count_dots(const char *str)
{
	int	i;
	int	dots;

	i = 0;
	dots = 0;
	while (str[i])
	{
		dots += str[i] == '.';
		i++;
	}
	return (dots);
}
