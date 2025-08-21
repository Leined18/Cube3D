/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:42:52 by daniel            #+#    #+#             */
/*   Updated: 2025/08/21 16:23:24 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_vertical_line(t_game *g, int x, t_screenline d, t_tex_inf *tinf)
{
	draw_ceiling(g->render.img, x, d);
	draw_wall(g->render.img, x, &d, tinf);
	draw_floor(g->render.img, x, d);
}

void	calc_draw_line(t_game *g, t_ray *ray)
{
	int	s;
	int	e;

	ray->draw.lineheight = (int)(SCRHEIGHT / ray->perpwalldist);
	s = ft_clamp(SCRHEIGHT / 2 - ray->draw.lineheight / 2, 0, SCRHEIGHT - 1);
	e = ft_clamp(SCRHEIGHT / 2 + ray->draw.lineheight / 2, 0, SCRHEIGHT - 1);
	ray->draw.start = s;
	ray->draw.end = e;
	if (!TEXTURES)
		ray->draw.color_wall = set_color_line(g, ray->pos, ray->side);
	ray->draw.color_floor = &g->map.textures[F].color;
	ray->draw.color_ceiling = &g->map.textures[C].color;
}
