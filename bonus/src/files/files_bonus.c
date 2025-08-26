/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:53:15 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/06 10:14:19 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	secure_open(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file.\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	secure_close(int fd)
{
	if (close(fd) == -1)
	{
		ft_printf("Error closing file.\n");
		exit(EXIT_FAILURE);
	}
}
