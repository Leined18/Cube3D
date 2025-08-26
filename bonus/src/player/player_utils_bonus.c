/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:29:13 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/06 10:23:35 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_wall(t_game *g, double x, double y)
{
	int		ix;
	int		iy;
	char	c;

	ix = (int)x;
	iy = (int)y;
	if (!g || !g->map.matrix)
		return (1);
	if (iy < 0 || iy >= (int)g->map.map_height)
		return (1);
	if (ix < 0 || ix >= (int)g->map.map_width)
		return (1);
	c = g->map.matrix[iy][ix];
	if (is_door_symbol(c) && is_door_open(g, ix, iy))
		return (0);
	return (c != '0');
}

void	can_walk(t_game *game, double new_x, double new_y, t_vect2 dir)
{
	if (!is_wall(game, new_x + MARGIN_WALL * sign(dir.x), game->player.pos.y))
		game->player.pos.x = new_x;
	if (!is_wall(game, game->player.pos.x, new_y + MARGIN_WALL * sign(dir.y)))
		game->player.pos.y = new_y;
}

double	get_player_speed(mlx_t *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT))
		return (PLAYER_RUN_SPEED);
	else
		return (PLAYER_SPEED);
}
