/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 23:03:32 by daniel            #+#    #+#             */
/*   Updated: 2025/07/09 09:40:44 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void start_game(void *p)
{
    t_game *game;

    game = (t_game *)p;
    if (!game || !game->render.mlx)
    {
        ft_error("Error: Game or render not initialized.\n", 1);
        return;
    }
    ft_remove_button(game->render.mlx, &game->render.buttons[0]);
    ft_free_button(game->render.mlx, &game->render.buttons[1]); // Free the start button
    ft_successful("Game started successfully.", false);
    game->render.button_count = 1; // Update button count after starting the game
    game->render.buttons[0].y = 0; // Reset the second button position
    game->render.buttons[0].x = 0; // Reset the second button position
    game->running = true; // Set the game running state
    mlx_loop_hook(game->render.mlx, ft_on_game_loop, game); 
}

void print_exit(void *param)
{
    t_game *game;

    game = (t_game *)param;
    ft_cleanup(game);
    ft_successful("Game exited successfully.", true);
}
