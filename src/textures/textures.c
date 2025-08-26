/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:11:16 by mvidal-h          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/21 15:17:19 by mvidal-h         ###   ########.fr       */
=======
/*   Updated: 2025/08/06 10:25:14 by danpalac         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_load_texture(t_game *g, t_textures *texture)
{
	if (!texture || !texture->path)
		return (free_all(g, NULL, "Texture doesn't exist"));
	texture->texture = mlx_load_png(texture->path);
	if (!texture->texture)
	{
		ft_error("Error: Failed to load texture from path: ", 0);
		ft_error(texture->path, 0);
		ft_error("\n", 0);
		return (free_all(g, NULL, NULL));
	}
<<<<<<< HEAD
	else
	{
		if (ray_dir.y < 0)
			return (SO);
		else
			return (NO);
	}
=======
	return (0);
>>>>>>> main
}
