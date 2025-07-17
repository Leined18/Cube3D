/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:22:56 by danpalac          #+#    #+#             */
/*   Updated: 2025/07/07 11:55:02 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

mlx_image_t *ft_create_minimap_image(mlx_t *mlx, int width, int height)
{
    mlx_image_t *minimap_img;
    
    if (!mlx)
        return (0);
    minimap_img = mlx_new_image(mlx, width, height);
    if (!minimap_img)
        return (NULL);
    return (minimap_img);
}

char ft_get_map_tile(int x, int y)
{
    t_map map;
    char tile;

    map = *(t_map *)ft_mtget("map")->data;
    if (!map.matrix || y < 0 || y >= (int)map.map_height || x < 0 || x >= (int)map.map_width)
        return (' ');
    tile = map.matrix[y][x];
    return (tile);
}

void ft_set_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
    if (!img || x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
        return;
    img->pixels[y * img->width + x] = color;
}

void ft_set_scale(mlx_image_t *img, float scale)
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