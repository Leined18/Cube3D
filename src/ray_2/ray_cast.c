/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:29:36 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/19 09:34:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray_hit ray_cast(t_ray_input input, t_map *map)
{
    t_ray_hit ray;
    ray = ray_init(input);
    ray_step_and_sidedist(&ray, input.origin);
    ray_perform_dda(&ray, map);
    ray_compute_distance(&ray, input.origin);
    ray_calculate_draw(&ray, map->map_height);
    return (ray);
}
