/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:46:28 by mvidal-h          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/21 16:00:06 by mvidal-h         ###   ########.fr       */
=======
/*   Updated: 2025/08/21 09:25:54 by mvidal-h         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	flip_texx(t_ray *ray)
{
	return (ray->tex_info.mlx_tx->width - ray->tex_info.tx.x - 1);
}

double	calc_wallx(t_game *g, t_ray *ray)
{
	double	wallx;
	double	map_diff;
	double	ratio;
	double	step_correction;

	if (ray->side == 0)
	{
		map_diff = ray->pos.x - g->player.pos.x;
		step_correction = (1 - ray->step.x) / 2.0;
		ratio = ray->dir.y / ray->dir.x;
		wallx = g->player.pos.y + (map_diff + step_correction) * ratio;
	}
	else
	{
		map_diff = ray->pos.y - g->player.pos.y;
		step_correction = (1 - ray->step.y) / 2.0;
		ratio = ray->dir.x / ray->dir.y;
		wallx = g->player.pos.x + (map_diff + step_correction) * ratio;
	}
	return (wallx - floor(wallx));
}

void	calc_wallx_and_texx(t_game *g, t_ray *ray)
{
<<<<<<< HEAD
	double	tx_x;

	if (ray->side == 0)
		ray->tex_info.wallx = g->player.pos.y + ray->perpwalldist * ray->dir.y;
	else
		ray->tex_info.wallx = g->player.pos.x + ray->perpwalldist * ray->dir.x;
	ray->tex_info.wallx -= floor(ray->tex_info.wallx);
	tx_x = (int)(ray->tex_info.wallx * ray->tex_info.mlx_tx->width);
	ray->tex_info.tx.x = tx_x;
	if ((ray->side == 0 && ray->dir.x > 0)
		|| (ray->side == 1 && ray->dir.y < 0))
		ray->tex_info.tx.x = flip_texx(ray);
}

void	calc_step_and_pos(double *step, double *pos, t_ray *r, int linehei)
{
	*step = (double)r->tex_info.mlx_tx->height / linehei;
	*pos = (r->draw.start - SCRHEIGHT / 2.0 + linehei / 2.0) * (*step);
=======
	t_door	*door;

	ray->tex_info.wallx = calc_wallx(g, ray);
	ray->tex_info.tx.x = ray->tex_info.wallx * ray->tex_info.mlx_tx->width;
	door = find_door(g, ray->pos.x, ray->pos.y);
	if (door)
	{
		ray->tex_info.tx.x -= door->anim_state * ray->tex_info.mlx_tx->width;
		if (ray->tex_info.tx.x < 0)
			ray->tex_info.tx.x = 0;
		else if (ray->tex_info.tx.x >= (int)ray->tex_info.mlx_tx->width)
			ray->tex_info.tx.x = (int)ray->tex_info.mlx_tx->width - 1;
	}
	if ((ray->side == 0 && ray->dir.x > 0) || (ray->side == 1 && ray->dir.y < 0)
		|| door)
		ray->tex_info.tx.x = flip_texx(ray);
}

void	calc_step_and_pos(double *step, double *pos, t_ray *r, int lineheight)
{
	*step = (double)r->tex_info.mlx_tx->height / lineheight;
	*pos = (r->draw.start - SCREEN_HEIGHT / 2.0 + lineheight / 2.0) * (*step);
>>>>>>> main
}

int	calc_tex_inf(t_game *g, t_ray *ray)
{
<<<<<<< HEAD
	int		t_dir;

	t_dir = get_texture_direction(ray->side, ray->dir);
	ray->tex_info.tx_dir = t_dir;
	ray->tex_info.mlx_tx = g->map.textures[t_dir].texture;
	calc_wallx_and_texx(g, ray);
	calc_step_and_pos(&ray->tex_info.tx_step, &ray->tex_info.tx_pos,
		ray, ray->draw.lineheight);
=======
	char	map_elem;

	map_elem = g->map.matrix[ray->pos.y][ray->pos.x];
	if (!g->map.textures[(int)map_elem].texture)
		return (free_all(g, NULL, "Texture not loaded for map element"));
	ray->tex_info.tx_dir = (int)map_elem;
	ray->tex_info.mlx_tx = g->map.textures[(int)map_elem].texture;
	calc_wallx_and_texx(g, ray);
	calc_step_and_pos(&ray->tex_info.tx_step, &ray->tex_info.tx_pos, ray,
		ray->draw.lineheight);
	return (0);
>>>>>>> main
}
