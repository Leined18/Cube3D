/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:01:04 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/26 13:25:23 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

double	deg_to_rad(double degrees)
{
	return (degrees * (PI / 180));
}

void	rotate_vector(t_vect2 *vect, double radians)
{
	double	old_vect_x;

	old_vect_x = vect->x;
	vect->x = vect->x * cos(radians) - vect->y * sin(radians);
	vect->y = old_vect_x * sin(radians) + vect->y * cos(radians);
}

t_vect2	normalize(t_vect2 vect)
{
	t_vect2	result;
	double	length;

	length = sqrt(vect.x * vect.x + vect.y * vect.y);
	if (length == 0)
	{
		result.x = 0;
		result.y = 0;
	}
	else
	{
		result.x = vect.x / length;
		result.y = vect.y / length;
	}
	return (result);
}
