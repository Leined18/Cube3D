/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_calc_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:07:01 by mvidal-h          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/21 16:51:40 by mvidal-h         ###   ########.fr       */
=======
/*   Updated: 2025/08/06 10:23:13 by danpalac         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

double	ft_calc_fov_factor(double fov_degrees)
{
	double	half_angle_rad;

	half_angle_rad = deg_to_rad(fov_degrees / 2);
	return (tanf(half_angle_rad));
}

t_vect2	ft_calc_player_dir(char dir)
{
	t_vect2	player_dir;

	if (dir == 'N' || dir == 'S')
		player_dir.x = 0;
	if (dir == 'N')
		player_dir.y = -1;
	if (dir == 'S')
		player_dir.y = 1;
	if (dir == 'E' || dir == 'W')
		player_dir.y = 0;
	if (dir == 'E')
		player_dir.x = 1;
	if (dir == 'W')
		player_dir.x = -1;
	return (player_dir);
}

t_vect2	ft_calc_plane(t_vect2 dir, double fov_factor)
{
	t_vect2	plane;

	plane.x = -dir.y * fov_factor;
	plane.y = dir.x * fov_factor;
	return (plane);
}
