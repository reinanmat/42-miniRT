/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_texture_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:31:24 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/25 19:51:56 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

int	is_valid_texture(char *str)
{
	int		fd;
	char	*file;

	file = get_corresponding_ppm(str);
	if (!file)
		return (0);
	fd = open(file, O_RDONLY);
	free(file);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}
