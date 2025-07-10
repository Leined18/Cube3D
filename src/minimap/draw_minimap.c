/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:12:50 by daniel            #+#    #+#             */
/*   Updated: 2025/07/10 10:52:51 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// funciona
void	ft_draw_player_dir(mlx_image_t *img, t_game *g)
{
	t_ray ray;
	float x;
	t_vect2 pos = g->player.pos;
	t_vect2 start;
	t_vect2 end;
	double scale = g->map.minimap.scale;

	if (!img || !g)
		return;
	start.x = pos.x * TILE_SIZE * scale;
	start.y = pos.y * TILE_SIZE * scale;
	x = 0;
	while (x < g->render.screen_width && x < (float)g->render.img->width)
	{
		if (ft_setup_ray(&ray, (int)x, g) < 0)
			return;
		end.x = ray.pos.x * TILE_SIZE * scale;
		end.y = ray.pos.y * TILE_SIZE * scale;
		if (end.x >= 0 && end.y >= 0 && end.x < img->width && end.y < img->height)
			ft_draw_line(img, start, end, 0xFFFFFFFF); // dibuja el rayo desde el jugador
		x += 0.5f; // más fino = más líneas = menos separación
	}
}

// funciona a medias
void	ft_draw_player(mlx_image_t *img, t_game *g)
{
	size_t player_pixel;
	t_vect2 pos;

	if (!img || !g)
		return;
	player_pixel = ceil((TILE_SIZE / 2) * g->map.minimap.scale); // Tamaño del jugador en píxeles
	pos.x = g->player.pos.x * (g->map.minimap.scale * TILE_SIZE) - player_pixel / 2; // Escalar la posición del jugador
	pos.y = g->player.pos.y * (g->map.minimap.scale * TILE_SIZE) - player_pixel / 2; // Escalar la posición del jugador
	if (pos.x < 0 || pos.y < 0 || pos.x >= (int)img->width || pos.y >= (int)img->height)
		return;
	ft_draw_tile(img, pos, player_pixel, 0xFF0000FF); // Dibuja el jugador en rojo
	ft_draw_player_dir(img, g); // Dibuja la dirección del jugador
}

// funciona
void ft_draw_minimap_image(t_minimap *minimap, mlx_t *mlx, t_vect2 minimap_pos)
{
	if (!minimap || !minimap->img || !mlx)
		return;
	minimap->instance = mlx_image_to_window(mlx, minimap->img, minimap_pos.x, minimap_pos.y);
}

// no funciona
void ft_draw_minimap_grid(mlx_image_t *img, t_map *map, double scale)
{
	size_t x;
	size_t y;
	char current_tile;

	if (!img || !map || !img->pixels)
		return;
	x = 0;
	while (x < map->map_width)
	{
		y = 0;
		(void)scale; // scale is not used in this function, but could be used for scaling the grid
		while (y < map->map_height)
		{
			current_tile = map->matrix[y][x];
			ft_draw_by_tile(current_tile, img,
				(t_vect2){x * TILE_SIZE * scale, y * TILE_SIZE * scale}, scale);
			y++;
		}
		x++;
	}
}

// a medias
void ft_draw_minimap(t_minimap *minimap, t_game *g)
{
	t_vect2 draw_pos;

	if (!minimap->img || !MINIMAP || !g || !g->render.mlx)
		return;
	ft_bzero(&draw_pos, sizeof(t_vect2));
	draw_pos.x = g->render.screen_width - minimap->width - 10; // 10 pixels from the right edge
	draw_pos.y = 40; //
	if (!minimap->img->instances)
		ft_draw_minimap_image(minimap, g->render.mlx, draw_pos);
	ft_draw_minimap_grid(minimap->img, &g->map, minimap->scale);
	ft_draw_player(minimap->img, g);
	mlx_set_instance_depth(&minimap->img->instances[minimap->instance], 1);
	mlx_set_instance_depth(&g->render.img->instances[g->render.instance], 0);
	
}
