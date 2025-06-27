/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:36:51 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/27 14:34:12 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"



void ft_mouse_button(mouse_key_t btn, action_t act, modifier_key_t mod, void *p)
{
	(void)mod;
	t_game *g = (t_game *)p;
	int mouse_x;
	int mouse_y;

	if (!g || !g->render.mlx)
		return;
	if (btn == MLX_MOUSE_BUTTON_LEFT && act == MLX_PRESS)
	{
		mlx_get_mouse_pos(g->render.mlx, &mouse_x, &mouse_y);

		for (int i = 0; i < g->render.button_count; i++)
		{
			ft_button_handle_click(&g->render.buttons[i], mouse_x, mouse_y);
		}
		// Opcional: ocultar cursor
		mlx_set_cursor_mode(g->render.mlx, MLX_MOUSE_HIDDEN);
		g->cursor_hidden = true;
		mlx_set_mouse_pos(g->render.mlx, screenWidth / 2, screenHeight / 2);
	}
}



