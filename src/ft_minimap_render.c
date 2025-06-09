/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:26:26 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 11:04:50 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void ft_update_minimap(mlx_t *mlx, t_map *map, t_player *player)
{
    if (!mlx || !map || !player)
        return;
    mlx_delete_image(mlx, map->minimap_img);
    ft_draw_minimap(mlx, map, player);
}

