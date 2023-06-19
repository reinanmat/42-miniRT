/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:32:12 by revieira          #+#    #+#             */
/*   Updated: 2023/06/19 14:13:36 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WINDOW_NAME "minirt"
# define WIDTH 400
# define HEIGHT 400

# define KEY_ESC 0xff1b

# include <mlx.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_mlx;

typedef struct s_color
{
	double	x;
	double	y;
	double	z;
}	t_color;

typedef struct s_data
{
	t_mlx	mlx;
}	t_data;

//color
int		get_color(t_color color);

void	ft_free(void *ptr);

//render
int		render(t_mlx mlx);

//mlx functions
void	mlx_close_window(t_mlx *mlx);
void	mlx_create_img(t_mlx *mlx);
void	mlx_create_window(t_mlx *mlx);
void	mlx_hooks(t_mlx *mlx);
void	mlx_img_pix_put(t_img *img, int x, int y, int color);

#endif
