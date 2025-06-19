/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_perform_dda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:36:22 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/19 09:37:20 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void ray_perform_dda(t_ray_hit *ray, t_map *map)
{
    while (!ray->hit)
    {
        if (ray->side_dist.x < ray->side_dist.y)
        {
            ray->side_dist.x += ray->delta_dist.x;
            ray->map_coord.x += ray->step.x;
            ray->side = 0;
        }
        else
        {
            ray->side_dist.y += ray->delta_dist.y;
            ray->map_coord.y += ray->step.y;
            ray->side = 1;
        }
        if (map->matrix[(int)ray->map_coord.y][(int)ray->map_coord.x] == '1')
            ray->hit = true;
    }
}