/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:18:46 by daniel            #+#    #+#             */
/*   Updated: 2025/06/27 15:00:15 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button.h"

t_button button_new(int x, int y, const char *label, void (*on_click)(void *))
{
    t_button button;

    button.x = x;
    button.y = y;
    button.width = 60;
    button.height = 60;
    button.color = 99295; // Default color (blue)
    button.label = ft_strdup(label);
    button.on_click = on_click;
    button.param = ft_mtget("game_struct")->data; // Assuming you have a game struct stored in mt
    return button;
}

void init_button_image(mlx_t *mlx, t_button *btn)
{
	if (!btn || !mlx)
		return;

	btn->img = mlx_new_image(mlx, btn->width, btn->height);

	int y = 0;
	while (y < btn->height)
	{
		int x = 0;
		while (x < btn->width)
			mlx_put_pixel(btn->img, x++, y, btn->color);
		y++;
	}
	mlx_image_to_window(mlx, btn->img, btn->x, btn->y);
}

void draw_button(mlx_t *mlx, t_button *btn)
{
    if (!mlx || !btn)
        return;

    if (!btn->img)
        init_button_image(mlx, btn);
    if (btn->img)
    {
        mlx_image_to_window(mlx, btn->img, btn->x, btn->y);
        if (btn->label)
        {
            mlx_put_string(mlx, btn->label, btn->x + (btn->width / 2) - (ft_strlen(btn->label) * 5), 
                           btn->y + (btn->height / 2) - 10);
        } 
    }
}
