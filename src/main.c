/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/07/10 09:47:36 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*Check if the map file extension is ".cub". Error and exit if not*/
void	check_arg_cub(char *name)
{
	int	len_total;
	int	len_name;

	len_total = ft_strlen(name);
	len_name = len_total - 4;
	if (!(len_total > 4 && ft_strncmp(name + len_name, ".cub", 4) == 0
			&& name[len_total - 5] != '/'))
	{
		ft_printf("Error: Invalid map file extension. Expected '.cub'\n");
		exit(EXIT_FAILURE);
	}
}

void ft_set_cursor(t_game *g)
{
    //mlx_set_cursor_mode(g->render.mlx, MLX_MOUSE_HIDDEN);
    //g->cursor_hidden = true;
    mlx_set_mouse_pos(g->render.mlx, g->render.screen_width / 2, g->render.screen_height / 2);
}

void ft_launch_game(void *p)
{
	t_game *game;
	int i;

	game = (t_game *)p;
	if (!game || !game->render.mlx)
	{
        ft_cleanup(game);
        return;
    }
	game->render.img = mlx_new_image(game->render.mlx, game->render.screen_width, game->render.screen_height);
	if (!game->render.img)
	{
		ft_error("Error: Failed to create render image\n", 1);
		ft_cleanup(game);
        return;
	}
	game->render.instance = mlx_image_to_window(game->render.mlx, game->render.img, 0, 0);
	ft_set_cursor(game);
	i = -1;
	while (++i < 2)
		ft_draw_button(game->render.mlx, &game->render.buttons[i]);
	mlx_key_hook(game->render.mlx, ft_on_keypress, game);
	mlx_mouse_hook(game->render.mlx, ft_mouse_button, game);
	mlx_loop(game->render.mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		ft_error("Error: No map file provided\n", 1);
	check_arg_cub(argv[1]);
	if (!ft_setup(&game, argv[1]))
		ft_error("Error: Failed to setup game\n", 1);
	ft_successful("Game setup successful\n", 0);
	ft_launch_game(&game);
	return (ft_cleanup(&game), 0);
}
