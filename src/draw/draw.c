/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:33:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/18 19:08:17 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	draw_ceiling(mlx_image_t* img, int x, t_screenline draw)
{
	int	index;
	// int tex_x;
	// int tex_y;

	index = 0;
	while (index < draw.start && index < screenHeight)
	{
		// if (TEXTURES)
		// {
		// 	tex_x = (int)(draw.texture_ceiling->width * (x % draw.texture_ceiling->width) / screenWidth);
		// 	tex_y = (int)(index * draw.texture_ceiling->height / draw.start);
		// 	*draw.color_ceiling = get_pixel_texture(draw.texture_ceiling, tex_x, tex_y);
		// }
		mlx_put_pixel(img, x, index, *draw.color_ceiling);
		index++;
	}
}

static void	draw_floor(mlx_image_t* img, int x, t_screenline draw)
{
	int	index;
	// int tex_x;
	// int tex_y;

	index = draw.end + 1;
	while (index < screenHeight - 1)
	{
		// if (TEXTURES)
		// {
		// 	tex_x = (int)(draw.texture_floor->width * (x % draw.texture_floor->width) / screenWidth);
		// 	tex_y = (int)((index - draw.end - 1) * draw.texture_floor->height / (screenHeight - draw.end - 1));
		// 	*draw.color_floor = get_pixel_texture(draw.texture_floor, tex_x, tex_y);
		// }
		mlx_put_pixel(img, x, index, *draw.color_floor);
		index++;
	}
}

static void	draw_wall(mlx_image_t* img, int x, t_screenline draw, bool dark_mode)
{
	int	index;
	int	tex_x;
	int tex_y;
	uint32_t color_wall;
	
	index = draw.start;
	color_wall = draw.color_wall;
	while (index <= draw.end && index <= screenHeight)
	{
		color_wall = draw.color_wall;
		if (TEXTURES || DEBUG)
		{
			tex_x = (int)(draw.texture->width * (x % draw.texture->width) / screenWidth);
			tex_y = (int)((index - draw.start) * draw.texture->height / (draw.end - draw.start + 1));
			color_wall = get_pixel_texture(draw.texture, tex_x, tex_y);
		}
		if (dark_mode)
			color_wall = darken_color(color_wall);
		mlx_put_pixel(img, x, index, color_wall);
		index++;
	}
}

void	draw_vertical_line(mlx_image_t* img, int x, t_screenline draw, bool dark_mode)
{
	draw_ceiling(img, x, draw);
	draw_wall(img, x, draw, dark_mode);
	draw_floor(img, x, draw);
}

void	calc_draw_line(t_game *g, t_ray *ray)
{
	int	lineheight;

	lineheight = (int)(screenHeight / ray->perpWallDist);
	ray->draw.start = screenHeight / 2 - lineheight / 2;
	if (ray->draw.start < 0)
		ray->draw.start = 0;
	ray->draw.end = screenHeight / 2 + lineheight / 2;
	if (ray->draw.end >= screenHeight)
		ray->draw.end = screenHeight - 1;
	ray->draw.texture = g->map.textures[ray->side].texture;
	ray->draw.color_wall = set_color_line(g, ray->map, ray->side);
	ray->draw.color_floor = &g->map.textures[F].color;
	ray->draw.color_ceiling = &g->map.textures[C].color;
}
