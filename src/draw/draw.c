/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:42:52 by daniel            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/21 16:23:24 by mvidal-h         ###   ########.fr       */
=======
/*   Updated: 2025/08/21 09:25:08 by mvidal-h         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

<<<<<<< HEAD
void	draw_vertical_line(t_game *g, int x, t_screenline d, t_tex_inf *tinf)
=======
void	draw_vertical_line(t_game *g, int x, t_ray *ray, t_tex_inf *tinf)
>>>>>>> main
{
	draw_ceiling(g->render.img, x, ray->draw);
	draw_wall(g->render.img, x, ray, tinf);
	draw_floor(g->render.img, x, ray->draw);
}

void	calc_draw_line(t_game *g, t_ray *ray)
{
<<<<<<< HEAD
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
=======
	ray->draw.lineheight = (int)(SCREEN_HEIGHT / ray->perpwalldist);
	ray->draw.start = ft_clamp(SCREEN_HEIGHT / 2 - ray->draw.lineheight / 2, 0,
			SCREEN_HEIGHT - 1);
	ray->draw.end = ft_clamp(SCREEN_HEIGHT / 2 + ray->draw.lineheight / 2, 0,
			SCREEN_HEIGHT - 1);
	if (!TEXTURES)
		ray->draw.color_wall = set_color_line(g, ray->pos, ray->side);
	ray->draw.color_floor = &g->map.textures['F'].color;
	ray->draw.color_ceiling = &g->map.textures['C'].color;
>>>>>>> main
}
