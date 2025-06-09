/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:17:12 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 11:10:21 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    ft_draw_tile(mlx_t *mlx, int x, int y, int color)
{
    mlx_image_t *minimap_img;
    if (!mlx || x < 0 || y < 0)
        return ;
    minimap_img = (mlx_image_t *)ft_mtget("minimap_img")->data;
    ft_set_pixel(minimap_img, x * TILE_SIZE, y * TILE_SIZE, color);
    mlx_image_to_window(mlx, minimap_img, x * TILE_SIZE, y * TILE_SIZE);
}

int ft_draw_player_on_minimap(mlx_t *mlx, t_player *player)
{
    int player_x;
    int player_y;
    
    if (!mlx || !player)
        return (0);
    player_x = (int)(player->pos.x / TILE_SIZE);
    player_y = (int)(player->pos.y / TILE_SIZE);
    if (player_x < 0 || player_y < 0)
        return (0);
    // Draw player as a red dot on the minimap
    ft_draw_tile(mlx, player_x, player_y, 0xFF0000); // Red color for player
    // Optionally, draw a circle around the player
    return (1);
}

int ft_draw_minimap_grid(mlx_t *mlx, t_map *map)
{
    int x;
    int y;

    if (!mlx || !map || !map->map_2d)
        return (0);
    y = -1;
    while(++y < map->height)
    {
        x = -1;
        while (++x < map->width[y])
        {
            if (map->map_2d[y][x] == '1') // Wall
                ft_draw_tile(mlx, x, y, 0xFFFFFF);
            else if (map->map_2d[y][x] == '0') // Floor
                ft_draw_tile(mlx, x, y, 0x000000);
            else // Empty space or other elements
                ft_draw_tile(mlx, x, y, 0x808080);
        }
    }
    return (1);
}

void ft_draw_minimap(mlx_t *mlx, t_map *map, t_player *player)
{
    if (!mlx || !map || !player)
        return;
    ft_draw_minimap_grid(mlx, map);
    ft_draw_player_on_minimap(mlx, player);
}
