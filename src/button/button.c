/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:18:46 by daniel            #+#    #+#             */
/*   Updated: 2025/06/27 23:48:33 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
    int x;
    int y;
    
    if (!mlx || !btn)
        return;

    if (!btn->img)
        init_button_image(mlx, btn);
    x = btn->x + btn->width / 2;
    y = btn->y + btn->height / 2;
    if (btn->img)
    {
        mlx_image_to_window(mlx, btn->img, btn->x, btn->y);
        if (btn->label)
            mlx_put_string(mlx, btn->label, x - (ft_strlen(btn->label) * 5),  y - 10);
    }
}

void remove_button(mlx_t *mlx, t_button *btn)
{
    if (!mlx || !btn || !btn->img)
        return;

    mlx_delete_image(mlx, btn->img);
    btn->img = NULL;
    if (btn->label)
    {
        free(btn->label);
        btn->label = NULL;
    }
    mlx_image_t *img = ((t_render *)ft_mtget("render")->data)->img;
    mlx_image_to_window(mlx, img, 0, 0);
    btn->on_click = NULL;
}


