/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:32:12 by revieira          #+#    #+#             */
/*   Updated: 2023/07/21 12:59:19 by fnacarel         ###   ########.fr       */
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
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
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
	t_point	direction;
}	t_ray;

typedef struct s_data
{
	t_mlx	mlx;
	t_cam	cam;
}	t_data;

typedef t_point	t_color;
typedef t_point	t_vec3;

//color
int		get_color(t_color color);

//render
int		render(t_data data, int height);

//hit
double	hit_sphere(t_point center, double radius, t_ray ray);

//mlx functions
void	mlx_close_window(t_mlx *mlx);
void	mlx_create_img(t_mlx *mlx);
void	mlx_create_window(t_mlx *mlx);
void	mlx_hooks(t_mlx *mlx);
void	mlx_img_pix_put(t_img *img, int x, int y, int color);

//vec operators
t_vec3	add(t_vec3 a, t_vec3 b);
t_vec3	minus(t_vec3 a, t_vec3 b);
t_vec3	multiply(t_vec3 a, t_vec3 b);
t_vec3	division(t_vec3 a, t_vec3 b);
t_vec3	s_multiply(t_vec3 a, double n);
t_vec3	s_division(t_vec3 a, double n);
double	length_square(t_vec3 a);
double	magnitude(t_vec3 a);
t_vec3	normalize(t_vec3 a);
double	dot(t_vec3 m1, t_vec3 m2);
t_vec3	at(t_ray ray, double t);

//utils
void	print_point(t_point point);
void	print_cam(t_cam cam);
int		reset_fd(int fd, char *filename);

//file parsing
int		received_invalid_param(char *filename);
int		expected_number_of_identifiers(char **lines);
void	trim_lines(char **lines);
int		map_parsed_successfully(char **lines);
int		is_valid_identifier(char *identifier);
int		is_valid_ambient_lighting(char **params, int number_of_params);
int		is_valid_camera(char **params, int number_of_params);
int		is_valid_light(char **params, int number_of_params);
int		is_valid_sphere(char **params, int number_of_params);
int		is_valid_plane(char **params, int number_of_params);
int		is_valid_cylinder(char **params, int number_of_params);
int		is_number(const char *str);
int		set_contain_only_numbers(const char *str);
int		is_valid_rgb_set(const char *str);
int		is_valid_lighting_ratio(const char *str);
int		is_valid_coordinates(const char *str);
int		expected_number_of_fields(const char *str, int expected_fields);
int		is_valid_3d_normalized_vec(const char *str);
int		count_dots(const char *str);

#endif
