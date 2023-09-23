/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:55:33 by revieira          #+#    #+#             */
/*   Updated: 2023/09/23 16:57:42 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_color	uv_pattern_at(t_texture t, double u, double v)
{
	int	x;
	int	y;

	if (u > 1 || u < 0 || v > 1 || v < 0)
	{
		printf("error u or v\n");
		exit(1);
	}
	v = 1 - v;
	x = floor(u * (t.width - 1));
	y = floor(v * (t.height - 1));
	return (t.map_texture[y][x]);
}

static void	get_width_and_height(t_texture *t, char *info)
{
	char	**values;

	values = ft_split_whitespaces(info);
	t->width = ft_atoi(values[0]);
	t->height = ft_atoi(values[1]);
	ft_free_matrix((void **)values);
}

static void	set_color(t_texture *t, int curr_row, char *line)
{
	int		i;
	int		j;
	t_color	tmp;
	int		third_color;
	char	**info;

	i = 0;
	j = 0;
	third_color = 0;
	info = ft_split_whitespaces(line);
	while (info[i])
	{
		if (third_color == 0 && ++third_color)
			tmp.x = ft_atoi(info[i]);
		else if (third_color == 1 && ++third_color)
			tmp.y = ft_atoi(info[i]);
		else if (third_color == 2 && ++third_color)
			tmp.z = ft_atoi(info[i]);
		if (third_color == 3)
		{
			t->map_texture[curr_row][j] = normalize_color(tmp);
			third_color = 0;
			j++;
		}
		if (t->width == j)
			break ;
		i++;
	}
	ft_free_matrix((void **)info);
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
