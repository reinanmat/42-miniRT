/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:04:20 by fnacarel          #+#    #+#             */
/*   Updated: 2023/07/18 19:14:31 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

int	file_opened_successfully(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("Error\nNo such file or directory\n", 2);
	return (fd);
}

int	file_ends_with_rt(char *filename)
{
	int		len;
	char	*file_extension;

	len = ft_strlen(filename);
	file_extension = ft_strrchr(filename, '.');
	if (len < 4 || !file_extension)
		return (0);
	else if (ft_strcmp(file_extension, ".rt") != 0)
		return (0);
	return (1);
}

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
	reset_fd(fd, filename);
	return (file_content);
}

int	received_invalid_param(char *filename)
{
	int	fd;

	fd = file_opened_successfully(filename);
	if (fd == -1)
		return (1);
	else if (!file_ends_with_rt(filename))
		return (1);
	return (0);
}
