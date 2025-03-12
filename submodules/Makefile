LIBFT := libft/libft.a
MEMTRACK := memtrack/libmt.a
MLX42 := mlx42/libmlx42.a

LIB_DIR := lib/

all: $(LIBFT) $(MEMTRACK) $(MLX42)

$(LIBFT):
	@make -sC libft

$(MEMTRACK):
	@make -sC memtrack

$(MLX42):
	@make -sC mlx42

clean:
	@make fclean -sC libft/
	@make fclean -sC memtrack/
	@make fclean -sC mlx42/

fclean: clean
	@rm -rf $(LIB_DIR)

re: fclean all

.SILENT: clean fclean 
	