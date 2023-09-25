/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:55:33 by revieira          #+#    #+#             */
/*   Updated: 2023/09/25 20:08:38 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

static void	get_width_and_height(t_texture *t, char *info)
{
	char	**values;

	values = ft_split_whitespaces(info);
	t->width = ft_atoi(values[0]);
	t->height = ft_atoi(values[1]);
	ft_free_matrix((void **)values);
}

int	get_value(char *str, int *iter)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (str[i] == ' ' || str[i] == '	')
		i++;
	while (ft_isdigit(str[i]))
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	*iter = *iter + i;
	return (value);
}

static void	set_color(t_texture *t, int curr_row, char *line)
{
	int		j;
	int		i;
	t_color	tmp;

	j = 0;
	i = 0;
	while (line [i] && j < t->width)
	{
		tmp.x = get_value(&line[i], &i);
		tmp.y = get_value(&line[i], &i);
		tmp.z = get_value(&line[i], &i);
		t->map_texture[curr_row][j] = normalize_color(tmp);
		j++;
	}
}

char	**get_ppm_lines(char *filename)
{
	int		fd;
	char	*content;
	char	**lines;

	fd = open(filename, O_RDONLY);
	content = get_file_content(fd, filename);
	lines = ft_split(content, '\n');
	ft_free(content);
	return (lines);
}

t_texture	set_texture(char *config)
{
	t_texture	t;
	int			col;
	int			row;
	char		**lines;
	char		*filename;

	col = -1;
	row = 0;
	filename = get_corresponding_ppm(config);
	lines = get_ppm_lines(filename);
	get_width_and_height(&t, lines[1]);
	t.map_texture = ft_calloc(sizeof(t_color *), t.height);
	while (++col < t.height)
		t.map_texture[col] = ft_calloc(sizeof(t_color), t.width);
	col = 3;
	while (lines[col] && row != t.height)
	{
		set_color(&t, row, lines[col]);
		row++;
		col++;
	}
	ft_free_matrix((void **)lines);
	return (t);
}
