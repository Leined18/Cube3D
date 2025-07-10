/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:06:54 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/10 10:50:07 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	setup_dda(t_ray *ray, t_game *game)
{
	set_ray_pos(ray, game->player.pos.x, game->player.pos.y);
	calc_delta_dist(ray);
	calc_step_dir(ray);
	calc_side_dist(ray, &game->player.pos);
	return (1); // Retorna 1 si la configuración fue exitosa.
}

int	reach_wall(t_ray *ray, t_game *g)
{
	ray->hit = 0;
	while (!ray->hit)
	{
		if (!g->map.matrix[(int)ray->pos.y][(int)ray->pos.x])
			return (0); // Si la posición del rayo está fuera del mapa, retornar 0.
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->pos.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->pos.y += ray->step.y;
			ray->side = 1;
		}
		if (is_wall_elem(g, g->map.matrix[(int)ray->pos.y][(int)ray->pos.x]))
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpWallDist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perpWallDist = ray->side_dist.y - ray->delta_dist.y;
	return (ray->hit);
}

int	ft_raycast_dda(t_ray *ray, t_game *g)
{
	
	if (!ray || !g || !g->map.matrix)
		return (0); // Validación de entrada.
	if (ray->cameraX < -1 || ray->cameraX > 1)
		return (0); // Si cameraX está fuera de rango, retornar 0.
	if (!setup_dda(ray, g))
		return (0); // Configuración del DDA fallida, retornar 0.
	if (!reach_wall(ray, g))
		return (0); // Si no se alcanza un muro, retornar 0.
	return (ray->hit); // Retorna 1 si se ha alcanzado un muro, 0 si no.
}
