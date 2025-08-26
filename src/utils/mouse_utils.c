/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:55:02 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:55:22 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_set_cursor(t_game *g)
{
	mlx_set_mouse_pos(g->render.mlx, g->render.screen_width / 2,
		g->render.screen_height / 2);
}
