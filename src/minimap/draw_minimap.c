/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:12:50 by daniel            #+#    #+#             */
/*   Updated: 2025/07/07 11:59:20 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw_tile(mlx_image_t *img, int x, int y, int size, uint32_t color)
{
	for (int dy = 0; dy < size; dy++)
	{
		for (int dx = 0; dx < size; dx++)
		{
			ft_set_pixel(img, x + dx, y + dy, color);
		}
	}
}

void	ft_draw_player(mlx_image_t *img, t_game *g)
{
	int player_size = 4; // píxeles
	int px = g->player.pos.x * TILE_SIZE * MINIMAP_SCALE;
	int py = g->player.pos.y * TILE_SIZE * MINIMAP_SCALE;

	for (int dy = -player_size / 2; dy < player_size / 2; dy++)
	{
		for (int dx = -player_size / 2; dx < player_size / 2; dx++)
		{
			ft_set_pixel(img, px + dx, py + dy, 0x0000FF); // Blue for player
		}
	}
}

void ft_draw_line(mlx_image_t *img, int x1, int y1, int x2, int y2, uint32_t color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = fmax(abs(dx), abs(dy));
    double x_inc = (double)dx / steps;
    double y_inc = (double)dy / steps;
    double x = x1;
    double y = y1;

    for (int i = 0; i <= steps; i++)
    {
        ft_set_pixel(img, (int)x, (int)y, color);
        x += x_inc;
        y += y_inc;
    }
}

void	ft_draw_player_dir(mlx_image_t *img, t_game *g)
{
	t_vect2	pos = g->player.pos;
	t_vect2	dir = g->player.dir;

	int px = pos.x * TILE_SIZE * MINIMAP_SCALE;
	int py = pos.y * TILE_SIZE * MINIMAP_SCALE;

	int dx = dir.x * 10;
	int dy = dir.y * 10;

	ft_draw_line(img, px, py, px + dx, py + dy, 0xFFFF00); // Yellow direction
}

void ft_draw_minimap(t_minimap *minimap, t_game *g)
{
	size_t x, y;
	size_t map_x, map_y;
	uint32_t color;

	if (!minimap->enabled || !minimap->img)
		return;

	for (y = 0; y < g->map.map_height; y++)
	{
		for (x = 0; x < g->map.map_width; x++)
		{
			map_x = x * TILE_SIZE * MINIMAP_SCALE;
			map_y = y * TILE_SIZE * MINIMAP_SCALE;
			color = (ft_get_map_tile(x, y) == '1') ? 0xFF0000 : 0x00FF00;
			ft_draw_tile(minimap->img, map_x, map_y, TILE_SIZE * MINIMAP_SCALE, color);
		}
	}
	ft_draw_player(minimap->img, g);
    ft_draw_player_dir(minimap->img, g);
    if (!minimap->img->enabled)
        mlx_image_to_window(g->render.mlx, minimap->img, 0, 0);
}