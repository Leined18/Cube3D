/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:26:37 by danpalac         ###   ########.fr       */
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

int	ft_launch_game(t_game *game)
{
	if (!game || !game->render.mlx)
		return (ft_cleanup(game), 1);
	game->render.img = mlx_new_image(game->render.mlx,
			game->render.screen_width, game->render.screen_height);
	if (!game->render.img)
		return (ft_cleanup(game), 1);
	game->render.instance = mlx_image_to_window(game->render.mlx,
			game->render.img, 0, 0);
	ft_set_cursor(game);
	ft_draw_buttons(game);
	mlx_key_hook(game->render.mlx, ft_on_keypress, game);
	mlx_mouse_hook(game->render.mlx, ft_mouse_button, game);
	mlx_loop(game->render.mlx);
	return (ft_cleanup(game), 0);
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
