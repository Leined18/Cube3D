/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/21 12:47:32 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc < 2)
		ft_error("Error: No map file provided\n", 1);
	if (!setup(&game, argv[1]))
		ft_error("Error: Failed to setup game\n", 1);
	ft_successful("Game setup successful\n",0);
	//if (!mlx_loop_hook(game->mlx, handle_exit, game))
	//	ft_error("Error: Failed to set up loop\n", 1);
	//mlx_loop(game->mlx);
	return (cleanup(&game), 0);
}
