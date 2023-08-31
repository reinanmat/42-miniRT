/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:32:12 by revieira          #+#    #+#             */
/*   Updated: 2023/08/30 20:56:41 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 720
# define HEIGHT 480
# define WINDOW_NAME "minirt"

# define KEY_ESC 0xff1b

# define EPSILON 0.00001

# include <mlx.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include "vec3.h"
# include "ray.h"
# include "world.h"
# include "hittable.h"
# include "matrices.h"
# include "objects.h"
# include "intersection.h"
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

typedef struct s_data
{
	t_mlx	mlx;
	t_world	world;
}	t_data;

//render
int		render(t_data data);

//mlx functions
void	mlx_close_window(t_mlx *mlx);
void	mlx_create_img(t_mlx *mlx);
void	mlx_create_window(t_mlx *mlx);
void	mlx_hooks(t_data *data);
void	mlx_img_pix_put(t_img *img, int x, int y, int color);

//utils tests - delet
void	timer();
void	print_matrix2(t_matrix matrix);
void	print_point(t_point point);
void	print_cam(t_cam cam);
//worlds
t_world	default_world(void);
t_world	complex_world(void);

//utils
int		reset_fd(int fd, char *filename);
char	*get_file_content(int fd, char *filename);
char	**get_splitted_identifier(char **lines, char *identifier);
void	assign_t_point(t_point *coordinate, char *param);
void	assign_t_color(t_color *color, char *param);

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

//linear algebra
t_matrix	transform_object(t_point translation, t_vec3 scale);
t_ray	transform_ray(t_ray	ray, t_matrix transform);
t_vec3	reflect(t_vec3 in, t_vec3 normal);
t_vec3	normal_at(t_hittable *object, t_point world_point);

t_color	color_at(t_ray ray, t_world world);

t_color	lighting(t_light light, t_comps comps);
t_light	point_light(t_point pos, double intensity);
int		is_shadowed(t_world world, t_point point);

#endif
