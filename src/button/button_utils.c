/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:41:11 by daniel            #+#    #+#             */
/*   Updated: 2025/07/02 14:47:49 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

mlx_image_t *get_button_image(mlx_t *mlx, t_button *btn)
{
    if (!btn || !mlx)
        return (NULL);
    btn->img = mlx_new_image(mlx, btn->width, btn->height);
    if (!btn->img)
        return (NULL);
    int y = 0;
    while (y < btn->height)
    {
        int x = 0;
        while (x < btn->width)
            mlx_put_pixel(btn->img, x++, y, btn->color);
        y++;
    }
    return (btn->img);
}

void set_button_position(t_button *btn, int x, int y)
{
    if (!btn)
        return;
    btn->x = x;
    btn->y = y;
}

void set_button_size(t_button *btn, int width, int height)
{
    if (!btn)
        return;
    btn->width = width;
    btn->height = height;
    if (btn->img)
    {
        mlx_delete_image(btn->mlx, btn->img);
        btn->img = get_button_image(btn->mlx, btn);
    }
}

void set_button_color(t_button *btn, uint32_t color)
{
    if (!btn)
        return;
    btn->color = color;
    if (btn->img)
    {
        mlx_delete_image(btn->mlx, btn->img);
        btn->img = get_button_image(btn->mlx, btn);
    }
}

void set_button_label(t_button *btn, const char *label)
{
    if (!btn || !label)
        return;
    if (btn->label)
        free(btn->label);
    btn->label = ft_strdup(label);
    if (btn->label_img)
        mlx_delete_image(btn->mlx, btn->label_img);
    btn->label_img = mlx_put_string(btn->mlx, btn->label, btn->x + 10, btn->y + 10);
}


