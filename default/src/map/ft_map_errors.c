/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:51:23 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/16 14:45:47 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*Write the error message in the stderr, free buffer if necessary and exit*/
void	wrong_map_exit(char *buffer, char *message, int need_free)
{
	ft_printf("Error\n%s\n", message);
	if (need_free)
		free(buffer);
	exit(EXIT_FAILURE);
}

/*Check if the map file extension is ".cub". Error and exit if not*/
void	check_arg_cub(char *name)
{
	int	len_total;
	int	len_name;

	len_total = ft_strlen(name);
	len_name = len_total - 4;
	if (!(len_total > 4 && ft_strncmp(name + len_name, ".cub", 4) == 0
			&& name[len_total - 5] != '/'))
	{
		ft_printf("Error: Invalid map file extension. Expected '.cub'\n");
		exit(EXIT_FAILURE);
	}
}
