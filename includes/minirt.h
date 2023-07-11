/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:32:12 by revieira          #+#    #+#             */
/*   Updated: 2023/07/11 17:02:43 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 1024
# define HEIGHT 576
# define WINDOW_NAME "minirt"

# define KEY_ESC 0xff1b

# define PI 3.14159265358979323846264338327950288419716939937510L

# include <mlx.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "vec3.h"
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

typedef struct s_cam
{
	double	fov;
	double	viewport_height;
	double	viewport_width;
	double	focal_length;
	t_point	origin;
	t_point	horizontal;
	t_point	vertical;
	t_point	lower_left_corner;
}	t_cam;

typedef struct s_ray
{
	t_point	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_light
{
	t_color	color;
	t_point	position;
	double	brightness;
}	t_light;

typedef struct s_sphere
{
	t_point center;
	double	radius;
	t_color	color;
}	t_sphere;

typedef struct s_cylinder
{
	t_point center;
	t_vec3	vector;
	double	radius;
	double	height;
	t_color	color;
}	t_cylinder;

typedef struct s_plane
{
	t_point	center;
	t_vec3	vector;
	t_color	color;
}	t_plane;

typedef struct s_world
{
	t_cam		cam;
	t_light		light;
	t_light		ambient_light;
	t_sphere	*sp;
	t_cylinder	*cy;
	t_plane		*pl;
}	t_world;

typedef struct s_data
{
	t_mlx	mlx;
	t_world	world;
}	t_data;

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

//utils
void	print_point(t_point point);
void	print_cam(t_cam cam);

#endif
