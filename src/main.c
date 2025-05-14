/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 22:43:12 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(void)
{
	t_mt *s;

	(void)s;
	//mlx_t	*mlx;

	//mlx = mlx_init(800, 600, "Cube3D", true);
	//if (!mlx)
		//return (1);
	if (handle() == 0)
	{
		printf("Error\n");
		return (1);
	}
	//mlx_loop(mlx);
	return (0);
}
