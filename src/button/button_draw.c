/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:18:46 by daniel            #+#    #+#             */
/*   Updated: 2025/08/06 10:10:55 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/**
 * funtion to draw a single button.
 */

void	ft_draw_button(mlx_t *mlx, t_button *btn)
{
	int	x;
	int	y;

	if (!mlx || !btn || !btn->img)
		return ;
	x = btn->x + btn->width / 2;
	y = btn->y + btn->height / 2;
	if (btn->img)
	{
		mlx_image_to_window(mlx, btn->img, btn->x, btn->y);
		if (btn->label)
			btn->label_img = mlx_put_string(mlx, btn->label, x
					- (ft_strlen(btn->label) * 5), y - 10);
	}
	btn->active = true;
}
