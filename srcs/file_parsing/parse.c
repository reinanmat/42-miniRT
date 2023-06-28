/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:04:20 by fnacarel          #+#    #+#             */
/*   Updated: 2023/06/27 21:48:51 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

int	file_opened_successfully(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("No such file or directory\n", 2);
	return (fd);
}

int	received_invalid_param(char *filename)
{
	int	fd;

	fd = file_opened_successfully(filename);
	if (fd == -1)
		return (1);
	return (0);
}
