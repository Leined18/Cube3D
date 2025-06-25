/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:42:28 by daniel            #+#    #+#             */
/*   Updated: 2025/06/25 12:48:58 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_wall(mlx_image_t* img, int x, t_screenline *d, t_tex_inf *ti)
{
	int	index;
	
	index = d->start;
	while (index <= d->end)
	{
		if (TEXTURES)
			set_color_texture(d, ti);
		mlx_put_pixel(img, x, index, d->color_wall);
		index++;
	}
}
