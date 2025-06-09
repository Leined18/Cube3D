/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:43:30 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 11:07:20 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


void ft_render_minimap(t_map *map, t_player *player)
{
    mlx_t *mlx;

    if (!map || !player)
        return;
    mlx = (mlx_t *)ft_mtget("mlx")->data;
    if (!mlx)
        return;
    if (!map->minimap_img)
        ft_create_minimap_viewport(mlx, map, player);
    else
        ft_update_minimap(mlx, map, player);
}

void ft_render_frame(void *param)
{
    t_game *game;
    
    game = (t_game *)param;
    if (!game || !game->mlx || !game->map || !game->player)
        return;
    usleep(1000 / game->render->fps); // Simulate frame rate (60 FPS)
    ft_render_minimap(game->map, game->player);
}