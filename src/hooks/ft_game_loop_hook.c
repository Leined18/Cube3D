/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:43:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:59:59 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_on_game_loop(void *param)
{
	t_game	*g;
	double	rot_speedk;
	double	rot_speedm;
	double	move_speed;

	g = (t_game *)param;
	move_speed = g->render.mlx->delta_time * get_player_speed(g->render.mlx);
	rot_speedk = g->render.mlx->delta_time * PLAYER_ROTATION_SPEED;
	if (g->cursor_hidden)
	{
		rot_speedm = g->render.mlx->delta_time * MOUSE_ROTATION_SPEED;
		update_mouse_rotation(g, rot_speedm);
	}
	update_player_movement(g, move_speed, rot_speedk);
	update_doors_touch_timer(g);
	update_doors_animation(g, g->render.mlx->delta_time);
	update_minimap(g);
	if (cast_all_rays(g) < 0)
		exit(-1);
}
