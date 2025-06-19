/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:07:01 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/18 16:48:35 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calc_fov_factor(double fov_degrees)
{
	double	half_angle_rad;

	half_angle_rad = deg_to_rad(fov_degrees / 2);
	return (tanf(half_angle_rad));
}

t_vect2	calc_player_dir(char dir)
{
	t_vect2	player_dir;

	if (dir == 'N' || dir == 'S')
		player_dir.x = 0;
	if (dir == 'N')
		player_dir.y = -1;
	if (dir == 'S')
		player_dir.y = 1;
	if (dir == 'E' || dir == 'W')
		player_dir.y = 0;
	if (dir == 'E')
		player_dir.x = 1;
	if (dir == 'W')
		player_dir.x = -1;
	return (player_dir);
}

t_vect2	calc_plane(t_vect2 dir, double fov_factor)
{
	t_vect2	plane;

	plane.x = -dir.y * fov_factor;
	plane.y = dir.x * fov_factor;
	return (plane);
}

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	initialize_player(t_map *map, t_player *player)
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
				player->dir = calc_player_dir(map->matrix[y][x]);
				map->matrix[y][x] = '0'; // quitar el simbolo de inicio del jugador del mapa.
				found = 1;
			}
			x++;
		}
		y++;
	}
}
