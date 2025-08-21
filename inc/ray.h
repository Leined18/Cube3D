/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:29:00 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/21 15:02:09 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "types.h"

// Información del resultado del raycast
typedef struct s_ray_hit
{
	bool			hit;
	int				side;
	double			perp_wall_dist;
	t_vect2			map_pos;
	t_vect2			step;
	t_vect2			side_dist;
	t_vect2			delta_dist;
	t_vect2			ray_dir;
	t_screenline	draw;
}	t_ray_hit;

/*	t_ray_input
	Contiene la información necesaria para lanzar un rayo desde la cámara.
	origin: Posición del jugador
	dir: Dirección del rayo (calculada según cámara)
	plane: Plano de la cámara
	screen_x: Columna de la pantalla
	screen_width: Ancho de la pantalla
	matrix: Mapa del juego (matriz de caracteres)
*/
typedef struct s_ray_input
{
	t_vect2	origin;
	t_vect2	dir;
	t_vect2	plane;
	int		screen_x;
	int		screen_width;
	char	**matrix;
}	t_ray_input;

// Punto de entrada para lanzar un rayo desde la cámara
t_ray_hit	ray_cast(t_ray_input input, t_map *map);

// Funciones individuales SOLID
t_ray_hit	ray_init(t_ray_input input);
void		ray_step_and_sidedist(t_ray_hit *ray, t_vect2 pos);
void		ray_perform_dda(t_ray_hit *ray, t_map *input);
void		ray_compute_distance(t_ray_hit *ray, t_vect2 pos);
void		ray_calculate_draw(t_ray_hit *ray, int screen_height);
bool		ray_check_collision(const t_ray_hit *hit, t_map *input);
bool		ray_hit_matches(const t_ray_hit *hit, t_map *input, char target);

// Funciones de utilidades
bool		ray_has_hit(const t_ray_hit *hit);

#endif
