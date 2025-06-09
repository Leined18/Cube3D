/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:22:56 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 11:13:21 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

mlx_image_t *ft_create_minimap_image(mlx_t *mlx, t_map *map)
{
    mlx_image_t *minimap_img;
    
    if (!mlx || !map)
        return (0);
    minimap_img = mlx_new_image(mlx, *map->width * TILE_SIZE, map->height * TILE_SIZE);
    if (!minimap_img)
        return (NULL);
    map->minimap_img = minimap_img;
    ft_mtnew("minimap_img")->data = minimap_img;
    return (minimap_img);
}

int ft_create_minimap_viewport(mlx_t *mlx, t_map *map, t_player *player)
{
    mlx_image_t *minimap_img;

    if (!mlx || !map || !player)
        return (0);
    minimap_img = ft_create_minimap_image(mlx, map);
    if (!minimap_img)
        return (0);
    map->minimap_bool = true;
    map->minimap_img = minimap_img;
    ft_draw_minimap_grid(mlx, map);
    ft_draw_player_on_minimap(mlx, player);
    mlx_image_to_window(mlx, minimap_img, 0, 0);
    return (1);
}

char ft_get_map_tile(int x, int y)
{
    t_map *map;
    char tile;

    map = (t_map *)ft_mtget("map")->data;
    if (!map || !map->map_2d || y < 0 || y >= map->height || x < 0 || x >= map->width[y])
        return (' ');
    tile = map->map_2d[y][x];
    return (tile);
}

void ft_set_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
    if (!img || x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
        return;
    img->pixels[y * img->width + x] = color;
}

void ft_set_minimap_scale(mlx_image_t *img, float scale)
{
    int width;
    int height;
    if (!img || scale <= 0)
        return;
    width = (int)(img->width * scale);
    height = (int)(img->height * scale);
    if (width <= 0 || height <= 0)
        return;
    mlx_resize_image(img, width, height);
}

void ft_toggle_minimap(void)
{
    mlx_t *mlx;
    t_map *map;
    t_player *player;

    mlx = (mlx_t *)ft_mtget("mlx")->data;
    map = (t_map *)ft_mtget("map")->data;
    player = (t_player *)ft_mtget("player")->data;
    if (!mlx || !map || !player)
        return;
    map->minimap_bool = !map->minimap_bool;
    if (map->minimap_bool)
    {
        ft_create_minimap_viewport(mlx, map, player);
        mlx_set_window_title(mlx, "Minimap: ON");
    }
    else
    {
        mlx_delete_image(mlx, map->minimap_img);
        mlx_set_window_title(mlx, "Minimap: OFF");
    }
}
