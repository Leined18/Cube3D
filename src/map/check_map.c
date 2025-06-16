/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:02:18 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/16 14:45:46 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	generate_map_array(t_game *g)
{
	t_list	*current_node;
	char	*line;
	int		i;

	g->map.matrix = ft_calloc(g->map.map_height + 1, sizeof(char *));
	if (g->map.matrix == NULL)
		return (ft_cleanup(g), -1);
	current_node = g->map.map_list;
	i = 0;
	while (current_node)
	{
		line = current_node->content;
		g->map.matrix[i] =ft_calloc(g->map.map_width + 1, sizeof(char));
		if (g->map.matrix[i] == NULL)
			return (ft_cleanup(g), -1);
		fill_with_spaces(g->map.matrix[i], line, g->map.map_width);	
		current_node = current_node->next;
		i++;
	}
	return (0);
}

int check_map_closed(t_game *g, size_t height, size_t width)
{
	size_t		y;
	size_t		x;
	char	**map;

	map = g->map.matrix;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == '0' || is_player(map[y][x]))
			{
				if (y == 0 || y == height - 1 || x == 0 || x == width - 1
						|| map[y - 1][x] == ' ' || map[y + 1][x] == ' '
						|| map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
					return (ft_cleanup(g), -1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_map_elems(t_game *g, size_t height, size_t width)
{
	size_t		y;
	size_t		x;
	char	**map;

	map = g->map.matrix;
	y = 0;
	while (y < g->map.map_height)
	{
		x = 0;
		while (x < g->map.map_width)
		{
			if (map[0][x] != '1' && map[0][x] != ' ')
				return (ft_cleanup(g), -1);
			if (map[height - 1][x] != '1' && map[height - 1][x] != ' ')
				return (ft_cleanup(g), -1);
			if (map[y][0] != '1' && map[y][0] != ' ')
				return (ft_cleanup(g), -1);
			if (map[y][width - 1] != '1' && map[y][width - 1] != ' ')
				return (ft_cleanup(g), -1);
			x++;
		}
		y++;
	}
	return (0);
}

/* int	check_map(t_game *g)
{
	if (g->map.player_count != 1)
		return (free_parse_all(g, "Error\nMap must have exactly one player"));
	if (generate_map_array(g) < 0)
		return (-1);
	if (check_map_elems(g, g->map.height, g->map.width) < 0)
		return (-1);
	if (check_map_closed(g, g->map.height, g->map.width) < 0)
		return (-1);
	return (0);
} */
