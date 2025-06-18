/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:47:30 by daniel            #+#    #+#             */
/*   Updated: 2025/06/18 12:48:01 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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