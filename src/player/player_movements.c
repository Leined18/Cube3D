/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:33:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/09 12:37:19 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	rotate_player(t_game *game, double angle)
{
	rotate_vector(&game->player.dir, angle);
	rotate_vector(&game->player.plane, angle);
}

void	move_player_forward(t_game *game, double moveSpeed)
{
	double	new_x;
	double	new_y;
	
	printf("moveSpeed: %f\n", moveSpeed);
	new_x = game->player.pos.x + game->player.dir.x * moveSpeed;
	new_y = game->player.pos.y + game->player.dir.y * moveSpeed;
	can_walk(game, new_x, new_y, game->player.dir);
}

void	move_player_backward(t_game *game, double moveSpeed)
{
	double	new_x;
	double	new_y;
	t_vect2	back_dir;
	
	new_x = game->player.pos.x - game->player.dir.x * moveSpeed;
	new_y = game->player.pos.y - game->player.dir.y * moveSpeed;
	back_dir.x = -game->player.dir.x;
	back_dir.y = -game->player.dir.y;
	can_walk(game, new_x, new_y, back_dir);
}

void	strafe_player_left(t_game *game, double moveSpeed)
{
	double	new_x;
	double	new_y;
	t_vect2	left_dir;
	
	new_x = game->player.pos.x - game->player.plane.x * moveSpeed;
	new_y = game->player.pos.y - game->player.plane.y * moveSpeed;
	left_dir.x = -game->player.plane.x;
	left_dir.y = -game->player.plane.y;
	can_walk(game, new_x, new_y, left_dir);
}

void	strafe_player_right(t_game *game, double moveSpeed)
{
	double	new_x;
	double	new_y;
	t_vect2	right_dir;

	new_x = game->player.pos.x + game->player.plane.x * moveSpeed;
	new_y = game->player.pos.y + game->player.plane.y * moveSpeed;
	right_dir.x = game->player.plane.x;
	right_dir.y = game->player.plane.y;
	can_walk(game, new_x, new_y, right_dir);
}
