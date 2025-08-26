/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_get_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:41:38 by daniel            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/21 16:04:59 by mvidal-h         ###   ########.fr       */
=======
/*   Updated: 2025/08/06 10:13:27 by danpalac         ###   ########.fr       */
>>>>>>> main
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
