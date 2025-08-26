/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_cleanup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:17:54 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/21 16:43:23 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/** * Cleans up the map structure.
 * 
 * @param map A pointer to the map structure to clean up.
 */

void	ft_cleanup_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->matrix)
	{
		free_2d(map->matrix);
		map->matrix = NULL;
	}
	ft_lstclear(&map->map_list, free);
	i = 0;
	while (i < TEXTURE_COUNT && map->textures[i].texture)
	{
		mlx_delete_texture(map->textures[i].texture);
		map->textures[i].texture = NULL;
		i++;
	}
}
