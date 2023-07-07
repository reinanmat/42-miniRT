
NAME = 			miniRT
SRCS_PATH =		./srcs
OBJS_PATH =		./objs
LIBFT_PATH =	./libft

FILES =			main \
				return_struct \
				render \
				objects \
				ray/ray \
				ray/ray_color \
				hittable/hit \
				hittable/hit_sphere \
				hittable/hittable_lst \
				vectors/basic_operations \
				vectors/scalar_operations \
				vectors/extra_operations \
				color/color \
				color/gradient_color \
				mlx/mlx_hooks \
				vec_operations/basic_operations \
				vec_operations/scalar_operations \
				vec_operations/extra_operations \
				mlx/mlx_create_img \
				mlx/mlx_img_pix_put \
				mlx/mlx_close_window \
				mlx/mlx_create_window \
				utils_tests \
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
				aux_functions/reset_fd



SRCS =			$(addprefix $(SRCS_PATH)/, $(addsuffix .c, $(FILES)))
OBJS =			$(addprefix $(OBJS_PATH)/, $(addsuffix .o, $(FILES)))

CFLAGS = 		-Wall -Wextra -Werror -g3
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

valg:
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./miniRT file.rt

re: fclean all

.PHONY: all clean fclean re
