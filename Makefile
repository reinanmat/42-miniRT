NAME 				= miniRT
SRCS_PATH 			= ./mandatory/srcs
OBJS_PATH 			= ./objs
INCLUDE_PATH		= ./mandatory/includes/

NAME_BONUS			= miniRT_bonus
BONUS_SRCS_PATH 	= ./bonus/srcs
BONUS_OBJS_PATH		= ./bonus_objs
BONUS_INCLUDE_PATH	= ./bonus/includes/

LIBFT_PATH 			= ./libft

FILES =			main \
				render \
				lighting_and_shadow/shade_hit \
				lighting_and_shadow/lighting \
				lighting_and_shadow/is_shadowed \
				ray/reflect \
				ray/normal_at \
				ray/ray_for_pixel \
				structures/hittable_lst \
				structures/hittable_getters \
				structures/clean_hittable \
				structures/intersection_lst \
				structures/create_structure \
				linear_algebra/vectors/basic_operations \
				linear_algebra/vectors/scalar_operations \
				linear_algebra/vectors/extra_operations \
				linear_algebra/matrices/matrix_create \
				linear_algebra/matrices/matrix_operators \
				linear_algebra/matrices/matrix_rotates \
				linear_algebra/matrices/matrix_utils \
				linear_algebra/matrices/matrix_transform \
				linear_algebra/matrices/view_transformation \
				linear_algebra/conversions \
				linear_algebra/transforms \
				intersections/intersection \
				intersections/intersect_sphere \
				intersections/intersect_plane \
				intersections/intersect_cylinder \
				mlx/mlx_hooks \
				mlx/mlx_create_img \
				mlx/mlx_img_pix_put \
				mlx/mlx_close_window \
				mlx/mlx_create_window \
				file_parsing/parse \
				file_parsing/map_parse \
				file_parsing/parse_aux_functions/expected_number_of_identifiers \
				file_parsing/parse_aux_functions/trim_lines \
				file_parsing/parse_aux_functions/is_valid_identifier \
				file_parsing/parse_aux_functions/is_valid_ambient_lighting \
				file_parsing/parse_aux_functions/is_valid_camera \
				file_parsing/parse_aux_functions/is_valid_light \
				file_parsing/parse_aux_functions/is_valid_sphere \
				file_parsing/parse_aux_functions/is_valid_plane \
				file_parsing/parse_aux_functions/is_valid_cylinder \
				file_parsing/parse_aux_functions/is_number \
				file_parsing/parse_aux_functions/is_valid_rgb_set \
				file_parsing/parse_aux_functions/set_contain_only_numbers \
				file_parsing/parse_aux_functions/is_valid_lighting_ratio \
				file_parsing/parse_aux_functions/is_valid_coordinates \
				file_parsing/parse_aux_functions/expected_number_of_fields \
				file_parsing/parse_aux_functions/is_valid_3d_normalized_vec \
				file_parsing/parse_aux_functions/count_dots \
				file_parsing/parse_aux_functions/only_two_commas \
				world/init_world \
				world/objects \
				world/material \
				world/camera \
				aux_functions/color \
				aux_functions/reset_fd \
				aux_functions/get_file_content \
				aux_functions/get_splitted_identifier \
				aux_functions/assign_value \
				aux_functions/sort_lst \
				aux_functions/double_equals \
				aux_functions/check_equal_vec3 \
				aux_functions/get_orientation

FILES_BONUS =	${FILES:%=%_bonus} \
				intersections/intersect_cone_bonus \
				intersections/hit_objects_bonus \
				ray/specific_normals_bonus \
				world/pattern_bonus \
				world/texture_bonus \
				world/texture_map_bonus \
				world/init_objects_bonus \
				structures/get_transforms_bonus \
				lighting_and_shadow/compute_lighting_bonus \
				file_parsing/parse_aux_functions/is_valid_texture_bonus \
				file_parsing/parse_aux_functions/is_valid_pattern_bonus \
				file_parsing/parse_aux_functions/is_valid_material_type_bonus \
				file_parsing/parse_aux_functions/is_valid_cone_bonus \

SRCS =			${FILES:%=$(SRCS_PATH)/%.c}
OBJS =			${FILES:%=$(OBJS_PATH)/%.o}

SRCS_BONUS =	${FILES_BONUS:%=$(BONUS_SRCS_PATH)/%.c}
OBJS_BONUS =	${FILES_BONUS:%=$(BONUS_OBJS_PATH)/%.o}

CC = cc
CFLAGS = 		-Wall -Wextra -Werror -O3
LIBXFLAGS =		-lmlx -lXext -lX11 -lm -lz
LIBFTFLAGS =	-L $(LIBFT_PATH) -lft

all: libft $(NAME)

libft:
	@make -C $(LIBFT_PATH) --no-print-directory

$(LIBFT_PATH)/libft.a:
	make -C $(LIBFT_PATH) --no-print-directory

$(NAME): $(OBJS) $(LIBFT_PATH)/libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTFLAGS) $(LIBXFLAGS)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(OBJS_PATH) -c $< -o $@

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

bonus: libft $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT_PATH)/libft.a
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFTFLAGS) $(LIBXFLAGS)

$(BONUS_OBJS_PATH)/%.o: $(BONUS_SRCS_PATH)/%.c | $(BONUS_OBJS_PATH)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(BONUS_INCLUDE_PATH) -c $< -o $@

$(BONUS_OBJS_PATH):
	mkdir -p $(BONUS_OBJS_PATH)

clean:
	rm -rf $(OBJS_PATH)
	make -C $(LIBFT_PATH) clean --no-print-directory

clean_bonus:
	rm -rf $(BONUS_OBJS_PATH)
	make -C $(LIBFT_PATH) clean --no-print-directory

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean --no-print-directory

fclean_bonus: clean_bonus
	rm -f $(NAME_BONUS)
	make -C $(LIBFT_PATH) fclean --no-print-directory

re: fclean all

rebonus: fclean_bonus bonus

.PHONY: all clean fclean re
