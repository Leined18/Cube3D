/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_cleanup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:17:54 by danpalac          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/21 16:43:23 by mvidal-h         ###   ########.fr       */
=======
/*   Updated: 2025/08/06 10:16:09 by danpalac         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
<<<<<<< HEAD
	int	i;

=======
>>>>>>> main
	if (!map)
		return ;
	if (map->matrix)
	{
		free_2d(map->matrix);
		map->matrix = NULL;
	}
	ft_lstclear(&map->map_list, free);
<<<<<<< HEAD
	i = 0;
	while (i < TEXTURE_COUNT && map->textures[i].texture)
	{
		mlx_delete_texture(map->textures[i].texture);
		map->textures[i].texture = NULL;
		i++;
	}
=======
	ft_cleanup_textures(map->textures);
	ft_cleanup_minimap(&map->minimap);
>>>>>>> main
}
