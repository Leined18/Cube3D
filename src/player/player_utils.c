/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:29:13 by mvidal-h          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/21 16:59:35 by mvidal-h         ###   ########.fr       */
=======
/*   Updated: 2025/08/06 10:23:35 by danpalac         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
<<<<<<< HEAD
	return (g->map.matrix[iy][ix] != '0');
=======
	c = g->map.matrix[iy][ix];
	if (is_door_symbol(c) && is_door_open(g, ix, iy))
		return (0);
	return (c != '0');
>>>>>>> main
}

/*
 * Verifica si el jugador puede moverse a la nueva posición.
	primer if:Mover en X si no hay pared en la posición nueva en X con misma Y
	segundo if:Mover en Y si no hay pared en la posición nueva en Y con misma X
 */
void	can_walk(t_game *game, double new_x, double new_y, t_vect2 dir)
{
	if (!is_wall(game, new_x + MARGIN_WALL * sign(dir.x), game->player.pos.y))
		game->player.pos.x = new_x;
	if (!is_wall(game, game->player.pos.x, new_y + MARGIN_WALL * sign(dir.y)))
		game->player.pos.y = new_y;
}
<<<<<<< HEAD
=======

double	get_player_speed(mlx_t *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT))
		return (PLAYER_RUN_SPEED);
	else
		return (PLAYER_SPEED);
}
>>>>>>> main
