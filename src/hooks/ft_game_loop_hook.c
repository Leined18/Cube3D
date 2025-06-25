/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:43:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/25 10:52:13 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void ft_on_game_loop(void *param)
{
	t_game	*g;
	double	moveSpeed;
	double	rotSpeed;

	g = (t_game *)param;
	// upgrade_frameTime(&g->time);
	// printf("Frame_time: %.3f - delta_time: %.3f\n", g->time.frameTime, g->data.mlx->delta_time);
	moveSpeed = g->render.mlx->delta_time * g->player.movspeed; // Ajusta la velocidad de movimiento
	rotSpeed = g->render.mlx->delta_time * g->player.rotspeed; // Ajusta la velocidad de rotación
	ft_handle_input(g, moveSpeed, rotSpeed);
	cast_all_rays(g);
	// Mostrar FPS (opcional)
	//printf("FPS: %.1f\n", 1.0 / g->time.frameTime);
}
