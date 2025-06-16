/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:33:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/16 15:18:58 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_ceiling(mlx_image_t* img, int x, t_screenline draw)
{
	int	index;

	index = 0;
	while (index < draw.start)
	{
		mlx_put_pixel(img, x, index, draw.color_ceiling);
		index++;
	}
}

void	draw_floor(mlx_image_t* img, int x, t_screenline draw)
{
	int	index;
	t_game	g;

	index = draw.end + 1;
	g = *(t_game *)ft_mtget("game_struct")->data;
	while (index <= g.render.screen_height - 1)
	{
		mlx_put_pixel(img, x, index, draw.color_floor);
		index++;
	}
}

void	draw_wall(mlx_image_t* img, int x, t_screenline draw)
{
	int	index;
	
	index = draw.start;
	while (index <= draw.end)
	{
		mlx_put_pixel(img, x, index, draw.color_wall);
		index++;
	}
}

void	draw_vertical_line(mlx_image_t* img, int x, t_screenline draw)
{
	draw_ceiling(img, x, draw);
	draw_wall(img, x, draw);
	draw_floor(img, x, draw);
}

void	calc_draw_line(t_game *g, t_ray *ray)
{
	int	lineheight;

	lineheight = (int)(g->render.screen_height / ray->perpWallDist);
	ray->draw.start = g->render.screen_height / 2 - lineheight / 2;
	if (ray->draw.start < 0)
		ray->draw.start = 0;
	ray->draw.end = g->render.screen_height / 2 + lineheight / 2;
	if (ray->draw.end >= g->render.screen_height)
		ray->draw.end = g->render.screen_height - 1;
	ray->draw.color_wall = set_color_line(g, ray->map, ray->side);
	ray->draw.color_floor = darken_color(0xFFFFFFFF);
	ray->draw.color_ceiling = 0x00000000;
}
