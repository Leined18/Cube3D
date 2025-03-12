# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 11:56:46 by danpalac          #+#    #+#              #
#    Updated: 2025/03/12 12:02:21 by danpalac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Configuración de directorios
NAME    := libmlx42.a
LIB     := ../lib/
MLX_LIB := ../lib/mlx/
BUILD   := build/

# Regla principal
all: $(NAME)

# Compilación de MLX42
$(NAME):
	@echo "Compilando MLX42..."
	@cmake -S mlx -B $(BUILD)
	@make -sC $(BUILD) -j4
	@mkdir -p $(LIB)
	@mkdir -p $(MLX_LIB)
	@cp $(BUILD)/$(NAME) $(MLX_LIB)
	@cp -r mlx/include $(MLX_LIB)

# Limpieza
clean:
	@rm -rf $(BUILD)
	@rm -rf $(MLX_LIB)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re