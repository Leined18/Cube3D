/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:45:42 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/18 13:42:26 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	cast_all_rays(t_game *g)
{
	int		x;
	t_ray	ray;

	ft_memset(&ray, 0, sizeof(t_ray));
	x = 0;
	ray.draw.texture_floor = g->map.textures[F].texture;
	ray.draw.texture_ceiling = g->map.textures[C].texture;
	while (x < g->render.screen_width && x < (int)g->render.img->width)
	{
		ray.cameraX = calc_cameraX(x);
		ray.dir = calc_ray_dir(g->player.dir, g->player.plane, ray.cameraX);
		setup_dda(&ray, g);
		raycast_dda(&ray, g);
		calc_draw_line(g, &ray);
		draw_vertical_line(g->render.img, x, ray.draw, ray.side);
		/* printf("cameraX = %.5f, Columna %d: rayDirX = %.5f, rayDirY = %.5f ", ray.cameraX, x, ray.dir.x, ray.dir.y);
		printf("||||| deltaX = %.5f , deltaY = %.5f ", ray.delta_dist.x, ray.delta_dist.y);
		printf("||||| stepX = %f , stepY = %f ", ray.step.x, ray.step.y);
		printf("||||| sideX = %.5f , sideY = %.5f", ray.side_dist.x, ray.side_dist.y);
		printf("----> choco en [%f,%f] (lado %d)", ray.map.x, ray.map.y, ray.side);
		printf("muro [ini,fin]=[%d,%d] (lado %d)\n", ray.draw.start, ray.draw.end, ray.side); */
		x++;
	}
}