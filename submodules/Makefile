LIBFT := libft/libft.a
MEMTRACK := memtrack/libmt.a
MLX42 := mlx/libmlx.a

LIB_DIR := lib/

all: $(LIBFT) $(MEMTRACK) $(MLX42)

$(LIBFT):
	@make -sC libft

$(MEMTRACK):
	@make -sC memtrack

$(MLX42):
	@make -sC mlx
	cp mlx/libmlx.a $(LIB_DIR)
	cp mlx/libmlx_Linux.a $(LIB_DIR)
	cp mlx/*.h $(LIB_DIR)inc/

clean:
	@make fclean -sC libft/
	@make fclean -sC memtrack/
	@make clean -sC mlx/

fclean: clean
	@rm -rf $(LIB_DIR)

re: fclean all

.SILENT: clean fclean 
	