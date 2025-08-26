/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:28:20 by daniel            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/21 15:38:39 by mvidal-h         ###   ########.fr       */
=======
/*   Updated: 2025/08/06 10:55:50 by danpalac         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_clamp(int value, int min, int max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
<<<<<<< HEAD
=======
}

double	ft_clamp_double(double value, double min, double max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
>>>>>>> main
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

<<<<<<< HEAD
int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

// Linear interpolation: ft_lerp(0.0, 1.0, 0.5) => 0.5
=======
>>>>>>> main
float	ft_lerp(float a, float b, float t)
{
	return (a + (b - a) * t);
}

<<<<<<< HEAD
// Sign function: returns -1 for negative, 1 for positive, and 0 for zero
=======
>>>>>>> main
int	sign(double x)
{
	return ((x > 0) - (x < 0));
}
