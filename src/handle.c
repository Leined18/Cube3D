/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:59:15 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 23:15:50 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	handle_exit(void *param)
{
	t_game	*game;
	game = (t_game *)param;
	if (!game)
		return ;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		cleanup(&game);
		ft_successful("Game exited successfully\n", 1);
	}
}
