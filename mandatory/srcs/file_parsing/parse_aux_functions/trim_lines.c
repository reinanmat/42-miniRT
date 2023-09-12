/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:38 by fnacarel          #+#    #+#             */
/*   Updated: 2023/07/11 14:26:23 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt.h"

void	trim_lines(char **lines)
{
	int		i;
	char	*prev_ptr;

	i = 0;
	if (!lines)
		return ;
	while (lines[i])
	{
		prev_ptr = lines[i];
		lines[i] = ft_strtrim(lines[i], " \r\v\f\t");
		free(prev_ptr);
		i++;
	}
}
