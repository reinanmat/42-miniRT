/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:25:59 by revieira          #+#    #+#             */
/*   Updated: 2023/06/20 12:26:12 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	render_background(t_mlx mlx)
{
	int		x;
	int		y;
	int		i;
	int		j;
	t_color	color;

	j = HEIGHT - 1;
	y = 0;
	while (j >= 0)
	{
		i = 0;
		x = 0;
		while (i < WIDTH - 1)
		{
			color.x = (double)i / (WIDTH - 1);
			color.y = (double)j / (HEIGHT - 1);
			color.z = 0.25;
			mlx_img_pix_put(&mlx.img, x, y, get_color(color));
			x++;
			i++;
		}
		y++;
		j--;
	}
}

int	render(t_mlx mlx)
{
	render_background(mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.mlx_img, 0, 0);
	return (0);
}
