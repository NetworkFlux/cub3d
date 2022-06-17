# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swautele <swautele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 15:23:41 by npinheir          #+#    #+#              #
#    Updated: 2022/06/17 19:18:39 by swautele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME = cub3D

# Compiling flags
FLAGS = -Wall -Wextra -Werror -Iinclude

# Folders
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./include/
LIBFT_DIR = ./libft/
MINLBX_DIR = ./minilibx_opengl/

# Source files and object files
SRC_FILES = main.c errors.c cub_file.c utils.c file_extractor.c \
			map_extractor.c graph/minimap.c init_window.c graph/move.c  \
			graph/get_texture.c graph/check_walls.c graph/distance.c \
			graph/draw_col.c graph/draw_key.c graph/draw_view.c \
			graph/graphic_utils.c graph/hor_dist.c graph/keyboard.c \
			graph/vert_dist.c

HEADER = ./include/cub3D.h
			 
OBJ_FILES = $(SRC_FILES:.c=.o)

# Paths
SRC	:= $(wildcard $(SRC_DIR)*.c)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
MINLBX	= $(addprefix $(MINLBX_DIR), libmlx.a)

# Libft and Minilibx linkers
LNK  = -L $(LIBFT_DIR) -lft -L $(MINLBX_DIR) \
			-lmlx -framework OpenGL -framework AppKit

# Colors
RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m

# all rule
all: obj $(LIBFT) $(MINLBX) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR) obj/graph
	@echo "\t$(GREEN)✔ Object folder created in cub3D !$(NONE)"
	
$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HEADER)
	@gcc $(FLAGS) -I $(MINLBX_DIR) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
	
$(LIBFT):
	@make -C $(LIBFT_DIR)
	
$(MINLBX):
	@make -C $(MINLBX_DIR)

# Compiling
$(NAME): obj $(OBJ) 
	@gcc $(OBJ) $(LNK) -lm -o $(NAME)
	@echo "\t$(GREEN)✔ cub3D ready to run !$(NONE)"

# clean rule
clean:
	@rm -Rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MINLBX_DIR) clean
	@echo "\t$(GREEN)✔ All objects removed !$(NONE)"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "\t$(GREEN)✔ Project fully cleaned !$(NONE)"

# re rule
re: fclean all

#autosave rule
save:
	git commit -am "$(MAKECMDGOALS)" 
	git push

# phony
.PHONY: all clean fclean re save
