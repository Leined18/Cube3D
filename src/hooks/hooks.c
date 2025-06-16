/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:04:11 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/16 14:45:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_on_keypress(mlx_key_data_t keydata, void *param)
{
	t_game	*g;
	bool	pressed;

	g = (t_game *)param;
	pressed = (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT);
	if (keydata.key == MLX_KEY_W)
		g->input.move_forward = pressed;
	if (keydata.key == MLX_KEY_S)
		g->input.move_backward = pressed;
	if (keydata.key == MLX_KEY_A)
		g->input.move_left = pressed;
	if (keydata.key == MLX_KEY_D)
		g->input.move_right = pressed;
	if (keydata.key == MLX_KEY_LEFT)
		g->input.rotate_left = pressed;
	if (keydata.key == MLX_KEY_RIGHT)
		g->input.rotate_right = pressed;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_printf("Bye!\n");
		ft_cleanup(g);
	}
}

void handle_input(t_game *g, double moveSpeed, double rotSpeed)
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
		(void)rotSpeed;
		//rotate_player(g, -rotSpeed);
	if (g->input.rotate_right)
		(void)rotSpeed;
		//rotate_player(g, rotSpeed);
}

void ft_on_game_loop(void *param)
{
	t_game	*g;
	double	moveSpeed;
	double	rotSpeed;

	g = (t_game *)param;
	// upgrade_frameTime(&g->time);
	// printf("Frame_time: %.3f - delta_time: %.3f\n", g->time.frameTime, g->data.mlx->delta_time);
	moveSpeed = g->render.mlx->delta_time * 3.0;
	rotSpeed = g->render.mlx->delta_time * 1.5;
	handle_input(g, moveSpeed, rotSpeed);
	cast_all_rays(g);
	// Mostrar FPS (opcional)
	//printf("FPS: %.1f\n", 1.0 / g->time.frameTime);
}
