/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:55:58 by daniel            #+#    #+#             */
/*   Updated: 2025/06/18 18:04:26 by mvidal-h         ###   ########.fr       */
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
    map->textures[NO].path = TEXTURE_NO;
    map->textures[SO].path = TEXTURE_SE;
    map->textures[WE].path = TEXTURE_WE;
    map->textures[EA].path = TEXTURE_EA;
    map->textures[F].path = TEXTURE_F;
    map->textures[C].path = TEXTURE_C;
    map->textures[F].color = 0xFFFFFF; // Default color for floor
    map->textures[C].color = 0x000000; // Default color for ceiling
    int i = 0;
    while (i < TEXTURE_COUNT)
    {
        if (!ft_load_texture(&map->textures[i]))
            return (ft_error("Error: Failed to load texture\n", 0), 0);
        i++;
    }
    ft_mtnew("map", "textures")->data = map->textures;
    return (1);
}
