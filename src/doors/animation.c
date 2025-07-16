/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:22:43 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/16 10:18:32 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	update_doors_animation(t_game *g, double delta_time)
{
	size_t	i;
	t_door	*door;
	double	now;

	i = 0;
	now = ft_get_time();
	while (i < g->map.doors_info.doors_count)
	{
		door = &g->map.doors_info.doors_array[i];

		if (door->open && (now - door->timer >= 5.0))
			door->open = false;

		if (door->open && door->anim_state < 1.0)
		{
			door->anim_elapsed += delta_time;
			if (door->anim_elapsed > DOOR_ANIM_TIME)
				door->anim_elapsed = DOOR_ANIM_TIME;

			double progress = door->anim_elapsed / DOOR_ANIM_TIME;
			door->anim_state = 0.5 - 0.5 * cos(progress * M_PI);
		}
		else if (!door->open && door->anim_state > 0.0)
		{
			door->anim_elapsed -= delta_time;
			if (door->anim_elapsed < 0.0)
				door->anim_elapsed = 0.0;

			double progress = door->anim_elapsed / DOOR_ANIM_TIME;
			door->anim_state = 0.5 - 0.5 * cos(progress * M_PI);
		}

		i++;
	}
}



