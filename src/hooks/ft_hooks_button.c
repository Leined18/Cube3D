/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_button.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:01:44 by daniel            #+#    #+#             */
/*   Updated: 2025/07/02 14:18:55 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


bool	ft_button_is_hovered(t_button *btn, int mouse_x, int mouse_y)
{
	int	x;
	int	y;
	int	w;
	int	h;

	if (!btn || !btn->img || !btn->active)
		return (false);
	x = btn->img->instances[0].x;
	y = btn->img->instances[0].y;
	w = btn->img->width;
	h = btn->img->height;
	return (
		mouse_x >= x && mouse_x < x + w &&
		mouse_y >= y && mouse_y < y + h
	);
}

void ft_button_handle_click(t_button *btn, int mouse_x, int mouse_y)
{
	if (!btn->on_click || !btn->img || !btn->active)
		return;
	if (ft_button_is_hovered(btn, mouse_x, mouse_y))
	{
		if (btn->on_click)
			btn->on_click(btn->param);
	}
}

void	ft_ui_handle_click(t_render *render, int mouse_x, int mouse_y)
{
	int	i;

	if (!render || !render->mlx)
		return;
	i = 0;
	while (i < render->button_count)
    {
        if (ft_button_is_hovered(&render->buttons[i], mouse_x, mouse_y))
        {
            ft_button_handle_click(&render->buttons[i], mouse_x, mouse_y);
            break ; // Important! Only one button can be activated
        }
        i++;
    }
}

