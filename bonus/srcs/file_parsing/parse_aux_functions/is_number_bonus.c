/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:31:28 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/12 17:54:17 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

int	is_number(const char *str)
{
	int	digit_count;
	int	post_dot_count;

	digit_count = 0;
	post_dot_count = 0;
	if (count_dots(str) > 1)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		digit_count++;
		str++;
	}
	if (*str == '.')
		str++;
	while (ft_isdigit(*str))
	{
		post_dot_count++;
		str++;
	}
	if (digit_count == 0 || *str != '\0')
		return (0);
	return (1);
}
