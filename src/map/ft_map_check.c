/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:02:18 by mvidal-h          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/21 16:42:43 by mvidal-h         ###   ########.fr       */
=======
/*   Updated: 2025/08/06 10:16:03 by danpalac         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	is_wall_elem(t_game *g, char c)
{
	if (is_reserved_symbol(c))
		return (0);
	if (g->map.textures[(int)c].texture)
		return (1);
	return (0);
}

int	validate_map_textures(t_game *g, size_t height, size_t width)
{
	size_t	y;
	size_t	x;
	char	c;

	y = 0;
	while (y < height)
	{
<<<<<<< HEAD
		line = current_node->content;
		g->map.matrix[i] = ft_calloc(g->map.map_width + 1, sizeof(char));
		if (g->map.matrix[i] == NULL)
			return (free_all(g, NULL, "allocating memory for map array line"));
		fill_with_spaces(g->map.matrix[i], line, g->map.map_width);
		current_node = current_node->next;
		i++;
=======
		x = 0;
		while (x < width)
		{
			c = g->map.matrix[y][x];
			if (!g->map.textures[(int)c].path && !is_reserved_symbol(c))
				return (free_all(g, NULL, "No texture for element in map"));
			x++;
		}
		y++;
>>>>>>> main
	}
	return (0);
}

<<<<<<< HEAD
static int	check_map_closed(t_game *g, size_t height, size_t width)
=======
int	check_map_closed(t_game *g, size_t height, size_t width)
>>>>>>> main
{
	size_t	y;
	size_t	x;
	char	**map;

	map = g->map.matrix;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == '0' || is_player(map[y][x]) || map[y][x] == 'D')
			{
				if (y == 0 || y == height - 1 || x == 0 || x == width - 1
<<<<<<< HEAD
					|| map[y - 1][x] == ' ' || map[y + 1][x] == ' '
						|| map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
=======
					|| map[y - 1][x] == ' ' || map[y + 1][x] == ' ' || map[y][x
					- 1] == ' ' || map[y][x + 1] == ' ')
>>>>>>> main
					return (free_all(g, NULL, "Map must be closed with walls"));
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_map_border(t_game *g, size_t hei, size_t wid)
{
	size_t	y;
	size_t	x;
	char	**map;

	map = g->map.matrix;
	y = 0;
	while (y < hei)
	{
		x = 0;
		while (x < wid)
		{
			if (!is_wall_elem(g, map[0][x]) && map[0][x] != ' ')
				return (free_all(g, NULL, "Map must be surrounded by walls"));
			if (!is_wall_elem(g, map[hei - 1][x]) && map[hei - 1][x] != ' ')
				return (free_all(g, NULL, "Map must be surrounded by walls"));
			if (!is_wall_elem(g, map[y][0]) && map[y][0] != ' ')
				return (free_all(g, NULL, "Map must be surrounded by walls"));
			if (!is_wall_elem(g, map[y][wid - 1]) && map[y][wid - 1] != ' ')
				return (free_all(g, NULL, "Map must be surrounded by walls"));
			x++;
		}
		y++;
	}
	return (0);
}

int	check_map(t_game *g)
{
	if (g->map.player_count != 1)
		return (free_all(g, NULL, "Error\nMap must have exactly one player"));
	if (generate_map_array(g) < 0)
		return (-1);
	print_game_map(g->map.matrix);
	if (check_map_border(g, g->map.map_height, g->map.map_width) < 0)
		return (-1);
	if (check_map_closed(g, g->map.map_height, g->map.map_width) < 0)
		return (-1);
	if (validate_map_textures(g, g->map.map_height, g->map.map_width) < 0)
		return (-1);
	return (0);
}
