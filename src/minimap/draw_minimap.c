/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:12:50 by daniel            #+#    #+#             */
/*   Updated: 2025/07/09 11:18:26 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// funciona
void	ft_draw_tile(mlx_image_t *img, t_vect2 vtile, size_t size, uint32_t color)
{
	int x, y;

	if (!img || vtile.x < 0 || vtile.y < 0
		|| vtile.x + (int)size > (int)img->width || vtile.y + (int)size > (int)img->height)
		return;
	for (y = 0; y < (int)size; y++)
	{
		for (x = 0; x < (int)size; x++)
		{
			int px = vtile.x + x;
			int py = vtile.y + y;
			if (px >= 0 && py >= 0 && px < (int)img->width && py < (int)img->height)
				mlx_put_pixel(img, px, py, color);
		}
	}
}


// funciona
void	ft_draw_line(mlx_image_t *img, t_vect2 e1, t_vect2 e2, uint32_t color)
{
	int		dx;
	int		dy;
	int		steps;
	double	x_inc;
	double	y_inc;
	double	x;
	double	y;

	if (!img || e1.x < 0 || e1.y < 0 || e2.x < 0 || e2.y < 0
		|| e1.x >= (int)img->width || e1.y >= (int)img->height
		|| e2.x >= (int)img->width || e2.y >= (int)img->height)
		return ;
	dx = e2.x - e1.x;
	dy = e2.y - e1.y;
	steps = fmax(abs(dx), abs(dy));
	x_inc = (double)dx / steps;
	y_inc = (double)dy / steps;
	x = e1.x;
	y = e1.y;
	while (steps-- >= 0)
	{
		mlx_put_pixel(img, (int)x, (int)y, color);
		x += x_inc;
		y += y_inc;
	}
}

// no funciona
void	ft_draw_player_dir(mlx_image_t *img, t_game *g)
{
	t_vect2	pos = g->player.pos;
	t_vect2	dir = g->player.dir;

	t_vect2	start;
	t_vect2	end;


	if (!img || !g)
		return;
	start.x = pos.x * MINIMAP_SCALE * TILE_SIZE - 0.5; // Ajuste para centrar la dirección del jugador
	start.y = pos.y * MINIMAP_SCALE * TILE_SIZE - 0.5; // Ajuste para centrar la dirección del jugador
	end.x = dir.x * 10;
	end.y = dir.y * 10;
	ft_draw_line(img, start, end, 0xFFFF00);
}

// funciona a medias
void	ft_draw_player(mlx_image_t *img, t_game *g)
{
	size_t player_pixel;
	t_vect2 pos;

	if (!img || !g)
		return;
	player_pixel = TILE_SIZE * g->map.minimap.scale; // Tamaño del jugador en el minimapa
	pos.x = g->player.pos.x * g->map.minimap.scale * TILE_SIZE; // Escalar la posición del jugador
	pos.y = g->player.pos.y * g->map.minimap.scale * TILE_SIZE; // Escalar la posición del jugador
	if (pos.x < 0 || pos.y < 0 || pos.x >= (int)img->width || pos.y >= (int)img->height)
		return;
	ft_draw_tile(img, pos, player_pixel, 0xFFF0FF); // Dibuja el jugador en rojo
	ft_draw_player_dir(img, g); // Dibuja la dirección del jugador
}

// funciona
void ft_draw_minimap_image(t_minimap *minimap, mlx_t *mlx, t_vect2 minimap_pos)
{
	if (!minimap || !minimap->img || !mlx)
		return;
	minimap->instance = mlx_image_to_window(mlx, minimap->img, minimap_pos.x, minimap_pos.y);
}

// funciona
void	fill_image_color(mlx_image_t *img, uint32_t color)
{
	size_t	i;
	uint32_t	*pixel;

	if (!img || !img->pixels)
		return;

	pixel = (uint32_t *)img->pixels;
	i = 0;
	while (i < img->width * img->height)
	{
		pixel[i] = color;
		i++;
	}
}


// no funciona
void ft_draw_minimap_grid(mlx_image_t *img, t_map *map, double scale)
{
	size_t x;
	size_t y;

	if (!img || !map || !img->pixels)
		return;
	x = 0;
	while (x < map->map_width)
	{
		y = 0;
		(void)scale; // scale is not used in this function, but could be used for scaling the grid
		while (y < map->map_height)
		{
			if (map->matrix[y][x] == '0') // Assuming '1' represents a wall
			{
				printf("Drawing wall at (%zu, %zu)\n", x, y);
				ft_draw_tile(img, (t_vect2){x * TILE_SIZE * scale, y * TILE_SIZE * scale}, 
					TILE_SIZE, 0xFFF00FFF); // Draw wall in red
			}
			else if (map->matrix[y][x] == ' ') // Assuming '0' represents empty space
			{
				printf("Drawing empty space at (%zu, %zu)\n", x, y);
				ft_draw_tile(img, (t_vect2){x * TILE_SIZE * scale, y * TILE_SIZE * scale}, 
					TILE_SIZE, 0x000000); // Draw empty space in black
			}
			else
			{ 
				printf("Drawing other tile at (%zu, %zu)\n", x, y);
				ft_draw_tile(img, (t_vect2){x * TILE_SIZE * scale, y * TILE_SIZE * scale}, 
					TILE_SIZE, 0xF00FFF); // Draw other tiles in green
			}
			y++;
		}
		x++;
	}
}

// a medias
void ft_draw_minimap(t_minimap *minimap, t_game *g)
{
	t_vect2 draw_pos;

	if (!minimap->enabled || !minimap->img)
	return;
	ft_bzero(&draw_pos, sizeof(t_vect2));
	draw_pos.x = g->render.screen_width - minimap->width - 10; // 10 pixels from the right edge
	draw_pos.y = 40; //
	if (!minimap->img->instances)
		ft_draw_minimap_image(minimap, g->render.mlx, draw_pos);
	//fill_image_color(minimap->img, 0xFFF00FFF); // blanco con alpha
	ft_draw_minimap_grid(minimap->img, &g->map, minimap->scale); // Draw the grid
	ft_draw_player(minimap->img, g);
	mlx_set_instance_depth(&minimap->img->instances[minimap->instance], 1);
	mlx_set_instance_depth(&g->render.img->instances[g->render.instance], 0);
	if (!minimap->text)
		minimap->text = mlx_put_string(g->render.mlx, "Minimap",
			SCREEN_WIDTH - 100, 20);
}
