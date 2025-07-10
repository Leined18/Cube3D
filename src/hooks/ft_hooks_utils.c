/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:04:11 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/10 09:45:49 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


void process_scape_key(t_game *g)
{
	if (g->cursor_hidden)
	{
		mlx_set_cursor_mode(g->render.mlx, MLX_MOUSE_NORMAL);
		g->cursor_hidden = false;
		ft_draw_button(g->render.mlx, &g->render.buttons[0]);
		ft_draw_button(g->render.mlx, &g->render.buttons[1]);
	}
	else
	{
		ft_printf("Bye!\n");
		ft_cleanup(g);
	}
}

t_door *find_door(t_game *g, int x, int y)
{
	size_t	i;

	if (!g || !g->map.doors_info.doors_array)
		return (NULL);
	for (i = 0; i < g->map.doors_info.doors_count; i++)
	{
		if (g->map.doors_info.doors_array[i].x == x
			&& g->map.doors_info.doors_array[i].y == y)
			return (&g->map.doors_info.doors_array[i]);
	}
	return (NULL);
}

double ft_get_time(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (0.0);
	return (tv.tv_sec + (double)tv.tv_usec / 1000000.0);
}

void process_action_key(t_game *g, mlx_key_data_t keydata)
{
	t_door *door;

	if (keydata.key == MLX_KEY_E)
	{
		int target_x = (int)(g->player.pos.x + g->player.dir.x);
		int target_y = (int)(g->player.pos.y + g->player.dir.y);
		door = find_door(g, target_x, target_y);
		if (door)
		{
			//toggle_door(door);
			if (door->open) //si la acabo de abrir actualizao el tiempo.
				door->timer = ft_get_time();
		}
	}
	else if (keydata.key == MLX_KEY_LEFT_SHIFT)
	{
		if (g->player.running)
			g->player.running = false;
		else
			g->player.running = true;
	}
}