/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:46:28 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/21 16:00:06 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	flip_texx(t_ray *ray)
{
	return (ray->tex_info.mlx_tx->width - ray->tex_info.tx.x - 1);
}

void	calc_wallx_and_texx(t_game *g, t_ray *ray)
{
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
}

void	calc_tex_inf(t_game *g, t_ray *ray)
{
	int		t_dir;

	t_dir = get_texture_direction(ray->side, ray->dir);
	ray->tex_info.tx_dir = t_dir;
	ray->tex_info.mlx_tx = g->map.textures[t_dir].texture;
	calc_wallx_and_texx(g, ray);
	calc_step_and_pos(&ray->tex_info.tx_step, &ray->tex_info.tx_pos,
		ray, ray->draw.lineheight);
}
