NAME = 			miniRT
SRCS_PATH =		./mandatory/srcs
OBJS_PATH =		./objs
TESTS_PATH =	./mandatory/tests
LIBFT_PATH =	./libft

FILES =			main \
				render \
				color \
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
				world/init_world \
				world/objects \
				world/material \
				world/camera \
				aux_functions/reset_fd \
				aux_functions/get_file_content \
				aux_functions/get_splitted_identifier \
				aux_functions/assign_value \
				aux_functions/sort_lst \
				aux_functions/double_equals \
				aux_functions/check_equal_vec3


TEST_FILES =	cylinder worlds utils_tests unit_shapes

SRCS =			${FILES:%=$(SRCS_PATH)/%.c} ${TEST_FILES:%=$(TESTS_PATH)/%.c}
OBJS =			${FILES:%=$(OBJS_PATH)/%.o} ${TEST_FILES:%=$(OBJS_PATH)/%.o}

CFLAGS = 		-Wall -Wextra -Werror -O3
LIBXFLAGS =		-lmlx -lXext -lX11 -lm -lz
LIBFTFLAGS =	-L $(LIBFT_PATH) -lft

all: libft $(NAME)

libft:
	@make -C $(LIBFT_PATH) --no-print-directory

$(NAME): $(OBJS) $(LIBFT_PATH)/libft.a
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTFLAGS) $(LIBXFLAGS)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	@mkdir -p $(@D)
	cc $(CFLAGS) -I ./includes -c $< -o $@

$(OBJS_PATH)/%.o: $(TESTS_PATH)/%.c | $(OBJS_PATH)
	@mkdir -p $(@D)
	cc $(CFLAGS) -I ./includes -c $< -o $@

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

$(LIBFT_PATH)/libft.a:
	make -C $(LIBFT_PATH) --no-print-directory

clean:
	rm -rf $(OBJS_PATH)
	make -C $(LIBFT_PATH) clean --no-print-directory

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean --no-print-directory

valg: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./miniRT $(param1)

re: fclean all

.PHONY: all clean fclean re
