/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:48:03 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/21 16:45:40 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/**
 * Creates a new map structure.
 *
 * @return A pointer to the newly created map structure, or NULL on failure.
 * @path The path to the map file.
 */

int	ft_set_map(t_map *map)
{
	if (!ft_init_textures(map))
		return (ft_cleanup_map(map), 0);
	ft_mtnew("map", "map_width")->data = &map->map_width;
	ft_mtnew("map", "map_height")->data = &map->map_height;
	ft_mtnew("map", "map_struct")->data = &map;
	return (1);
}
