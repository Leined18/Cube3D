/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:06:47 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/06 10:21:35 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_cleanup_parse(t_game *game)
{
	ft_cleanup_map(&game->map);
	ft_cleanup_player(&game->player);
	ft_cleanup_render(&game->render);
	ft_backup_static(0, false, true);
}

int	free_all(t_game *game, char **tokens, char *message)
{
	if (tokens)
		free_2d(tokens);
	ft_cleanup_parse(game);
	if (message)
		ft_printf("Error\n%s\n", message);
	return (-1);
}
