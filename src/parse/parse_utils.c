/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:25:00 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/21 16:51:29 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
		i++;
	}
	clean[j] = '\0';
	return (clean);
}
