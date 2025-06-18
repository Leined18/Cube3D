/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:42:28 by daniel            #+#    #+#             */
/*   Updated: 2025/06/18 17:51:57 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_wall(mlx_image_t *img, int x, t_screenline draw, bool dark_mode)
{
    int y;
    
    y = draw.start;
    while (y <= draw.end && y <= screenHeight)
    {
        uint32_t color = get_wall_color(&draw, y);
        if (dark_mode)
            color = darken_color(color);
        mlx_put_pixel(img, x, y, color);
        y++;
    }
}
