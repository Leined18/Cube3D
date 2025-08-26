/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:45:42 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/06 10:57:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

int	ft_setup_ray(t_ray *ray, int x, t_game *g)
{
	if (!ray || !g || !g->render.img)
		return (-1);
	if (!ft_set_ray(ray, x, g))
		return (-1);
	if (!ft_raycast_dda(ray, g))
		return (-1);
	return (0);
}

int	cast_all_rays(t_game *g)
{
	int		x;
	t_ray	ray;

	if (!g || !g->render.img || !g->map.matrix)
		return (-1);
	x = 0;
	while (x < g->render.screen_width && x < (int)g->render.img->width)
	{
		if (ft_setup_ray(&ray, x, g) < 0)
			return (-1);
		calc_draw_line(g, &ray);
		if (TEXTURES)
			if (calc_tex_inf(g, &ray) < 0)
				return (-1);
		draw_vertical_line(g, x, &ray, &ray.tex_info);
		x++;
	}
	return (0);
}
