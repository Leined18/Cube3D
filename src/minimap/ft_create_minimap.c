/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:29:23 by daniel            #+#    #+#             */
/*   Updated: 2025/07/07 11:54:40 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_minimap  ft_create_minimap(t_map *map)
{
    t_minimap minimap;

    if (!map)
        return ((t_minimap){0});
    ft_bzero(&minimap, sizeof(t_minimap));
    minimap.width = map->map_width * TILE_SIZE * MINIMAP_SCALE;
    minimap.height = map->map_height * TILE_SIZE * MINIMAP_SCALE;
    minimap.scale = MINIMAP_SCALE;
    minimap.enabled = MINIMAP;
    minimap.img = ft_create_minimap_image(ft_mtget("mlx")->data, minimap.width, minimap.height);
    if (!minimap.img)
        return ((t_minimap){0});
    return (minimap);
}