/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:01:04 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/18 10:48:24 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

double	deg_to_rad(double degrees)
{
	return (degrees * (PI / 180));
}

void	rotate_vector(t_vector *vect, double radians)
{
	double	old_vect_x;

	old_vect_x = vect->x;
	vect->x = vect->x * cos(radians) - vect->y * sin(radians);
	vect->y = old_vect_x * sin(radians) + vect->y * cos(radians);
}

t_vector	normalize(t_vector vect)
{
	t_vector	result;
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

// Función para eliminar el '\n' al final de una línea
void remove_newline(char *line)
{
	int	len;
	
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

void	fill_with_spaces(char *dest, const char *src, int width)
{
	int	i;

	i = ft_strlcpy(dest, src, width + 1);
	while (i < width)
		dest[i++] = ' ';
	dest[i] = '\0';
}