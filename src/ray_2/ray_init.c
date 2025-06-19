/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:29:19 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/19 10:25:14 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray_hit ray_init(t_ray_input input)
{
    t_ray_hit ray;
    double cameraX = 2.0 * input.screen_x / (double)input.screen_width - 1.0;
    ray.ray_dir.x = input.dir.x + input.plane.x * cameraX;
    ray.ray_dir.y = input.dir.y + input.plane.y * cameraX;
    ray.map_pos.x = (int)input.origin.x;
    ray.map_pos.y = (int)input.origin.y;
    ray.delta_dist.x = fabs(1 / ray.ray_dir.x);
    ray.delta_dist.y = fabs(1 / ray.ray_dir.y);
    ray.hit = false;
    return ray;
}