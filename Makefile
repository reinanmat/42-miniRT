NAME = 			miniRT

SRCS_PATH =		./srcs
OBJS_PATH =		./objs
LIBFT_PATH =	./libft

FILES =			main \
				render \
				color \
				hit_sphere \
				mlx/mlx_hooks \
				vec_operations/basic_operations \
				vec_operations/scalar_operations \
				vec_operations/extra_operations \
				mlx/mlx_create_img \
				mlx/mlx_img_pix_put \
				mlx/mlx_close_window \
				mlx/mlx_create_window \
				utils_tests


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

re: fclean all

.PHONY: all clean fclean re
