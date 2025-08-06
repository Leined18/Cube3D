/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_buttons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:51:08 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 11:00:11 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_draw_buttons(t_game *game)
{
	int	i;

	if (!game)
		return (0);
	i = -1;
	while (++i < 2)
		ft_draw_button(game->render.mlx, &game->render.buttons[i]);
	return (1);
}
