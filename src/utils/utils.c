/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:28:20 by daniel            #+#    #+#             */
/*   Updated: 2025/08/06 10:55:50 by danpalac         ###   ########.fr       */
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

double	ft_clamp_double(double value, double min, double max)
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

float	ft_lerp(float a, float b, float t)
{
	return (a + (b - a) * t);
}

int	sign(double x)
{
	return ((x > 0) - (x < 0));
}
