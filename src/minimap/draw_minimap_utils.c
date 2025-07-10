/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 09:49:05 by daniel            #+#    #+#             */
/*   Updated: 2025/07/10 10:17:53 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// funciona
void	ft_draw_tile(mlx_image_t *img, t_vect2 vtile, size_t size, uint32_t color)
{
	int x, y;

	if (!img || vtile.x < 0 || vtile.y < 0
		|| vtile.x + (int)size > (int)img->width || vtile.y + (int)size > (int)img->height)
		return;
	for (y = 0; y < (int)size; y++)
	{
		for (x = 0; x < (int)size; x++)
		{
			int px = vtile.x + x;
			int py = vtile.y + y;
			if (px >= 0 && py >= 0 && px < (int)img->width && py < (int)img->height)
				mlx_put_pixel(img, px, py, color);
		}
	}
}


// funciona
void	ft_draw_line(mlx_image_t *img, t_vect2 e1, t_vect2 e2, uint32_t color)
{
	int		dx;
	int		dy;
	int		steps;
	double	x_inc;
	double	y_inc;
	double	x;
	double	y;

	if (!img || e1.x < 0 || e1.y < 0 || e2.x < 0 || e2.y < 0
		|| e1.x >= (int)img->width || e1.y >= (int)img->height
		|| e2.x >= (int)img->width || e2.y >= (int)img->height)
		return ;
	dx = e2.x - e1.x;
	dy = e2.y - e1.y;
	steps = fmax(abs(dx), abs(dy));
	x_inc = (double)dx / steps;
	y_inc = (double)dy / steps;
	x = e1.x;
	y = e1.y;
	while (steps-- >= 0)
	{
		mlx_put_pixel(img, (int)x, (int)y, color);
		x += x_inc;
		y += y_inc;
	}
}


// funciona
void	fill_image_color(mlx_image_t *img, uint32_t color)
{
	size_t	i;
	uint32_t	*pixel;

	if (!img || !img->pixels)
		return;

	pixel = (uint32_t *)img->pixels;
	i = 0;
	while (i < img->width * img->height)
	{
		pixel[i] = color;
		i++;
	}
}

void ft_draw_by_tile(char tile, mlx_image_t *img, t_vect2 pos, double scale)
{
	uint32_t color;

	if (tile == '1') // Assuming '1' represents a wall
		color = 0xFFF00FFF; // Red for walls
	else if (tile == '0') // Assuming '0' represents empty space
		color = 0x0000FFF; // Black for empty space
	else if (tile == ' ') // Assuming 'P' represents the player
		color = 0x000000; // Green for other tiles
	else
		color = 0xFFFFFF; // Default color for unknown tiles
	ft_draw_tile(img, pos, ceil(TILE_SIZE * scale), color);
}