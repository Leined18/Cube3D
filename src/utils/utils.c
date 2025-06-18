/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:28:20 by daniel            #+#    #+#             */
/*   Updated: 2025/06/18 17:34:11 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int ft_clamp(int value, int min, int max)
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
