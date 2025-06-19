/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_step_and_sidedist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:35:43 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/19 09:57:24 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void ray_step_and_sidedist(t_ray_hit *ray, t_vect2 pos)
{
    if (ray->ray_dir.x < 0)
    {
        ray->step.x = -1;
        ray->side_dist.x = (pos.x - ray->map_pos.x) * ray->delta_dist.x;
    }
    else
    {
        ray->step.x = 1;
        ray->side_dist.x = (ray->map_pos.x + 1.0 - pos.x) * ray->delta_dist.x;
    }
    if (ray->ray_dir.y < 0)
    {
        ray->step.y = -1;
        ray->side_dist.y = (pos.y - ray->map_pos.y) * ray->delta_dist.y;
    }
    else
    {
        ray->step.y = 1;
        ray->side_dist.y = (ray->map_pos.y + 1.0 - pos.y) * ray->delta_dist.y;
    }
}