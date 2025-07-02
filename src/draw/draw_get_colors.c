/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_get_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:41:38 by daniel            #+#    #+#             */
/*   Updated: 2025/07/02 13:30:10 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

uint32_t	get_ceiling_color(t_screenline *draw)
{
	return (*draw->color_ceiling);
}

uint32_t	get_floor_color(t_screenline *draw)
{
	return (*draw->color_floor);
}

