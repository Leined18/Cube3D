/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:28:20 by daniel            #+#    #+#             */
/*   Updated: 2025/08/21 15:38:39 by mvidal-h         ###   ########.fr       */
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
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

// Linear interpolation: ft_lerp(0.0, 1.0, 0.5) => 0.5
float	ft_lerp(float a, float b, float t)
{
	return (a + (b - a) * t);
}

// Sign function: returns -1 for negative, 1 for positive, and 0 for zero
int	sign(double x)
{
	return ((x > 0) - (x < 0));
}
