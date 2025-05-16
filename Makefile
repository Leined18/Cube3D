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

# Variables básicas
NAME		:= cube3d
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g3 -fsanitize=address
RM			:= rm -rf
MKDIR		:= mkdir -p

SUBMODULES	:= submodules/
LIB			:= submodules/lib/
SRC_DIR 	:= src/
OBJ_DIR 	:= obj/
INC_DIR		:= inc/

IFLAGS		:= -I$(INC_DIR) -I$(LIB)$(INC_DIR)
LDFLAGS 	= -L$(LIB) -lmlx42 -lft -lmt -lX11 -lXext -ldl -lglfw -pthread -lm -lbsd

# Variables de fuentes y objetos
SRCS		:= $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS		:= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))


# Regla principal
all: $(NAME)

# Compilación de objetos
$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) $(LDFLAGS) -MP -MMD -c $< -o $@

$(LIB):
	@make -sC $(SUBMODULES)

# Compilación final del ejecutable
$(NAME): $(LIB) $(OBJS) 
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(BOLD_BLUE)[$(BOLD_MAGENTA)$(NAME)$(DEF_COLOR)$(BOLD_BLUE)] ready!$(DEF_COLOR)"
	@echo "$(TURQUOISE)------------\n| Done! 👌 |\n------------$(DEF_COLOR)"

# Limpieza
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(RM) $(OBJ_DIR); \
		echo "$(CYAN)[$(NAME)]:\tobject files $(GREEN) => Cleaned!$(DEF_COLOR)"; \
	fi
	@make fclean -sC $(SUBMODULES)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.SILENT: all clean fclean re