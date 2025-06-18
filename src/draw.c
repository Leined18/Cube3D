/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:33:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/18 12:39:58 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
// Dibuja una imagen src_img sobre dst_img en la posición (dst_x, dst_y)
void	draw_image(mlx_image_t *dst_img, mlx_image_t *src_img, int dst_x, int dst_y)
{
    int	x, y;
    uint32_t	color;

    if (!dst_img || !src_img)
        return;
    for (y = 0; y < (int)src_img->height; y++)
    {
        for (x = 0; x < (int)src_img->width; x++)
        {
            color = src_img->pixels[y * src_img->width + x];
            // Opcional: salta píxeles transparentes (si usas canal alpha)
            if ((color & 0xFF000000) == 0)
                continue;
            mlx_put_pixel(dst_img, dst_x + x, dst_y + y, color);
        }
    }
}

void draw_texture(mlx_image_t *img, mlx_texture_t *texture, int x, int y)
{
	uint32_t tex_x, tex_y;
	uint32_t color;

	if (!img || !texture)
		return;

	for (tex_y = 0; tex_y < texture->height; tex_y++)
	{
		for (tex_x = 0; tex_x < texture->width; tex_x++)
		{
			color = texture->pixels[tex_y * texture->width + tex_x];
			if ((color & 0xFF000000) != 0) // Ignora píxeles transparentes
				mlx_put_pixel(img, x + tex_x, y + tex_y, color);
		}
	}
}

u_int32_t get_pixel_img(mlx_image_t *img, int x, int y)
{
	if (!img || x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
		return (0); // Retorna color
	// transparente si está fuera de los límites
	return (img->pixels[y * img->width + x]);
}

u_int16_t get_pixel_texture(mlx_texture_t *texture, int x, int y)
{
	if (!texture || x < 0 || x >= (int)texture->width || y < 0 || y >= (int)texture->height)
		return (0); // Retorna color transparente si está fuera de los límites
	return (texture->pixels[y * texture->width + x]);
}

static void	draw_ceiling(mlx_image_t* img, int x, t_screenline draw)
{
	int	index;
	int tex_x;
	int tex_y;

	index = 0;
	while (index < draw.start && index < screenHeight)
	{
		if (TEXTURES)
		{
			tex_x = (int)(draw.texture_ceiling->width * (x % draw.texture_ceiling->width) / screenWidth);
			tex_y = (int)(index * draw.texture_ceiling->height / draw.start);
			draw.color_ceiling = get_pixel_texture(draw.texture_ceiling, tex_x, tex_y);
		}
		mlx_put_pixel(img, x, index, draw.color_ceiling);
		index++;
	}
}

static void	draw_floor(mlx_image_t* img, int x, t_screenline draw)
{
	int	index;
	int tex_x;
	int tex_y;

	index = draw.end + 1;
	while (index < screenHeight - 1)
	{
		if (TEXTURES)
		{
			tex_x = (int)(draw.texture_floor->width * (x % draw.texture_floor->width) / screenWidth);
			tex_y = (int)((index - draw.end - 1) * draw.texture_floor->height / (screenHeight - draw.end - 1));
			draw.color_floor = get_pixel_texture(draw.texture_floor, tex_x, tex_y);
		}		
		mlx_put_pixel(img, x, index, draw.color_floor);
		index++;
	}
}

static void	draw_wall(mlx_image_t* img, int x, t_screenline draw)
{
	int	index;
	int	tex_x;
	int tex_y;
	
	index = draw.start;
	while (index <= draw.end && index < screenHeight)
	{
		if (TEXTURES || DEBUG)
		{
			tex_x = (int)(draw.texture->width * (x % draw.texture->width) / screenWidth);
			tex_y = (int)((index - draw.start) * draw.texture->height / (draw.end - draw.start + 1));
			draw.color_wall = get_pixel_texture(draw.texture, tex_x, tex_y);
		}
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

	lineheight = (int)(screenHeight / ray->perpWallDist);
	ray->draw.start = screenHeight / 2 - lineheight / 2;
	if (ray->draw.start < 0)
		ray->draw.start = 0;
	ray->draw.end = screenHeight / 2 + lineheight / 2;
	if (ray->draw.end >= screenHeight)
		ray->draw.end = screenHeight - 1;
	ray->draw.texture = g->map.textures[ray->side].texture;
	ray->draw.color_wall = set_color_line(g, ray->map, ray->side);
	ray->draw.color_floor = darken_color(0xFFFFFFFF);
	ray->draw.color_ceiling = 0x00000000;
}
