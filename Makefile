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
NAME		:= cub3d
BONUS		:= cub3d_bonus
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g3 -fsanitize=address -O3
RM			:= rm -rf
MKDIR		:= mkdir -p

BONUS_DIR	:= bonus/
DEFAULT_DIR := default/

NAME_PROGRAM := $(DEFAULT_DIR)$(NAME)
BONUS_PROGRAM := $(BONUS_DIR)$(BONUS)

# Regla principal
all: $(NAME_PROGRAM) 

# Compilación final del ejecutable
$(NAME_PROGRAM):
	@make -sC $(DEFAULT_DIR)
	@cp $(NAME_PROGRAM) .

$(BONUS_PROGRAM):
	@make -sC $(BONUS_DIR)
	@cp $(BONUS_PROGRAM) .

bonus: $(BONUS_PROGRAM)
	
bmap: $(BONUS_PROGRAM)
	@./$(BONUS) ./bonus/assets/maps/scene_1.cub

dmap: $(NAME_PROGRAM)
	@./$(NAME) ./default/assets/maps/scene_1.cub

# Limpieza
clean:
	@make fclean -sC $(DEFAULT_DIR)
	@make fclean -sC $(BONUS_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS)


re: fclean all

.SILENT: all clean fclean re