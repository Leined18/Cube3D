/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:47:30 by daniel            #+#    #+#             */
/*   Updated: 2025/08/06 10:13:55 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	set_color_texture(t_screenline *d, int side, t_tex_inf *ti)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	ti->tx.y = ft_clamp((int)ti->tx_pos, 0, ti->mlx_tx->height - 1);
	ti->tx_pos += ti->tx_step;
	ti->pixel_index = (ti->tx.y * ti->mlx_tx->width + ti->tx.x) * 4;
	r = ti->mlx_tx->pixels[ti->pixel_index];
	g = ti->mlx_tx->pixels[ti->pixel_index + 1];
	b = ti->mlx_tx->pixels[ti->pixel_index + 2];
	a = ti->mlx_tx->pixels[ti->pixel_index + 3];
	d->color_wall = (r << 24) | (g << 16) | (b << 8) | a;
	if (side == 0)
		d->color_wall = darken_color(d->color_wall);
}

/**
 * aplica oscurecimiento al %50
 */

uint32_t	darken_color(uint32_t color)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	r = (color >> 24) & 0xFF;
	g = (color >> 16) & 0xFF;
	b = (color >> 8) & 0xFF;
	a = color & 0xFF;
	r /= 2;
	g /= 2;
	b /= 2;
	return (r << 24 | g << 16 | b << 8 | a);
}
