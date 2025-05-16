/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:59:15 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 23:15:50 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void loop(void *param)
{
	mlx_t *mlx;

	mlx = (mlx_t *)param;
	mlx_loop(mlx);
}


int	handle(void)
{
	mlx_t *mlx;

	mlx = mlx_init(1920, 1080, "Cube3D", true);
	if (!mlx)
	{
		ft_putstr_fd("Error: mlx_init failed\n", 2);
		return (1);
	}
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx_set_setting(MLX_MAXIMIZED, 1);
	mlx_loop(mlx);
	return (1);
}
