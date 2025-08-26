/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:42:52 by daniel            #+#    #+#             */
/*   Updated: 2025/08/21 09:25:08 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	draw_vertical_line(t_game *g, int x, t_ray *ray, t_tex_inf *tinf)
{
	draw_ceiling(g->render.img, x, ray->draw);
	draw_wall(g->render.img, x, ray, tinf);
	draw_floor(g->render.img, x, ray->draw);
}

void	calc_draw_line(t_game *g, t_ray *ray)
{
	ray->draw.lineheight = (int)(SCREEN_HEIGHT / ray->perpwalldist);
	ray->draw.start = ft_clamp(SCREEN_HEIGHT / 2 - ray->draw.lineheight / 2, 0,
			SCREEN_HEIGHT - 1);
	ray->draw.end = ft_clamp(SCREEN_HEIGHT / 2 + ray->draw.lineheight / 2, 0,
			SCREEN_HEIGHT - 1);
	if (!TEXTURES)
		ray->draw.color_wall = set_color_line(g, ray->pos, ray->side);
	ray->draw.color_floor = &g->map.textures['F'].color;
	ray->draw.color_ceiling = &g->map.textures['C'].color;
}
