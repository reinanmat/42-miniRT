/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:03:52 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/12 17:53:35 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

int	reset_fd(int fd, char *filename)
{
	int	new_fd;

	close(fd);
	new_fd = open(filename, O_RDONLY);
	return (new_fd);
}
