# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rkaras <rkaras@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2024/04/09 16:12:46 by rkaras        #+#    #+#                  #
#    Updated: 2024/05/15 16:58:20 by rkaras        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = ./Libft/libft.a
MLXLIB = MLX42/build/libmlx42.a
LIBMLX = ./MLX42
CFLAGS = -Wall -Werror -Wextra
FLAGSMLX = -ldl -lglfw -pthread -lm

SOURCE = main.c \
			parsing.c \
			str_map_checks.c \
			arr_map_checks.c \
			struct_inits.c \
			texture.c \
			free_and_error.c \
			add_to_window.c \
			key_movements.c \
			end_checkers.c \

OBJECTS = $(SOURCE:%.c=%.o)

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
		@$(MAKE) -C ./Libft

$(NAME): $(LIBFT) $(MLXLIB) $(OBJECTS)
		@cc $(CFLAGS) $(FLAGSMLX) $(OBJECTS) $(LIBFT) $(MLXLIB) -o $(NAME)

%.o:%.c
	@cc $(CFLAGS) -c -o $@ $^

clean:
	@$(MAKE) clean -C ./Libft
	@rm -f $(OBJECTS)
	@rm -rf $(LIBMLX)/build

fclean:	clean
	@$(MAKE) fclean -C $ ./Libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
