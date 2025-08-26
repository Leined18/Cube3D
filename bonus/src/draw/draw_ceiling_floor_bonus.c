/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_floor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:42:06 by daniel            #+#    #+#             */
/*   Updated: 2025/08/06 10:13:06 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	draw_ceiling(mlx_image_t *img, int x, t_screenline draw)
{
	int	y;

	y = 0;
	while (y < draw.start && y < SCREEN_HEIGHT)
	{
		mlx_put_pixel(img, x, y, get_ceiling_color(&draw));
		y++;
	}
}

void	draw_floor(mlx_image_t *img, int x, t_screenline draw)
{
	int	y;

	y = draw.end + 1;
	while (y < SCREEN_HEIGHT)
	{
		mlx_put_pixel(img, x, y, get_floor_color(&draw));
		y++;
	}
}
