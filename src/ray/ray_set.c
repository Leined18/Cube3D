/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:01:50 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/25 11:14:22 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int ft_set_ray(t_ray *ray,  int x, t_game *g)
{
    if (!ray || !g || !g->map.matrix)
        return (0); // Validación de entrada
    ft_bzero(ray, sizeof(t_ray)); // Limpiar la estructura del rayo
    ray->cameraX = calc_cameraX(x);
	ray->dir = calc_ray_dir(g->player.dir, g->player.plane, ray->cameraX);
    return (1);
}