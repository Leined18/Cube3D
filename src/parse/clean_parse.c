/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:06:47 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/18 18:00:11 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// void	free_textures(t_textures *textures)
// {
// 	if (textures->NO)
// 		free(textures->NO);
// 	if (textures->SE)
// 		free(textures->SE);
// 	if (textures->WE)
// 		free(textures->WE);
// 	if (textures->EA)
// 		free(textures->EA);
// 	if (textures->F)
// 		free(textures->F);
// 	if (textures->C)
// 		free(textures->C);
// 	textures->NO = NULL;
// 	textures->SE = NULL;
// 	textures->WE = NULL;
// 	textures->EA = NULL;
// 	textures->F = NULL;
// 	textures->C = NULL;
// }

int	free_all(t_game *game, char **tokens, char *message)
{
	if (tokens)
		free_2d(tokens);
	ft_cleanup(game);
	if (message)
		ft_printf("Error\n%s\n", message);
	return (-1);
}

// void	free_map_array(t_map *map)
// {
// 	int	i;

// 	if (!map->matrix)
// 		return;
// 	i = 0;
// 	while (map->matrix[i])
// 	{
// 		free(map->matrix[i]);
// 		i++;
// 	}
// 	free(map->matrix);
// 	map->matrix = NULL;
// }

// void	free_char_array(char **array)
// {
// 	int	i;

// 	if (!array)
// 		return;
// 	i = 0;
// 	while (array[i])
// 	{
// 		free(array[i]);
// 		i++;
// 	}
// 	free(array);
// 	array = NULL;
// }