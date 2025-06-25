/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_get_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:41:38 by daniel            #+#    #+#             */
/*   Updated: 2025/06/25 12:57:37 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

uint32_t	get_ceiling_color(t_screenline *draw)
{
	return (*draw->color_ceiling);
}

uint32_t	get_floor_color(t_screenline *draw)
{
	return (*draw->color_floor);
}

// uint32_t	get_wall_color(t_screenline *draw, int y)
// {
// 	t_vect2 tex;
// 	if (!TEXTURES && !DEBUG)
// 		return (draw->color_wall);
// 	ft_bzero(&tex, sizeof(t_vect2));
// 	tex.x = draw->tex.x;
// 	tex.y = calc_texture_y(y, draw->start, draw->end - draw->start + 1, draw->texture->height);
// 	return get_pixel_texture(draw->texture, tex.x, tex.y);
// }
