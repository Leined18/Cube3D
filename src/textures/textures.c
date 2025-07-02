/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:11:16 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/02 11:44:52 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int ft_load_texture(t_game *g, t_textures *texture)
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
	return (0);
}