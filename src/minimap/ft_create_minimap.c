/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:29:23 by daniel            #+#    #+#             */
/*   Updated: 2025/07/08 10:15:07 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_minimap  ft_create_minimap(t_map *map)
{
    t_minimap minimap;

    if (!map)
        return ((t_minimap){0});
    ft_bzero(&minimap, sizeof(t_minimap));
    minimap.width = map->map_width;
    minimap.height = map->map_height;
    minimap.scale = MINIMAP_SCALE;
    minimap.enabled = MINIMAP;
    minimap.img = mlx_new_image(ft_mtget("mlx")->data, 
        map->map_width * MINIMAP_SCALE, map->map_height * MINIMAP_SCALE);
    if (!minimap.img)
        return ((t_minimap){0});
    return (minimap);
}