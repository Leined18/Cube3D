/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:42:28 by daniel            #+#    #+#             */
/*   Updated: 2025/08/06 10:13:57 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	draw_wall(mlx_image_t *img, int x, t_ray *r, t_tex_inf *ti)
{
	int	index;

	index = r->draw.start;
	while (index <= r->draw.end)
	{
		if (TEXTURES)
			set_color_texture(&r->draw, r->side, ti);
		mlx_put_pixel(img, x, index, r->draw.color_wall);
		index++;
	}
}
