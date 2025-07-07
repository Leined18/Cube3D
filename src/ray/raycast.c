/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:45:42 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/07 15:51:07 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	cast_all_rays(t_game *g)
{
	int		x;
	t_ray	ray;
	if (!g || !g->render.img || !g->map.matrix)
		return (-1);
	x = 0;
	while (x < g->render.screen_width && x < (int)g->render.img->width)
	{
		if (!ft_set_ray(&ray, x, g))
			return (-1);
		if (!ft_raycast_dda(&ray, g))
			printf("DDA failed for column %d\n", x);
		calc_draw_line(g, &ray);
		if (TEXTURES)
			if (calc_tex_inf(g, &ray) < 0)
				return (-1);
		draw_vertical_line(g, x, &ray, &ray.tex_info);
		x++;
	}
	return (0);
}