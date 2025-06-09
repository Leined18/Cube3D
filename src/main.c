/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 10:43:20 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int ft_print_map(t_game *game)
{
	int i;

	if (!game || !game->map || !game->map->map_2d)
		return (0);
	i = 0;
	while (i < game->map->height)
	{
		ft_printf("%s\n", game->map->map_2d[i]);
		i++;
	}
	return (1);
}


int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc < 2)
		ft_error("Error: No map file provided\n", 1);
	if (!ft_setup(&game, argv[1]))
		ft_error("Error: Failed to setup game\n", 1);
	ft_print_map(game);
	ft_successful("Game setup successful\n",0);
	if (!mlx_loop_hook(game->mlx, ft_handle_exit, game))
		ft_error("Error: Failed to set up loop\n", 1);
	if (!mlx_loop_hook(game->mlx, ft_render_frame, game))
		ft_error("Error: Failed to set up render loop\n", 1);
	mlx_loop(game->mlx);
	return (ft_cleanup(&game), 0);
}
