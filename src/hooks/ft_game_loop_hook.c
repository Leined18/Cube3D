/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:43:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/21 15:37:27 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*
// Mostrar FPS (opcional, incluirlo al final)
//printf("FPS: %.1f\n", 1.0 / g->time.frameTime);
*/
void	ft_on_game_loop(void *param)
{
	t_game	*g;
	double	move_speed;
	double	rot_speed;

	g = (t_game *)param;
	move_speed = g->render.mlx->delta_time * g->player.movspeed;
	rot_speed = g->render.mlx->delta_time * g->player.rotspeed;
	ft_handle_input(g, move_speed, rot_speed);
	cast_all_rays(g);
}
