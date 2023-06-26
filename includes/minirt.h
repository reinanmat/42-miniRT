/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:32:12 by revieira          #+#    #+#             */
/*   Updated: 2023/06/26 18:17:00 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WINDOW_NAME "minirt"
# define WIDTH 1200
# define HEIGHT (int)(WIDTH/16.0*9.0)

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

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_cam
{
	double	viewport_height;
	double	viemport_width;
	double	focal_length;
	t_point	origin;
	t_point	horizontal;
	t_point	vertical;
	t_point	lower_left_corner;
}	t_cam;

typedef struct s_ray
{
	t_point	origin;
	t_point	direction;
}	t_ray;

typedef struct s_data
{
	t_mlx	mlx;
	t_cam	cam;
}	t_data;

typedef t_point	t_color;

//color
int		get_color(t_color color);

//render
int		render(t_data data);

//hit
double	hit_sphere(t_point center, double radius, t_ray ray);

//mlx functions
void	mlx_close_window(t_mlx *mlx);
void	mlx_create_img(t_mlx *mlx);
void	mlx_create_window(t_mlx *mlx);
void	mlx_hooks(t_mlx *mlx);
void	mlx_img_pix_put(t_img *img, int x, int y, int color);

//vec operators
t_point	add(t_point a, t_point b);
t_point	minus(t_point a, t_point b);
t_point	multiply(t_point a, t_point b);
t_point	multiply_n(t_point a, double n);
t_point	division(t_point a, t_point b);
t_point	division_n(t_point a, double n);
double	lenght_square(t_point a);
double	lenght(t_point a);
t_point	unit_vector(t_point a);
double	dot(t_point m1, t_point m2);
t_point	at(t_ray ray, double t);

//utils
void	print_point(t_point point);
void	print_cam(t_cam cam);

#endif
