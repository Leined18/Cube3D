/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:43:30 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/16 14:45:46 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void ft_render_frame(void *param)
{
    t_game *g;
    
    g = (t_game *)param;
    if (!g)
        return;
    usleep(10000000 / FPS); // Simulate frame rate (60 FPS)
    ft_printf("fps: %d\n", FPS);
}