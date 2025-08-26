# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 14:34:27 by danpalac          #+#    #+#              #
#    Updated: 2025/06/05 10:23:36 by danpalac         ###   ########.fr        #
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

NAME		:= libft.a

#==========COMMANDS============================================================#

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g3 #-fsanitize=address
RM			:= rm -rf
AR			:= ar rcs
LIB			:= ranlib
MKDIR 		:= mkdir -p

##==========DIRECTORIES=======================================================#

INC := inc/

SRC_DIR := srcs/
OBJ_DIR := obj/
LIB_DIR := ../lib/
LIBFT_LIB := $(LIB_DIR)libft/

INCLUDES := $(INC)*.h
IS_DIR := is/
LST_DIR := lst/
MEM_DIR := mem/
PUT_DIR := put/
STR_DIR := str/
TO_DIR := to/
PRINTF_DIR := printf/
PRINTF_PUT_DIR := printf/put/
MATH_DIR := math/
GET_DIR := get/

#==========SOURCES============================================================#


IS_FILES	:= ft_isalpha ft_isalnum ft_isascii ft_isdigit ft_isprint ft_isspace ft_isndup ft_isstrnum

MEM_FILES	:= ft_bzero ft_calloc ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset\
			   ft_memrev ft_memccpy ft_memdel ft_free_2d ft_free_null ft_hold_mem ft_realloc
			   
PUT_FILES	:= ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_error ft_successful ft_putstr_color_fd\
				ft_putaddr_fd ft_putbase_fd ft_puthexa_fd ft_putunsigned_fd

TO_FILES	:= ft_atoi ft_itoa ft_atol ft_atoll ft_tolower ft_toupper ft_bin2char ft_char2bin ft_bintoa ft_atobin

STR_FILES	:= ft_split ft_strchr ft_strdup ft_striteri ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strcspn ft_strmapi ft_strncmp \
			ft_strnstr ft_strrchr ft_strtrim ft_strrev ft_substr ft_strrncmp ft_strtok ft_straddc ft_strequ

LST_FILES	:= ft_lstnew_bonus ft_lstadd_front_bonus ft_lstsize_bonus ft_lstlast_bonus ft_lstadd_back_bonus \
		  	ft_lstdelone_bonus ft_lstclear_bonus ft_lstiter_bonus ft_lstmap_bonus ft_lstfind_bonus
			
PRINTF_FILES	:= ft_printf ft_printf_fd

MATH_FILES	:= ft_abs ft_index ft_insort ft_sqrt ft_fib ft_fact 

GET_FILES := get_next_line

#==========FILES###===========================================================#

SRC_FILES+=$(addprefix $(IS_DIR), $(IS_FILES))
SRC_FILES+=$(addprefix $(MEM_DIR), $(MEM_FILES))
SRC_FILES+=$(addprefix $(PUT_DIR), $(PUT_FILES))
SRC_FILES+=$(addprefix $(TO_DIR), $(TO_FILES))
SRC_FILES+=$(addprefix $(STR_DIR), $(STR_FILES))
SRC_FILES+=$(addprefix $(LST_DIR), $(LST_FILES))
SRC_FILES+=$(addprefix $(PRINTF_DIR), $(PRINTF_FILES))
SRC_FILES+=$(addprefix $(PRINTF_PUT_DIR), $(PRINTF_PUT_FILES))
SRC_FILES+=$(addprefix $(MATH_DIR), $(MATH_FILES))
SRC_FILES+=$(addprefix $(GET_DIR), $(GET_FILES))
SRC_FILES+=$(addprefix $(CMD_DIR), $(CMD_FILES))

SRCS := $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS := $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

#==========RULES==============================================================#

-include $(DEPS)
all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	@mkdir -p $(dir $@)
	@printf "%b" "$(BOLD_CYAN)[LIBFT]:\t$(DEF_COLOR)$(BOLD_GREEN)$<$(DEF_COLOR)\r"
	@$(CC) $(CFLAGS) -I$(INC) -MMD -MP -c $< -o $@
	@printf "%b" "$(BOLD_BLUE)$(DEF_COLOR)\r"

$(NAME) : $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(BOLD_BLUE)[$(BRIGHT_GREEN)$(NAME)$(DEF_COLOR)$(BOLD_BLUE)] compiled!$(DEF_COLOR)"
	@echo "$(TURQUOISE)------------\n| Done! 👌 |\n------------$(DEF_COLOR)"
	@$(MKDIR) $(LIB_DIR)
	@cp $(NAME) $(LIB_DIR)
	@cp -r inc $(LIB_DIR)

p: $(NAME)
	@$(CC) $(CFLAGS) -I$(INC) main.c libft.a -o program

clean: 
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(RM) $(OBJ_DIR) $(LIB_DIR); \
		echo "$(CYAN)[$(NAME)]:\tobject files $(GREEN) => Cleaned!$(DEF_COLOR)"; \
	fi

fclean: clean
	@$(RM) $(NAME) program a.out

re: fclean all

norm:
	@norminette $(SRC) $(INC) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm
