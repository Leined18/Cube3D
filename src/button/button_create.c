/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 23:05:21 by daniel            #+#    #+#             */
/*   Updated: 2025/08/06 10:10:04 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/**
 * funtion to create a new button.
 */

t_button	button_new(t_vect2 c, const char *label, void (*on_click)(void *),
		u_int32_t color)
{
	t_button	button;

	ft_bzero(&button, sizeof(t_button));
	button.x = c.x;
	button.y = c.y;
	button.width = 135;
	button.height = 110;
	button.color = color;
	button.label = ft_strdup(label);
	button.on_click = on_click;
	button.param = ft_mtget("game_struct")->data;
	button.mlx = ft_mtget("mlx")->data;
	return (button);
}

/**
 * generical funtion to create buttons.
 */

int	ft_create_buttons(t_render *render)
{
	t_vect2	button_pos;
	int		i;

	if (!render)
		return (0);
	i = -1;
	button_pos.x = render->screen_width / 2 - 50;
	button_pos.y = render->screen_height / 2 - 50;
	render->buttons[0] = button_new(button_pos, "Exit", print_exit,
			BUTTON_COLOR_EXIT);
	button_pos.x += 0;
	button_pos.y -= 140;
	render->buttons[1] = button_new(button_pos, "Start", start_game,
			BUTTON_COLOR_START);
	button_pos.x = SCREEN_WIDTH - 150;
	button_pos.y = 230;
	render->buttons[2] = button_new(button_pos, "Minimap", ft_show_minimap,
			BUTTON_COLOR_MINIMAP);
	render->buttons[2].width = 100;
	render->buttons[2].height = 50;
	render->button_count = 3;
	while (++i < render->button_count)
		get_button_image(render->mlx, &render->buttons[i]);
	return (1);
}
