/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculate_draw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:40:06 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/19 09:40:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void ray_calculate_draw(t_ray_hit *ray, int screen_height)
{
    int line_height;

    line_height = (int)(screen_height / ray->perp_wall_dist);
    ray->draw.start = -line_height / 2 + screen_height / 2;
    if (ray->draw.start < 0)
        ray->draw.start = 0;
    ray->draw.end = line_height / 2 + screen_height / 2;
    if (ray->draw.end >= screen_height)
        ray->draw.end = screen_height - 1;

    // Initialize the draw structure
    ray->draw.color_wall = 0xFFFFFF; // Default wall color
    ray->draw.color_floor = 0x000000; // Default floor color
    ray->draw.color_ceiling = 0x000000; // Default ceiling color
}