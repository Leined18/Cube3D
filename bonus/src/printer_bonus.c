/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:00:24 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/26 13:25:34 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	print_game_info(t_game *game)
{
	printf("player pos = [%g, %g]\n", game->player.pos.x, game->player.pos.y);
	printf("player dir = [%g, %g]\n", game->player.dir.x, game->player.dir.y);
	printf("fov_degrees = %g\n", game->player.fov_degrees);
	printf("fov_factor = %g\n", game->player.fov_factor);
	printf("plane = [%g, %g]\n", game->player.plane.x, game->player.plane.y);
}

void	print_game_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

int	ft_print_map(t_game *game)
{
	size_t	i;

	if (!game || !game->map.matrix)
		return (0);
	i = 0;
	while (i < game->map.map_height)
	{
		ft_printf("%s\n", game->map.matrix[i]);
		i++;
	}
	return (1);
}
