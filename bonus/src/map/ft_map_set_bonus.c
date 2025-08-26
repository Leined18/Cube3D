/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:48:03 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:16:17 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

/** * Creates a new map structure.
 *
 * @return A pointer to the newly created map structure, or NULL on failure.
 * @path The path to the map file.
 */

int	ft_set_map(t_map *map)
{
	ft_mtnew("map", "map_width")->data = &map->map_width;
	ft_mtnew("map", "map_height")->data = &map->map_height;
	ft_mtnew("map", "map_struct")->data = &map;
	map->minimap = ft_create_minimap(map);
	return (1);
}
