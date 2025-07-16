/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:49:17 by danpalac          #+#    #+#             */
/*   Updated: 2025/07/16 16:07:59 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_init_player(t_player *player, t_map *map)
{
	int		y;
	int		x;
	int		found;

	y = 0;
	found = 0;
	while (!found && map->matrix[y])
	{
		x = 0;
		while (!found && map->matrix[y][x] && map->matrix[y][x] != '\n')
		{
			if (is_player(map->matrix[y][x]))
			{
				player->pos.x = x + 0.5;
				player->pos.y = y + 0.5;
				player->dir = ft_calc_player_dir(map->matrix[y][x]);
				map->matrix[y][x] = '0'; // quitar el simbolo de inicio del jugador del mapa.
				found = 1;
			}
			x++;
		}
		y++;
	}
}
