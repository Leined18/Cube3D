/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:01:04 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/02 12:02:21 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
	double		length;
	
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
