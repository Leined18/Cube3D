/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:18:46 by daniel            #+#    #+#             */
/*   Updated: 2025/07/02 14:17:22 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void ft_draw_button(mlx_t *mlx, t_button *btn)
{
    int x;
    int y;
    
    if (!mlx || !btn || !btn->img)
        return;
    x = btn->x + btn->width / 2;
    y = btn->y + btn->height / 2;
    if (btn->img)
    {
        mlx_image_to_window(mlx, btn->img, btn->x, btn->y);
        if (btn->label)
            btn->label_img = mlx_put_string(mlx, btn->label, x - (ft_strlen(btn->label) * 5),  y - 10);
    }
    btn->active = true; // Set the button to active
}



