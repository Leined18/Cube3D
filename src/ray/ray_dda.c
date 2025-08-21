/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:06:54 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/21 09:24:37 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	setup_dda(t_ray *ray, t_game *game)
{
	set_ray_pos(ray, game->player.pos.x, game->player.pos.y);
	calc_delta_dist(ray);
	calc_step_dir(ray);
	calc_side_dist(ray, &game->player.pos);
	return (1);
}

int	is_hit_elem(t_game *g, int y, int x)
{
	char	c;

	c = g->map.matrix[y][x];
	if (!g->map.textures[(int)c].texture)
		return (0);
	if (is_door_symbol(c) && is_door_open(g, x, y))
		return (0);
	return (1);
}

void	calc_step_dda(t_ray *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->pos.x += ray->step.x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->pos.y += ray->step.y;
		ray->side = 1;
	}
}

static int	reach_wall(t_ray *ray, t_game *g)
{
	double	temp_wallx;
	t_door	*door;

	ray->hit = 0;
	ray->hit_door = 0;
	while (!ray->hit)
	{
		calc_step_dda(ray);
		if (!is_hit_elem(g, ray->pos.y, ray->pos.x))
			continue ;
		door = find_door(g, ray->pos.x, ray->pos.y);
		if (door)
		{
			temp_wallx = calc_wallx(g, ray);
			if (temp_wallx < door->anim_state)
				continue ;
			ray->hit_door = 1;
		}
		ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perpwalldist = ray->side_dist.y - ray->delta_dist.y;
	return (ray->hit);
}

int	ft_raycast_dda(t_ray *ray, t_game *g)
{
	if (!ray || !g || !g->map.matrix)
		return (0);
	if (ray->camerax < -1 || ray->camerax > 1)
		return (0);
	if (!setup_dda(ray, g))
		return (0);
	if (!reach_wall(ray, g))
		return (0);
	return (ray->hit);
}
