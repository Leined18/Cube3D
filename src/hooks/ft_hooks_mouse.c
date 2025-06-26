/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:36:51 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/26 18:40:04 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void ft_mouse_button(mouse_key_t btn, action_t act, modifier_key_t mod, void* p)
{
	(void)mod;
	t_game *g = (t_game *)p;

	if (btn == MLX_MOUSE_BUTTON_LEFT && act == MLX_PRESS)
	{
		mlx_set_cursor_mode(g->render.mlx, MLX_MOUSE_HIDDEN);
		g->cursor_hidden = true;
		mlx_set_mouse_pos(g->render.mlx, screenWidth / 2, screenHeight / 2);
	}
}
