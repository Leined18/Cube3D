# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 14:34:27 by danpalac          #+#    #+#              #
#    Updated: 2025/03/10 13:53:38 by danpalac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==========COLOURS=============================================================#

# Basic Colors
BLACK       = \033[0;30m
RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
MAGENTA     = \033[0;35m
CYAN        = \033[0;36m
WHITE       = \033[0;37m

# Bright Colors
BOLD_BLACK  = \033[1;30m
BOLD_RED    = \033[1;31m
BOLD_GREEN  = \033[1;32m
BOLD_YELLOW = \033[1;33m
BOLD_BLUE   = \033[1;34m
BOLD_MAGENTA= \033[1;35m
BOLD_CYAN   = \033[1;36m
BOLD_WHITE  = \033[1;37m

# Extended Colors (256 colors)
ORANGE      = \033[38;5;208m
WINE        = \033[38;5;88m
LIME        = \033[38;5;190m
TURQUOISE   = \033[38;5;38m
LIGHT_PINK  = \033[38;5;13m
DARK_GRAY   = \033[38;5;235m
LIGHT_RED   = \033[38;5;203m
LIGHT_BLUE  = \033[38;5;75m

BRIGHT_BLUE = \033[38;5;27m
BRIGHT_GREEN= \033[38;5;46m
BRIGHT_YELLOW=\033[38;5;226m
BRIGHT_CYAN = \033[38;5;51m
BRIGHT_WHITE= \033[38;5;231m

# Reseteo de color
NO_COLOR    = \033[0m
DEF_COLOR   = \033[0;39m
CLEAR_LINE  = \033[2K
MOVE_UP     = \033[1A

#==========NAMES===============================================================#

NAME		:= cube3d
NAME_LIB	:= libcube.a
LIBFT_LIB	:= libft.a
MLX_LIB		:= libmlx42.a

#==========DIRECTORIES=======================================================#

INC 			:= inc/
SRC_DIR 		:= src/
OBJ_DIR 		:= obj/
MLX_DIR			:= submodules/mlx/
LIBFT_DIR		:= submodules/libft/
MEMTRACK_DIR	:= submodules/memtrack/
LIB_DIR			:= submodules/lib/
SRC_DIR			:= src/

LIBFT			:= $(LIBFT_DIR)$(LIBFT_LIB)
MLX				:= $(MLX_DIR)/build/$(MLX_LIB)
INCLUDES		:= $(INC)/*.h

#==========COMMANDS============================================================#

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g3 -fsanitize=address
RM			:= rm -rf
AR			:= ar rcs
LIB			:= ranlib
MKDIR 		:= mkdir -p
IFLAGS		:= -I$(INC) -I$(LIB_DIR) -I$(MLX_DIR)include/MLX42/
LFLAGS		:= -L$(LIB_DIR) -lft -lmt -L$(MLX_DIR)build/ -lmlx42 

#==========FILES==============================================================#

# Variables de fuentes y objetos
SRCS      := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS      := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))
DEPS      := $(patsubst $(OBJ_DIR)%.o, $(OBJ_DIR)%.d, $(OBJS))

#==========RULES==============================================================#

-include $(DEPS)
all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)	
	@$(CC) $(CFLAGS) $(LFLAGS) $(IFLAGS) -MP -MMD -c $< -o $@ 

$(LIB_DIR):
	@make -sC $(LIBFT_DIR)
	@make -sC $(MEMTRACK_DIR)
	@cmake $(MLX_DIR) -B build

$(NAME): $(OBJS) $(LIB_DIR) 
	@$(AR) $(NAME_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(LFLAGS) $(IFLAGS) -o $(NAME)
	@echo "$(BOLD_BLUE)[$(BRIGHT_GREEN)$(NAME)$(DEF_COLOR)$(BOLD_BLUE)] compiled!$(DEF_COLOR)"
	@echo "$(TURQUOISE)------------\n| Done! 👌 |\n------------$(DEF_COLOR)"

clean_submodules:
	@make fclean -sC $(LIBFT_DIR)
	@make fclean -sC $(MEMTRACK_DIR)
	
clean: clean_submodules
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(RM) $(OBJ_DIR) $(LIB_DIR); \
		echo "$(CYAN)[$(NAME)]:\tobject files $(GREEN) => Cleaned!$(DEF_COLOR)"; \
	fi

fclean: clean
	@$(RM) -rf $(NAME) $(NAME_LIB) build
	@make fclean -sC $(LIBFT_DIR)

re: fclean all

.SILENT: all clean fclean
.PHONY: all clean fclean re
