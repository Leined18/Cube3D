/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:41:38 by daniel            #+#    #+#             */
/*   Updated: 2025/06/18 17:54:18 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

uint32_t	get_ceiling_color(t_screenline *draw, int x, int y)
{
	if (!TEXTURES)
		return draw->color_ceiling;
	t_vect2 tex = {
		.x = (x % draw->texture_ceiling->width) * draw->texture_ceiling->width / screenWidth,
		.y = y * draw->texture_ceiling->height / draw->start
	};
	return get_pixel_texture(draw->texture_ceiling, tex.x, tex.y);
}

uint32_t	get_floor_color(t_screenline *draw, int x, int y)
{
	if (!TEXTURES)
		return draw->color_floor;
	t_vect2 tex = {
		.x = (x % draw->texture_floor->width) * draw->texture_floor->width / screenWidth,
		.y = (y - draw->end - 1) * draw->texture_floor->height / (screenHeight - draw->end - 1)
	};
	return get_pixel_texture(draw->texture_floor, tex.x, tex.y);
}

uint32_t	get_wall_color(t_screenline *draw, int y)
{
	if (!TEXTURES && !DEBUG)
		return draw->color_wall;
	t_vect2 tex = {
		.x = draw->tex.x,
		.y = calc_texture_y(y, draw->start, draw->end - draw->start + 1, draw->texture->height)
	};
	return get_pixel_texture(draw->texture, tex.x, tex.y);
}
