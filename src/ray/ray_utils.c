/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:50:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/25 11:00:44 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	set_ray_pos(t_ray *ray, int x, int y)
{
	ray->pos.x = x;
	ray->pos.y = y;
}

/* printf("cameraX = %.5f, Columna %d: rayDirX = %.5f, rayDirY = %.5f ", ray.cameraX, x, ray.dir.x, ray.dir.y);
		printf("||||| deltaX = %.5f , deltaY = %.5f ", ray.delta_dist.x, ray.delta_dist.y);
		printf("||||| stepX = %f , stepY = %f ", ray.step.x, ray.step.y);
		printf("||||| sideX = %.5f , sideY = %.5f", ray.side_dist.x, ray.side_dist.y);
		printf("----> choco en [%f,%f] (lado %d)", ray.map.x, ray.map.y, ray.side);
		printf("muro [ini,fin]=[%d,%d] (lado %d)\n", ray.draw.start, ray.draw.end, ray.side); */