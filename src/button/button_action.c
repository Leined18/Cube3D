/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 23:03:32 by daniel            #+#    #+#             */
/*   Updated: 2025/08/06 10:06:25 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/**
 * start funtion used as a button.
 */

void	start_game(void *p)
{
	t_game	*game;

	game = (t_game *)p;
	if (!game || !game->render.mlx)
	{
		ft_error("Error: Game or render not initialized.\n", 1);
		return ;
	}
	ft_remove_button(game->render.mlx, &game->render.buttons[0]);
	ft_free_button(game->render.mlx, &game->render.buttons[1]);
	game->render.buttons[1] = game->render.buttons[2];
	game->render.buttons[2] = (t_button){0};
	ft_successful("Game started successfully.", false);
	game->render.button_count = 2;
	game->render.buttons[0].y = 50;
	game->render.buttons[0].x = 50;
	game->running = true;
	mlx_loop_hook(game->render.mlx, ft_on_game_loop, game);
}

void	print_exit(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_cleanup(game);
	ft_successful("Game exited successfully.", true);
}

void	ft_show_minimap(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (!game || !game->render.mlx)
	{
		ft_error("Error: Game or render not initialized.\n", 1);
		return ;
	}
	if (game->map.minimap.enabled)
	{
		game->map.minimap.enabled = false;
		game->map.minimap.img->instances[0].enabled = false;
		ft_successful("Minimap disabled. \n", false);
	}
	else
	{
		game->map.minimap.enabled = true;
		game->map.minimap.img->instances[0].enabled = true;
		ft_successful("Minimap enabled.\n", false);
	}
}
