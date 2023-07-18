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

int	has_invalid_identifier(char **lines)
{
	int		i;
	char	**splitted_identifer;

	i = 0;
	while (lines[i])
	{
		splitted_identifer = ft_split(lines[i], ' ');
		if (!is_valid_identifier(splitted_identifer[0]))
		{
			ft_putstr_fd("Invalid identifier '", 2);
			ft_putstr_fd(splitted_identifer[0], 2);
			ft_putstr_fd("' not supported.\n", 2);
			ft_free_matrix((void **)splitted_identifer);
			return (1);
		}
		ft_free_matrix((void **)splitted_identifer);
		i++;
	}
	return (0);
}

int	file_content_is_valid(int fd, char *filename)
{
	char	**lines;
	char	*file_content;

	file_content = get_file_content(fd, filename);
	if (!file_content)
		return (0);
	lines = ft_split(file_content, '\n');
	free(file_content);
	trim_lines(lines);
	if (!expected_number_of_identifiers(lines))
	{
		ft_putstr_fd("Unexpected number of identifiers.\n", 2);
		ft_free_matrix((void **)lines);
		return (0);
	}
	else if (has_invalid_identifier(lines) || !map_parsed_successfully(lines))
	{
		ft_free_matrix((void **)lines);
		return (0);
	}
	ft_free_matrix((void **)lines);
	return (1);
}

int	received_invalid_param(char *filename)
{
	int	fd;

	fd = file_opened_successfully(filename);
	if (fd == -1)
		return (1);
	else if (!file_ends_with_rt(filename))
		return (1);
	else if (!file_content_is_valid(fd, filename))
		return (1);
	return (0);
}
