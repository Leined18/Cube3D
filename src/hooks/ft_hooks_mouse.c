/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:36:51 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/09 10:26:09 by daniel           ###   ########.fr       */
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
		ft_ui_handle_click(&g->render, mouse_x, mouse_y);
		if (g->running)
		{
			mlx_set_cursor_mode(g->render.mlx, MLX_MOUSE_HIDDEN);
			g->cursor_hidden = true;
			mlx_set_mouse_pos(g->render.mlx, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
			ft_remove_all_buttons(g->render.mlx, &g->render);
		}
	}
}



