/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:55:33 by revieira          #+#    #+#             */
/*   Updated: 2023/09/25 19:14:14 by revieira         ###   ########.fr       */
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

t_texture	set_texture(char *config)
{
	int			fd;
	char		*filename;
	char		*content;
	char		**lines;
	t_texture	t;

	if (ft_strcmp("DOGUINHO", config) == 0)
		filename = ft_strdup("./bonus/textures/doguinho.ppm");
	else
		fd = -1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error in file of texture\n", 2);
		exit(1);
	}
	content = get_file_content(fd, filename);
	lines = ft_split(content, '\n');
	get_width_and_height(&t, lines[1]);
	printf("height %d, width %d\n", t.height, t.width);

	t.map_texture = ft_calloc(sizeof(t_color *), t.height);
	int	i = 0;
	while (i < t.height)
	{
		t.map_texture[i] = ft_calloc(sizeof(t_color), t.width);
		i++;
	}
	i = 3;
	int row = 0;
	while (lines[i] && row != t.height)
	{
		set_color(&t, row, lines[i]);
		row++;
		i++;
	}
	ft_free(content);
	ft_free_matrix((void **)lines);
	printf("Created Texture\n");
	return (t);
}
