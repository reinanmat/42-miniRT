/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:11:03 by revieira          #+#    #+#             */
/*   Updated: 2023/06/19 14:17:49 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	get_color(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = color.x * 255.999;
	g = color.y * 255.999;
	b = color.z * 255.999;
	return (r << 16 | g << 8 | b);
}

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

t_mlx	init_mlx(void)
{
	t_mlx	mlx;

	mlx_create_window(&mlx);
	mlx_create_img(&mlx);
	mlx_hooks(&mlx);
	return (mlx);
}

int	main(void)
{
	t_mlx	mlx;

	mlx = init_mlx();
	render(mlx);
	mlx_loop(mlx.mlx_ptr);
}
