/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_get_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:41:38 by daniel            #+#    #+#             */
/*   Updated: 2025/08/06 10:13:27 by danpalac         ###   ########.fr       */
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
