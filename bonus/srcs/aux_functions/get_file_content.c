/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:04:09 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/12 17:53:28 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

char	*get_file_content(int fd, char *filename)
{
	int		i;
	int		new_fd;
	char	buf[1];
	char	*file_content;

	i = 0;
	while (read(fd, buf, 1))
		i++;
	if (i == 0)
		return (NULL);
	file_content = malloc(sizeof(char) * (i + 1));
	new_fd = reset_fd(fd, filename);
	read(new_fd, file_content, i);
	file_content[i] = '\0';
	close(fd);
	return (file_content);
}
