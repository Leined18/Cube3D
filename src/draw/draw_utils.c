/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:47:30 by daniel            #+#    #+#             */
/*   Updated: 2025/06/18 18:08:03 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

uint32_t get_pixel_img(mlx_image_t *img, int x, int y)
{
    if (!img || x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
        return (0); // Color transparente
    int i = (y * img->width + x) * 4; // Índice base del píxel
    
    uint8_t r = img->pixels[i];
    uint8_t g = img->pixels[i + 1];
    uint8_t b = img->pixels[i + 2];
    uint8_t a = img->pixels[i + 3];
    // Devuelve el color empaquetado como uint32_t RGBA
    return (a << 24 | r << 16 | g << 8 | b);
}

uint32_t get_pixel_texture(mlx_texture_t *texture, int x, int y)
{
	if (!texture || x < 0 || x >= (int)texture->width || y < 0 || y >= (int)texture->height)
		return (0); // Color transparente o negro

	int i = (y * texture->width + x) * 4; // Índice base del píxel

	uint8_t r = texture->pixels[i];
	uint8_t g = texture->pixels[i + 1];
	uint8_t b = texture->pixels[i + 2];
	uint8_t a = texture->pixels[i + 3];

	// Devuelve el color empaquetado como uint32_t RGBA
	return (r << 24 | g << 16 | b << 8 | a);
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

double	calc_texture_y(int y, int start, int height, int tex_height)
{
	return (y - start) * tex_height / height;
}
