/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:12:50 by daniel            #+#    #+#             */
/*   Updated: 2025/07/08 10:39:08 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw_tile(mlx_image_t *img, size_t *x, size_t *y, size_t size, uint32_t color)
{
	if (!img || !x || !y || *x + size > (size_t)img->width || *y + size > (size_t)img->height)
		return;

	while (*y < *y + size)
	{
		size_t temp_x = *x;
		while (temp_x < *x + size)
		{
			mlx_put_pixel(img, temp_x, *y, color);
			temp_x++;
		}
		(*y)++;
	}
	*x += size; // Avanzar al siguiente bloque
	*y -= size; // Volver a la posición original en y

	// (Opcional) registrar en algún lado que se ha dibujado en (*x, *y) con size y color
}


void	ft_draw_player(mlx_image_t *img, t_game *g)
{
	int player_size = 12; // píxeles
	int px = g->player.pos.x * MINIMAP_SCALE;
	int py = g->player.pos.y * MINIMAP_SCALE;

	if (!img || px < 0 || py < 0 || px + player_size > (int)img->width || py + player_size > (int)img->height)
		return;
	
	for (int dy = -player_size / 2; dy < player_size / 2; dy++)
	{
		for (int dx = -player_size / 2; dx < player_size / 2; dx++)
		{
			mlx_put_pixel(img, px + dx, py + dy, 0x0000FF); // Azul para el jugador
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

	if (!img || x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 ||
		x1 >= (int)img->width || y1 >= (int)img->height ||
		x2 >= (int)img->width || y2 >= (int)img->height)
		return;

    for (int i = 0; i <= steps; i++)
    {
		mlx_put_pixel(img, (int)x, (int)y, color);
        x += x_inc;
        y += y_inc;
    }
}

void	ft_draw_player_dir(mlx_image_t *img, t_game *g)
{
	t_vect2	pos = g->player.pos;
	t_vect2	dir = g->player.dir;

	if (!img || !g)
		return;

	int px = pos.x * MINIMAP_SCALE;
	int py = pos.y * MINIMAP_SCALE;

	int dx = dir.x * 10;
	int dy = dir.y * 10;

	ft_draw_line(img, px, py, px + dx, py + dy, 0xFFFF00); // Yellow direction
}

void ft_draw_minimap_image(t_minimap *minimap, mlx_t *mlx)
{
	if (!minimap || !minimap->img || !mlx)
		return;
	minimap->instance = mlx_image_to_window(mlx, minimap->img, 50, 50);
}

void ft_draw_minimap(t_minimap *minimap, t_game *g)
{
	size_t x, y;
	size_t draw_x, draw_y;
	uint32_t color;

	if (!minimap->enabled || !minimap->img)
		return;
	for (y = 0; y < g->map.map_height; y++)
	{
		for (x = 0; x < g->map.map_width; x++)
		{
			draw_x = x * MINIMAP_SCALE;
			draw_y = y * MINIMAP_SCALE;
			color = (ft_get_map_tile(x, y) == '1') ? 0xFF0000 : 0x00FF00;
			ft_draw_tile(minimap->img, &draw_x, &draw_y, MINIMAP_SCALE, color);
		}
	}
	ft_draw_line(minimap->img, 0, 0, minimap->width, 0, 0xFFFFFF); // Horizontal line
    ft_draw_player_dir(minimap->img, g);
	ft_draw_player(minimap->img, g);
    ft_draw_minimap_image(minimap, g->render.mlx);
	mlx_set_instance_depth(&minimap->img->instances[minimap->instance], 0);
	mlx_set_instance_depth(&g->render.img->instances[g->render.instance], 1);
	minimap->text = mlx_put_string(g->render.mlx, "Minimap",
		screenWidth - 100, 20);

}
