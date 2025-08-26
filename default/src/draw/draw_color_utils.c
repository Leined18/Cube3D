/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_color_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:50:11 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/21 16:22:16 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	color_to_hex(t_game *game, char *color_text, uint32_t *color)
{
	int		r;
	int		g;
	int		b;
	char	**tokens;

	tokens = ft_split(color_text, ',');
	if (!tokens)
		return (free_all(game, NULL, "setting floor or ceiling color"));
	if (!tokens[0] || !tokens[1] || !tokens[2] || tokens[3])
		return (free_all(game, tokens, "Invalid color format"));
	r = ft_atoi(tokens[0]);
	g = ft_atoi(tokens[1]);
	b = ft_atoi(tokens[2]);
	free_2d(tokens);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (free_all(game, NULL, "Color must be 'R,G,B' between 0..255"));
	*color = (r << 24) | (g << 16) | (b << 8) | 0xFF;
	return (0);
}

int	set_surface_color(t_game *g, char surface)
{
	int	c;

	if (surface == 'F')
		c = color_to_hex(g, g->map.textures[F].path, &g->map.textures[F].color);
	else if (surface == 'C')
		c = color_to_hex(g, g->map.textures[C].path, &g->map.textures[C].color);
	else
		return (free_all(g, NULL, "Invalid surface type"));
	return (c);
}

static uint32_t	get_def_wall_color(t_game *g, t_vect2 map)
{
	char	pos;

	pos = g->map.matrix[(int)map.y][(int)map.x];
	if (pos == '1')
		return (0xFF0000FF);
	if (pos == '2')
		return (0x00FF00FF);
	if (pos == '3')
		return (0x0000FFFF);
	if (pos == '4')
		return (0xFFFF00FF);
	return (0xFFA500FF);
}

uint32_t	set_color_line(t_game *g, t_vect2 map, int wall_side)
{
	uint32_t	color;

	color = get_def_wall_color(g, map);
	if (wall_side)
		color = darken_color(color);
	return (color);
}
