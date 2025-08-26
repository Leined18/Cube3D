/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_cleanup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:17:54 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:16:09 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	ft_cleanup_minimap(t_minimap *minimap)
{
	if (!minimap)
		return ;
	if (minimap->img)
	{
		mlx_delete_image(ft_mtget("mlx")->data, minimap->img);
		minimap->img = NULL;
	}
	if (minimap->text)
	{
		mlx_delete_image(ft_mtget("mlx")->data, minimap->text);
		minimap->text = NULL;
	}
	minimap->width = 0;
	minimap->height = 0;
	minimap->scale = 0;
	minimap->enabled = false;
	minimap->text = NULL;
}

void	ft_cleanup_textures(t_textures textures[MAX_TEXTURES])
{
	int	i;

	if (!textures)
		return ;
	i = 0;
	while (i < MAX_TEXTURES)
	{
		if (textures[i].path)
		{
			free(textures[i].path);
			textures[i].path = NULL;
		}
		if (textures[i].texture)
			mlx_delete_texture(textures[i].texture);
		textures[i].texture = NULL;
		i++;
	}
}

/** * Cleans up the map structure.
 *
 * @param map A pointer to the map structure to clean up.
 */

void	ft_cleanup_map(t_map *map)
{
	if (!map)
		return ;
	if (map->matrix)
	{
		free_2d(map->matrix);
		map->matrix = NULL;
	}
	ft_lstclear(&map->map_list, free);
	ft_cleanup_textures(map->textures);
	ft_cleanup_minimap(&map->minimap);
}
