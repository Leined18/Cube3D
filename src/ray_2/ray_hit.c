/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:29:44 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/19 10:34:25 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

bool	ray_check_collision(const t_ray_hit *hit, t_map *map)
{
	if (!hit || !map || !map->matrix)
		return (false);

	char cell = map->matrix[(int)hit->map_pos.y][(int)hit->map_pos.x];
	return (cell == '1'); // aquí puedes añadir más condiciones si lo deseas
}

bool	ray_hit_matches(const t_ray_hit *hit, t_map *map, char target)
{
	if (!hit || !map)
		return (false);

	char cell = map->matrix[(int)hit->map_pos.y][(int)hit->map_pos.x];
	return (cell == target);
}
