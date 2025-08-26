/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:00:28 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/06 10:25:58 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	remove_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

void	fill_with_spaces(char *dest, const char *src, int width)
{
	int	i;

	i = ft_strlcpy(dest, src, width + 1);
	while (i < width)
		dest[i++] = ' ';
	dest[i] = '\0';
}

void	copy_info_color(char *str, char *clean, int *j, int *i)
{
	while (str[*i])
	{
		if (ft_isdigit(str[*i]) || str[*i] == ',')
			clean[(*j)++] = str[*i];
		(*i)++;
	}
}

void	copy_info_texture(char *str, char *clean, int *j, int *i)
{
	clean[(*j)++] = str[(*i)++];
	while (ft_isspace(str[*i]))
		(*i)++;
	clean[(*j)++] = ' ';
	while (str[*i])
		clean[(*j)++] = str[(*i)++];
}

/*Setea la linea de textura o color dejándola con un único espacio
 entre información y devuelve un nuevo string.*/

char	*remove_spaces(char *str)
{
	int		i;
	int		j;
	char	*clean;
	char	id;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	clean = malloc(strlen(str) + 3);
	if (!clean)
		return (NULL);
	while (ft_isspace(str[i]))
		i++;
	id = str[i];
	clean[j++] = str[i++];
	while (ft_isspace(str[i]))
		i++;
	clean[j++] = ' ';
	if (id == 'F' || id == 'C')
		copy_info_color(str, clean, &j, &i);
	else if (id == 'T')
		copy_info_texture(str, clean, &j, &i);
	clean[j] = '\0';
	return (clean);
}
