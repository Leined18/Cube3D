/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:55:58 by daniel            #+#    #+#             */
/*   Updated: 2025/06/19 11:04:56 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int ft_load_texture(t_textures *texture)
{
    if (!texture || !texture->path)
        return (0);
    texture->texture = mlx_load_png(texture->path);
    if (!texture->texture)
    {
        ft_error("Error: Failed to load texture from path: ", 0);
        ft_error(texture->path, 0);
        ft_error("\n", 0);
        return (0);
    }
    return (1);
}

int ft_init_textures(t_map *map)
{
    if (!map)
        return (0);
    int i = 0;
    while (i < TEXTURE_COUNT - 2) // Exclude F and C
    {
        if (!ft_load_texture(&map->textures[i]))
            return (ft_error("Error: Failed to load texture\n", 0), 0);
        i++;
    }
    ft_mtnew("map", "textures")->data = map->textures;
    return (1);
}
