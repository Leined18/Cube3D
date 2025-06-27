/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 23:03:32 by daniel            #+#    #+#             */
/*   Updated: 2025/06/27 23:26:52 by daniel           ###   ########.fr       */
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
    mlx_loop_hook(game->render.mlx, ft_on_game_loop, game);
    remove_button(game->render.mlx, &game->render.buttons[1]);
}

void print_exit(void *param)
{
    t_game *game;

    game = (t_game *)param;
    ft_cleanup(game);
    ft_successful("Game exited successfully.", true);
}
