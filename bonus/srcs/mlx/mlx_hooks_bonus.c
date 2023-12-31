/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:13:24 by revieira          #+#    #+#             */
/*   Updated: 2023/09/17 19:54:11 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

static int	close_program(t_data *data)
{
	mlx_close_window(&data->mlx);
	ft_free(data->world.light);
	clean_hittable(&data->world.objects);
	exit(0);
}

static int	handle_input(int key, t_data *data)
{
	if (key == KEY_ESC)
		close_program(data);
	return (0);
}

void	mlx_hooks(t_data *data)
{
	mlx_hook(data->mlx.win_ptr, 2, 1L << 0, &handle_input, data);
	mlx_hook(data->mlx.win_ptr, 17, 0L, &close_program, data);
}
