/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_process_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:53:12 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/21 10:24:22 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

/*Esta funcion se encarga de abrir o cerrar una puerta al pulsar la tecla E.
Busca la puerta en la dirección en la que está mirando el jugador y la abre o
 cierra.
Si la puerta se abre, se actualiza el temporizador para que se cierre
automáticamente después de un tiempo.*/

void	process_e_key(t_game *g)
{
	t_door	*door;
	int		target_x;
	int		target_y;

	target_x = (int)(g->player.pos.x + g->player.dir.x);
	target_y = (int)(g->player.pos.y + g->player.dir.y);
	door = find_door(g, target_x, target_y);
	if (door)
	{
		toggle_door(door);
		if (door->open)
			door->timer = ft_get_time();
	}
}

void	process_m_key(t_minimap *minimap)
{
	ft_toggle(&minimap->enabled);
	if (minimap->enabled)
		minimap->img->instances[0].enabled = true;
	else
		minimap->img->instances[0].enabled = false;
}

void	process_scape_key(t_game *g)
{
	if (g->cursor_hidden)
	{
		mlx_set_cursor_mode(g->render.mlx, MLX_MOUSE_NORMAL);
		g->cursor_hidden = false;
		ft_draw_button(g->render.mlx, &g->render.buttons[0]);
		ft_draw_button(g->render.mlx, &g->render.buttons[1]);
	}
	else
	{
		ft_printf("Bye!\n");
		ft_cleanup(g);
	}
}

void	process_key(t_game *g, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
		process_e_key(g);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		process_m_key(&g->map.minimap);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		process_scape_key(g);
}
