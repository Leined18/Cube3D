/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 23:03:32 by daniel            #+#    #+#             */
/*   Updated: 2025/07/21 11:58:08 by mvidal-h         ###   ########.fr       */
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
    game->render.buttons[1] = game->render.buttons[2];
    game->render.buttons[2] = (t_button){0}; // Clear the third button
    ft_successful("Game started successfully.", false);
    game->render.button_count = 2; // Update button count after starting the game
    game->render.buttons[0].y = 50; // Reset the second button position
    game->render.buttons[0].x = 50; // Reset the second button position
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

void ft_show_minimap(void *param)
{
    t_game *game;

    game = (t_game *)param;
    if (!game || !game->render.mlx)
    {
        ft_error("Error: Game or render not initialized.\n", 1);
        return;
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
