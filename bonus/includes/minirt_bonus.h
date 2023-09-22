/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:32:12 by revieira          #+#    #+#             */
/*   Updated: 2023/09/22 16:40:40 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# define WIDTH 720
# define HEIGHT 480
# define WINDOW_NAME "minirt"

# define KEY_ESC 0xff1b

# define AMBIENT 0
# define DIFFUSE 1
# define SPECULAR 2

# define EPSILON 0.00001

# include <mlx.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include "vec3_bonus.h"
# include "ray_bonus.h"
# include "world_bonus.h"
# include "hittable_bonus.h"
# include "matrices_bonus.h"
# include "objects_bonus.h"
# include "intersection_bonus.h"
# include "../../libft/libft.h"

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

//utils
int		reset_fd(int fd, char *filename);
int		double_equals(double a, double b);
char	*get_file_content(int fd, char *filename);
char	**get_splitted_identifier(char **lines, char *identifier);
void	assign_t_point(t_point *coordinate, char *param);
void	assign_t_color(t_color *color, char *param);
int		check_equal_vec3(t_vec3 a, t_vec3 b);

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
int		is_valid_texture(char *str);
int		is_valid_pattern(char *str);
int		is_valid_material_type(char *str);
int		is_valid_cone(char **params, int number_of_params);

//linear algebra
t_ray	transform_ray(t_ray	ray, t_matrix transform);
t_vec3	reflect(t_vec3 in, t_vec3 normal);
t_vec3	normal_at(t_hittable *object, t_point world_point);
t_vec3	local_normal_at(t_hittable *object, t_point local_point);

t_color	color_at(t_ray ray, t_world world);

//lighting
t_color	lighting(t_light light, t_comps comps, t_amb_light amb, int shadow);
t_color	shade_hit(t_world world, t_comps comps);
int		is_shadowed(t_world world, t_light light, t_point point);
t_color	compute_specular(double reflect_dot_eye, t_comps comps, t_light light);
double	compute_reflect_dot_eye(t_light light, t_comps comps);
double	compute_light_dot_normal(t_light light, t_comps comps);
t_color	compute_diffuse(t_light light, double light_dot_normal, t_comps comps);
t_color	compute_ambient(t_light light, t_comps comps);

//utils tests - delet
t_light	*point_light(t_point pos, double intensity);
void	timer(void);
void	print_matrix2(t_matrix matrix);
void	print_point(t_point point);
void	print_cam(t_cam cam);
void	print(char *str1, t_point *p1, char *str2, t_point *p2);
void	test_cylinder(void);
void	test_cone(void);
void	test_pattern(void);
t_world	room(void);
t_world	default_world(void);
t_world	complex_world(void);
t_world	test_multiple_objects(void);
t_world	cylinder_world(void);
t_world	chess2(void);
t_world	doguinho(void);
t_world	cone_world(void);
t_plane		*unit_plane(void);
t_sphere	*unit_sphere(void);
t_cylinder	*unit_cylinder(void);
t_cone		*unit_cone(void);

#endif
