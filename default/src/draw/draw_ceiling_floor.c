/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_floor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:42:06 by daniel            #+#    #+#             */
/*   Updated: 2025/08/21 16:22:41 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_ceiling(mlx_image_t *img, int x, t_screenline draw)
{
	int	y;

	y = 0;
	while (y < draw.start && y < SCRHEIGHT)
	{
		mlx_put_pixel(img, x, y, get_ceiling_color(&draw));
		y++;
	}
}

void	draw_floor(mlx_image_t *img, int x, t_screenline draw)
{
	int	y;

	y = draw.end + 1;
	while (y < SCRHEIGHT)
	{
		mlx_put_pixel(img, x, y, get_floor_color(&draw));
		y++;
	}
}
