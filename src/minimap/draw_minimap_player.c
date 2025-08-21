/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:19:09 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/21 09:25:22 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static t_vect2	get_hit_point(t_game *g, t_ray *ray)
{
	t_vect2	hit;

	hit.x = g->player.pos.x + ray->dir.x * ray->perpwalldist;
	hit.y = g->player.pos.y + ray->dir.y * ray->perpwalldist;
	return (hit);
}

static void	ft_draw_player_dir(mlx_image_t *img, t_game *g)
{
	t_ray	ray;
	float	x;
	t_vect2	start;
	t_vect2	end_world;
	t_vect2	end_minimap;

	if (!img || !g)
		return ;
	start.x = g->player.pos.x * g->map.minimap.scale;
	start.y = g->player.pos.y * g->map.minimap.scale;
	x = 0;
	while (x < g->render.screen_width && x < (float)g->render.img->width)
	{
		if (ft_setup_ray(&ray, (int)x, g) < 0)
			return ;
		end_world = get_hit_point(g, &ray);
		end_minimap.x = end_world.x * g->map.minimap.scale;
		end_minimap.y = end_world.y * g->map.minimap.scale;
		if (end_minimap.x >= 0 && end_minimap.y >= 0
			&& end_minimap.x < img->width && end_minimap.y < img->height)
			ft_draw_line(img, start, end_minimap, MINIMAP_COLOR_LINE);
		x += MINIMAP_GRANULARITY_LINE;
	}
}

void	ft_draw_player(mlx_image_t *img, t_game *g)
{
	size_t	player_pixel;
	t_vect2	pos;

	if (!img || !g)
		return ;
	player_pixel = ceil(g->map.minimap.scale / 2);
	pos.x = g->player.pos.x * (g->map.minimap.scale) - player_pixel / 2;
	pos.y = g->player.pos.y * (g->map.minimap.scale) - player_pixel / 2;
	if (pos.x < 0 || pos.y < 0 || pos.x >= (int)img->width
		|| pos.y >= (int)img->height)
		return ;
	ft_draw_player_dir(img, g);
	ft_draw_tile(img, pos, player_pixel, MINIMAP_COLOR_PLAYER);
}
