/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:43:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/07/07 15:24:39 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void ft_on_game_loop(void *param)
{
	t_game	*g;
	double	moveSpeed;
	double	rotSpeedk;
	double	rotSpeedm;

	g = (t_game *)param;
	moveSpeed = g->render.mlx->delta_time * PLAYER_SPEED;
	rotSpeedk = g->render.mlx->delta_time * PLAYER_ROTATION_SPEED;
	if (g->cursor_hidden)
	{
		rotSpeedm = g->render.mlx->delta_time * MOUSE_ROTATION_SPEED;
		update_mouse_rotation(g, rotSpeedm);
	}
	update_player_movement(g, moveSpeed, rotSpeedk);
	update_doors_touch_timer(g);
	update_doors_animation(g, g->render.mlx->delta_time);
	if (cast_all_rays(g) < 0)
		exit(-1);
	
}
