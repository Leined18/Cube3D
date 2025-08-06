/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:36:51 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/06 10:14:50 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_mouse_button(mouse_key_t btn, action_t act, modifier_key_t mod,
		void *p)
{
	t_game	*g;
	int		mouse_x;
	int		mouse_y;

	(void)mod;
	g = (t_game *)p;
	if (!g || !g->render.mlx)
		return ;
	if (btn == MLX_MOUSE_BUTTON_LEFT && act == MLX_PRESS)
	{
		mlx_get_mouse_pos(g->render.mlx, &mouse_x, &mouse_y);
		ft_ui_handle_click(&g->render, mouse_x, mouse_y);
		if (g->running)
		{
			mlx_set_cursor_mode(g->render.mlx, MLX_MOUSE_HIDDEN);
			g->cursor_hidden = true;
			mlx_set_mouse_pos(g->render.mlx, SCREEN_WIDTH / 2, SCREEN_HEIGHT
				/ 2);
			ft_remove_button(g->render.mlx, &g->render.buttons[0]);
			ft_remove_button(g->render.mlx, &g->render.buttons[1]);
		}
	}
}
