/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:50:11 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/18 17:49:18 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

//CREATE_COLOR O ALGO ASI

static uint32_t	get_def_wall_color(t_game *g, t_vect2 map)
{
	char	pos;
	
	pos = g->map.matrix[(int)map.y][(int)map.x];
	if (pos == '1')
		return 0xFF0000FF; // rojo
	if (pos == '2')
		return 0x00FF00FF; // verde
	if (pos == '3')
		return 0x0000FFFF; // azul
	if (pos == '4')
		return 0xFFFF00FF; // amarillo
	return 0xFFA500FF; // naranja por defecto
}

uint32_t	set_color_line(t_game *g, t_vect2 map, int wall_side)
{
	uint32_t	color;

	color = get_def_wall_color(g, map);
	(void)wall_side; // Si no se usa wall_side, se puede eliminar
	return (color);
}