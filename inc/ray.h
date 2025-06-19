/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:29:00 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/19 10:33:39 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "types.h"

// Información del resultado del raycast
typedef struct s_ray_hit {
	bool		hit;
	int			side;
	double		perp_wall_dist;
	t_vect2		map_pos;
	t_vect2		step;
	t_vect2		side_dist;
	t_vect2		delta_dist;
	t_vect2		ray_dir;
	t_screenline draw;
}	t_ray_hit;

typedef struct s_ray_input {
	t_vect2	origin;		// Posición del jugador
	t_vect2	dir;		// Dirección del rayo (calculada según cámara)
	t_vect2	plane;		// Plano de la cámara
	int		screen_x;	// Columna de la pantalla
	int		screen_width;
    char  **matrix;	// Mapa del juego (matriz de caracteres)
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
