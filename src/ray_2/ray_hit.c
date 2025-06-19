/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:29:44 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/19 09:57:44 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

bool	ray_check_collision(const t_ray_hit *hit, const t_ray_input *input)
{
	if (!hit || !input || !input->matrix)
		return (false);

	char cell = input->matrix[(int)hit->map_pos.y][(int)hit->map_pos.x];
	return (cell == '1'); // aquí puedes añadir más condiciones si lo deseas
}

bool	ray_hit_matches(const t_ray_hit *hit, const t_ray_input *input, char target)
{
	if (!hit || !input)
		return (false);

	char cell = input->matrix[(int)hit->map_pos.y][(int)hit->map_pos.x];
	return (cell == target);
}

// DDA traversal: recorre el mapa hasta encontrar una colisión
void	ray_perform_dda(t_ray_hit *hit, const t_ray_input *input)
{
	hit->hit = 0;
	while (hit->hit == 0)
	{
		if (hit->side_dist.x < hit->side_dist.y)
		{
			hit->side_dist.x += hit->delta_dist.x;
			hit->map_pos.x += hit->step.x;
			hit->side = 0;
		}
		else
		{
			hit->side_dist.y += hit->delta_dist.y;
			hit->map_pos.y += hit->step.y;
			hit->side = 1;
		}
		// Verificamos si hemos chocado con un muro
		if (input->matrix[(int)hit->map_pos.y][(int)hit->map_pos.x] == '1')
			hit->hit = 1;
	}
}
