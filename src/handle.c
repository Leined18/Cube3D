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

int	handle(void)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	if (!mlx)
		return (0);
	win = mlx_new_window(mlx, 800, 600, "Cube3D");
	if (!win)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		return (0);
	}
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	return (1);
}
