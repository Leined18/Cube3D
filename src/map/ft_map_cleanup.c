/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_cleanup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:17:54 by danpalac          #+#    #+#             */
/*   Updated: 2025/07/07 15:38:33 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/** * Cleans up the map structure.
 * 
 * @param map A pointer to the map structure to clean up.
 */

void ft_cleanup_map(t_map *map)
{
    int	i;
    
    if (!map)
        return;
    if (map->matrix)
    {
        free_2d(map->matrix);
        map->matrix = NULL;
    }
    ft_lstclear(&map->map_list, free);
    i = 0;
	while (i < MAX_TEXTURES && map->textures[i].texture)
    {
		mlx_delete_texture(map->textures[i].texture);
        map->textures[i].texture = NULL;
        i++;
    }
    if (map->doors_info.doors_array)
	{
		free(map->doors_info.doors_array);
		map->doors_info.doors_array = NULL;
		map->doors_info.doors_count = 0;
	}
}
