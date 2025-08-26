/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:01:50 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/21 16:58:55 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_set_ray(t_ray *ray, int x, t_game *g)
{
	if (!ray || !g || !g->map.matrix)
		return (0);
	ft_bzero(ray, sizeof(t_ray));
	ray->camerax = calc_camerax(x);
	ray->dir = calc_ray_dir(g->player.dir, g->player.plane, ray->camerax);
	return (1);
}
