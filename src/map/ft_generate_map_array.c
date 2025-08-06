/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_map_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:27:33 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/06 10:15:52 by danpalac         ###   ########.fr       */
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
		return (free_all(g, NULL, "allocating memory for map array"));
	current_node = g->map.map_list;
	i = 0;
	while (current_node)
	{
		line = current_node->content;
		g->map.matrix[i] = ft_calloc(g->map.map_width + 1, sizeof(char));
		if (g->map.matrix[i] == NULL)
			return (free_all(g, NULL, "allocating memory for map array line"));
		fill_with_spaces(g->map.matrix[i], line, g->map.map_width);
		current_node = current_node->next;
		i++;
	}
	return (0);
}
