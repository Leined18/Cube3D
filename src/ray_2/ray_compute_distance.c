/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_compute_distance.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:37:39 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/19 09:37:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void ray_compute_distance(t_ray_hit *ray, t_vect2 pos)
{
    if (ray->side == 0)
        ray->perp_wall_dist = (ray->map_coord.x - pos.x + (1 - ray->step.x) / 2) / ray->ray_dir.x;
    else
        ray->perp_wall_dist = (ray->map_coord.y - pos.y + (1 - ray->step.y) / 2) / ray->ray_dir.y;
}