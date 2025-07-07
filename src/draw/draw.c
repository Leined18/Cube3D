/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:42:52 by daniel            #+#    #+#             */
/*   Updated: 2025/07/02 12:45:24 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// void	draw_vertical_line(mlx_image_t *img, int x, t_screenline draw, bool dark_mode)
// {
// 	draw_ceiling(img, x, draw);
// 	draw_wall(img, x, draw, dark_mode);
// 	draw_floor(img, x, draw);
// }

void	draw_vertical_line(t_game *g, int x, t_ray *ray, t_tex_inf *tinf)
{
	draw_ceiling(g->render.img, x, ray->draw);
	draw_wall(g->render.img, x, ray, tinf);
	draw_floor(g->render.img, x, ray->draw);
}

void	calc_draw_line(t_game *g, t_ray *ray)
{
	ray->draw.lineheight = (int)(screenHeight / ray->perpWallDist);

	ray->draw.start = ft_clamp(screenHeight / 2 - ray->draw.lineheight / 2, 0, screenHeight - 1);
	ray->draw.end = ft_clamp(screenHeight / 2 + ray->draw.lineheight / 2, 0, screenHeight - 1);
	if (!TEXTURES)
		ray->draw.color_wall = set_color_line(g, ray->pos, ray->side);
	ray->draw.color_floor = &g->map.textures['F'].color;
	ray->draw.color_ceiling = &g->map.textures['C'].color;

	
	// ray->draw.texture = g->map.textures[ray->side].texture;
	// ray->draw.texture_floor = g->map.textures[F].texture;	
	// ray->draw.texture_ceiling = g->map.textures[C].texture;
	
	// if (ray->side == 0)
	// 	ray->draw.wall.x = g->player.pos.y + ray->perpWallDist * ray->dir.y;
	// else
	// 	ray->draw.wall.x = g->player.pos.x + ray->perpWallDist * ray->dir.x;
	// ray->draw.wall.x -= floor(ray->draw.wall.x);
	// ray->draw.tex.x = ray->draw.wall.x * ray->draw.texture->width;
	// if ((ray->side == 0 && ray->dir.x > 0) || (ray->side == 1 && ray->dir.y < 0))
	// 	ray->draw.tex.x = ray->draw.texture->width - ray->draw.tex.x - 1;
	// ray->draw.wall.y = g->player.pos.x + ray->perpWallDist * ray->dir.x;
	// ray->draw.wall.y -= floor(ray->draw.wall.y);
	// ray->draw.tex.y = ray->draw.wall.y * ray->draw.texture->height;
	// if ((ray->side == 0 && ray->dir.y < 0) || (ray->side == 1 && ray->dir.x > 0))
	// 	ray->draw.tex.y = ray->draw.texture->height - ray->draw.tex.y - 1;
}
