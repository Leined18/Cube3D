/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:12:50 by daniel            #+#    #+#             */
/*   Updated: 2025/08/06 10:58:33 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	ft_draw_minimap_image(t_minimap *minimap, mlx_t *mlx,
		t_vect2 minimap_pos)
{
	if (!minimap || !minimap->img || !mlx)
		return ;
	minimap->instance = mlx_image_to_window(mlx, minimap->img, minimap_pos.x,
			minimap_pos.y);
}

int	is_printable_tile(char tile, bool draw_walls)
{
	if (draw_walls)
		return (tile != 'D' && tile != '0' && tile != ' ');
	return (tile == 'D' || tile == '0' || tile == ' ');
}

void	ft_draw_minimap_grid(mlx_image_t *img, t_map *map, double scale,
		bool draw_walls)
{
	size_t	x;
	size_t	y;
	char	tile;

	if (!img || !map || !img->pixels)
		return ;
	x = 0;
	while (x < map->map_width)
	{
		y = 0;
		while (y < map->map_height)
		{
			tile = map->matrix[y][x];
			if (is_printable_tile(tile, draw_walls))
				ft_draw_by_tile(tile, img, (t_vect2){x * scale, y * scale},
					scale);
			y++;
		}
		x++;
	}
}

void	ft_draw_minimap(t_minimap *minimap, t_game *g)
{
	t_vect2	draw_pos;

	if (!minimap->img || !MINIMAP || !g || !g->render.mlx)
		return ;
	ft_bzero(&draw_pos, sizeof(t_vect2));
	draw_pos.x = g->render.screen_width - minimap->width - 10;
	draw_pos.y = 40;
	if (!minimap->img->instances)
		ft_draw_minimap_image(minimap, g->render.mlx, draw_pos);
	ft_draw_minimap_grid(minimap->img, &g->map, minimap->scale, false);
	ft_draw_player(minimap->img, g);
	ft_draw_minimap_grid(minimap->img, &g->map, minimap->scale, true);
	mlx_set_instance_depth(&minimap->img->instances[minimap->instance], 1);
	mlx_set_instance_depth(&g->render.img->instances[g->render.instance], 0);
}
