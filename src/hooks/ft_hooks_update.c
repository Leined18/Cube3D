/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:53:51 by daniel            #+#    #+#             */
/*   Updated: 2025/07/09 13:09:06 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	update_mouse_rotation(t_game *g, double rotSpeed)
{
	static bool first = true;
	int	xpos;
	int	ypos;
	int	delta_x;

	/*Para que la primera vez no se mueva el raton porque podria ser que el
	 puntero estuviera totalmente a la derecha o izquierda de la pantalla y 
	entonces se moveria un salto raro hacia esa direccion. De esta manera la
	 primera ves solo centra sin mover y no hay un salto exagerado.*/
	if (first) 
	{
		first = false;
		mlx_set_mouse_pos(g->render.mlx, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		return ;
	}
	mlx_get_mouse_pos(g->render.mlx, &xpos, &ypos);
	delta_x = xpos - (SCREEN_WIDTH / 2);
	delta_x = ft_clamp(delta_x, -50, 50);
	rotate_player(g, delta_x * rotSpeed);
	mlx_set_mouse_pos(g->render.mlx, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void update_player_movement(t_game *g, double moveSpeed, double rotSpeed)
{
	if (g->input.move_forward)
		move_player_forward(g, moveSpeed);
	if (g->input.move_backward)
		move_player_backward(g, moveSpeed);
	if (g->input.move_left)
		strafe_player_left(g, moveSpeed);
	if (g->input.move_right)
		strafe_player_right(g, moveSpeed);
	if (g->input.rotate_left)
		rotate_player(g, -rotSpeed);
	if (g->input.rotate_right)
		rotate_player(g, rotSpeed);
}

void update_minimap(t_game *g)
{
    if (!g || !g->map.minimap.img)
        return;
    if (!g->map.minimap.enabled)
    {
        if (g->map.minimap.img)
        {
            g->map.minimap.img->enabled = false;
            if (g->map.minimap.img->instances && g->map.minimap.img->instances[0].enabled)
                g->map.minimap.img->instances[0].enabled = false;
        }
        return;
    }
    ft_draw_minimap(&g->map.minimap, g);
}