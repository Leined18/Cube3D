/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:25:00 by mvidal-h          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/22 11:31:03 by mvidal-h         ###   ########.fr       */
=======
/*   Updated: 2025/08/06 10:23:11 by danpalac         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

<<<<<<< HEAD
//Elimina los espacios y tabulaciones de un string, dejando solo un espacio
//después del identificador del elemento, y devuelve un nuevo string.
char	*remove_spaces(char *str)
{
	int		i;
	int		j;
	int		space;
	char	*clean;

	i = 0;
	j = 0;
	space = 0;
	clean = malloc(strlen(str) + 1);
	if (!clean)
		return (free(str), NULL);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			clean[j++] = str[i];
		else if (str[i] == ' ' && !space)
		{
			clean[j++] = ' ';
			space = 1;
		}
=======
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
>>>>>>> main
		i++;
	}
	return (0);
}

int	is_map_line(char *line)
{
	int	not_all_spaces;

	not_all_spaces = 0;
	while (*line)
	{
		if (*line != ' ' && *line != '0' && *line != '1'
			&& *line != 'N' && *line != 'S' && *line != 'E' && *line != 'W')
			return (0);
		if (*line != ' ')
			not_all_spaces = 1;
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
