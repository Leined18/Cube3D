/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:11:16 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/25 14:40:50 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	get_texture_direction(int side, t_vect2 ray_dir)
{
	if (side == 0)
	{
		if (ray_dir.x < 0)
			return (EA);
		else
			return (WE);
	}
	else
	{
		if (ray_dir.y < 0)
			return (SO);
		else
			return (NO);
	}
}