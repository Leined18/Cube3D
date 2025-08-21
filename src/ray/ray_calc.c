/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:54:21 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/21 17:02:01 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

double	calc_camerax(int x)
{
	t_render	render;

	render = *(t_render *)ft_mtget("render")->data;
	if (render.screen_width <= 0)
		return (0);
	return (2 * x / (double)render.screen_width - 1);
}

t_vect2	calc_ray_dir(t_vect2 dir, t_vect2 plane, double cameraX)
{
	t_vect2	ray_dir;

	ray_dir.x = dir.x + plane.x * cameraX;
	ray_dir.y = dir.y + plane.y * cameraX;
	return (normalize(ray_dir));
}

/*
Deltadistx = distancia real (hipotenusa) que recorre el rayo para pasar de una 
línea vertical a la siguiente (es decir, avanzar una unidad completa en X).

Deltadisty = distancia real (hipotenusa) que recorre el rayo para pasar de una
línea horizontal a la siguiente (es decir, avanzar una unidad completa en Y).
*/
void	calc_delta_dist(t_ray *ray)
{
	if (ray->dir.x == 0)
		ray->delta_dist.x = INFINITY;
	else
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta_dist.y = INFINITY;
	else
		ray->delta_dist.y = fabs(1 / ray->dir.y);
}

void	calc_step_dir(t_ray *ray)
{
	ray->step.x = 0;
	ray->step.y = 0;
	if (ray->dir.x < 0)
		ray->step.x = -1;
	if (ray->dir.x > 0)
		ray->step.x = 1;
	if (ray->dir.y < 0)
		ray->step.y = -1;
	if (ray->dir.y > 0)
		ray->step.y = 1;
}

void	calc_side_dist(t_ray *ray, t_vect2 *player_pos)
{
	if (ray->step.x < 0)
		ray->side_dist.x = (player_pos->x - ray->pos.x) * ray->delta_dist.x;
	else if (ray->step.x > 0)
		ray->side_dist.x = (ray->pos.x + 1.0 - player_pos->x) * ray->delta_dist.x;
	else
		ray->side_dist.x = INFINITY;
	if (ray->step.y < 0)
		ray->side_dist.y = (player_pos->y - ray->pos.y) * ray->delta_dist.y;
	else if (ray->step.y > 0)
		ray->side_dist.y = (ray->pos.y + 1.0 - player_pos->y) * ray->delta_dist.y;
	else
		ray->side_dist.y = INFINITY;
}
