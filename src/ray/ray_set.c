/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:01:50 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 11:07:50 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_set_ray(t_ray *ray, int x, t_game *g)
{
	if (!ray || !g || !g->map.matrix)
		return (0);
	ft_bzero(ray, sizeof(t_ray));
	ray->cameraX = calc_camera_x(x);
	ray->dir = calc_ray_dir(g->player.dir, g->player.plane, ray->cameraX);
	return (1);
}
