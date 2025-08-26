/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:25:00 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/06 10:23:11 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

static bool	is_special_symbol(char c)
{
	return (c == ' ' || c == '0' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W');
}

static bool	is_color_symbol(char c)
{
	return (c == 'F' || c == 'C');
}

bool	is_reserved_symbol(char c)
{
	return (is_color_symbol(c) || is_special_symbol(c));
}

int	is_map_line(t_textures *tx, char *line)
{
	int		not_all_spaces;
	char	c;

	not_all_spaces = 0;
	while (*line)
	{
		c = *line;
		if (!is_special_symbol(c))
		{
			if (c == 'F' || c == 'C')
				return (0);
			if (!tx[(int)c].path)
				return (0);
			not_all_spaces = 1;
		}
		line++;
	}
	return (not_all_spaces);
}

int	is_player_inline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
			return (1);
		i++;
	}
	return (0);
}
