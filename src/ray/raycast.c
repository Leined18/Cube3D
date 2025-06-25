/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:45:42 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/25 12:45:44 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	cast_all_rays(t_game *g)
{
	int		x;
	t_ray	ray;
	if (!g || !g->render.img || !g->map.matrix)
		return;
	x = 0;
	while (x < g->render.screen_width && x < (int)g->render.img->width)
	{
		if (!ft_set_ray(&ray, x, g))
			return;
		if (!ft_raycast_dda(&ray, g))
			printf("DDA failed for column %d\n", x);
		calc_draw_line(g, &ray);
		if (TEXTURES)
			calc_tex_inf(g, &ray);
		draw_vertical_line(g, x, ray.draw, &ray.tex_info);
		// draw_vertical_line(g->render.img, x, ray.draw, ray.side);
		x++;
	}
}