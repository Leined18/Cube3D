/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:47:30 by daniel            #+#    #+#             */
/*   Updated: 2025/06/25 15:02:20 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// uint32_t get_pixel_img(mlx_image_t *img, int x, int y)
// {
//     if (!img || x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
//         return (0); // Color transparente
//     int i = (y * img->width + x) * 4; // Índice base del píxel
    
//     uint8_t r = img->pixels[i];
//     uint8_t g = img->pixels[i + 1];
//     uint8_t b = img->pixels[i + 2];
//     uint8_t a = img->pixels[i + 3];
//     // Devuelve el color empaquetado como uint32_t RGBA
//     return (a << 24 | r << 16 | g << 8 | b);
// }

// uint32_t get_pixel_texture(mlx_texture_t *texture, int x, int y)
// {
// 	if (!texture || x < 0 || x >= (int)texture->width || y < 0 || y >= (int)texture->height)
// 		return (0); // Color transparente o negro

// 	int i = (y * texture->width + x) * 4; // Índice base del píxel

// 	uint8_t r = texture->pixels[i];
// 	uint8_t g = texture->pixels[i + 1];
// 	uint8_t b = texture->pixels[i + 2];
// 	uint8_t a = texture->pixels[i + 3];

// 	// Devuelve el color empaquetado como uint32_t RGBA
// 	return (r << 24 | g << 16 | b << 8 | a);
// }

void	set_color_texture(t_screenline *d, t_tex_inf *ti)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	// seria lo mismo que ti->tx.y = ft_clamp((int)ti->tx_pos, 0, TILE_SIZE - 1);
	ti->tx.y = ft_clamp((int)ti->tx_pos, 0, ti->mlx_tx->height - 1);
	ti->tx_pos += ti->tx_step;
	ti->pixel_index = (ti->tx.y * ti->mlx_tx->width + ti->tx.x) * 4;
			
	r = ti->mlx_tx->pixels[ti->pixel_index];
	g = ti->mlx_tx->pixels[ti->pixel_index + 1];
	b = ti->mlx_tx->pixels[ti->pixel_index + 2];
	a = ti->mlx_tx->pixels[ti->pixel_index + 3];
	d->color_wall = (r << 24) | (g << 16) | (b << 8) | a;
}

uint32_t darken_color(uint32_t color)
{
	uint8_t a = (color >> 24) & 0xFF;
	uint8_t r = (color >> 16) & 0xFF;
	uint8_t g = (color >> 8) & 0xFF;
	uint8_t b = color & 0xFF;

	// Aplica oscurecimiento (50% por ejemplo)
	r /= 2;
	g /= 2;
	b /= 2;

	return (a << 24 | r << 16 | g << 8 | b);
}

// double	calc_texture_y(int y, int start, int height, int tex_height)
// {
// 	return (y - start) * tex_height / height;
// }
