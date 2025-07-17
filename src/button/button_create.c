/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 23:05:21 by daniel            #+#    #+#             */
/*   Updated: 2025/07/09 13:13:17 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_button button_new(t_vect2 c, const char *label, void (*on_click)(void *), u_int32_t color)
{
    t_button    button;

    ft_bzero(&button, sizeof(t_button));
    button.x = c.x;
    button.y = c.y;
    button.width = 135;
    button.height = 110;
    button.color = color; // Default color (blue)
    button.label = ft_strdup(label);
    button.on_click = on_click;
    button.param = ft_mtget("game_struct")->data; // Assuming you have a game struct stored in mt
    button.mlx = ft_mtget("mlx")->data; // Get the mlx instance from memory tracking
    return (button);
}

int ft_create_buttons(t_render *render)
{
    t_vect2 button_pos;
    int i;
    
    if (!render)
        return (0);
    i = -1;
    button_pos.x = render->screen_width / 2 - 50;
    button_pos.y = render->screen_height / 2 - 50;
    render->buttons[0] = button_new(button_pos, "Exit", print_exit, 0xF00000FF); // Red color for the exit button
    button_pos.x += 0; // Adjust position for the next button
    button_pos.y -= 140; // Adjust position for the next button
    render->buttons[1] = button_new(button_pos, "Start", start_game, 0x00FF00FF); // Green color for the start button
    button_pos.x = SCREEN_WIDTH - 150; // Adjust position for the next button
    button_pos.y = 230; // Adjust position for the next button
    render->buttons[2] = button_new(button_pos, "Minimap", ft_show_minimap, 0x0000FFFF); // Blue color for the minimap button
    render->buttons[2].width = 100; // Set width for the minimap button
    render->buttons[2].height = 50; // Set height for the minimap button
    render->button_count = 3;
    while (++i < render->button_count)
        get_button_image(render->mlx, &render->buttons[i]);
    return (1);
}
