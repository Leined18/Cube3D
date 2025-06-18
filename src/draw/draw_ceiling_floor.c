/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_floor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:42:06 by daniel            #+#    #+#             */
/*   Updated: 2025/06/18 17:50:13 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_ceiling(mlx_image_t *img, int x, t_screenline draw)
{
    int y;

    y = 0;
    while (y < draw.start && y < screenHeight)
    {
        mlx_put_pixel(img, x, y, get_ceiling_color(&draw, x, y));
        y++;
    }
}

void	draw_floor(mlx_image_t *img, int x, t_screenline draw)
{
    int y;
    
    y = draw.end + 1;
    while (y < screenHeight)
    {
        mlx_put_pixel(img, x, y, get_floor_color(&draw, x, y));
        y++;
    }
}

