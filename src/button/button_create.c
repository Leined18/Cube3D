/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 23:05:21 by daniel            #+#    #+#             */
/*   Updated: 2025/06/27 23:25:12 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int ft_create_buttons(t_render *render)
{
    if (!render)
        return (0);
    render->buttons[0] = button_new(50, 50, "Exit", print_exit);
    render->buttons[1] = button_new(screenWidth / 2 - 50, screenHeight / 2 - 50, "Start", start_game); // Example button
    render->button_count = 2;
    return (1);
}
