/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:56:52 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/18 16:48:35 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "MLX42.h"
# include "libft.h"
typedef struct	s_vector
{
	double		x;
	double		y;
	double		z; // Puede ser útil para futuras expansiones, como 3D
}				t_vect2;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

// typedef struct	s_time
// {
// 	double		prev;
// 	double		current;
// 	double		frameTime;
// }				t_time;

typedef struct	s_player
{
	t_vect2	pos;
	t_vect2	dir;
	t_vect2	plane;
	double		pitch; // Puede ser útil para futuras expansiones, como 3D
}				t_player;

typedef struct	s_map
{
	size_t			height;
	size_t			width;
	int			player_count;
	t_list		*map_list;
	char		**matrix;

}				t_map;

typedef struct	s_textures
{
	char	*NO;
	char	*SE;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
}				t_textures;
typedef struct	s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	int32_t			screen_width; //No se si es necesario, pero lo dejo por si acaso
	int32_t			screen_height; // No se si es necesario, pero lo dejo por si acasou
	t_textures		textures; //quizas añadir la textura en archivo posteriormente.
}				t_data;

typedef struct	s_input
{
	bool	move_forward;
	bool	move_backward;
	bool	move_left;
	bool	move_right;
	bool	rotate_left;
	bool	rotate_right;
}				t_input;

typedef struct	s_game
{
	t_player	player;
	double		fov_degrees;
	double		fov_factor;
	// t_time		time;
	t_map		map;
	t_data		data;
	t_input		input;
}				t_game;

typedef struct	s_screenline
{
	int			start;
	int			end;
	uint32_t	color_wall;
	uint32_t	color_floor;
	uint32_t	color_ceiling;
}				t_screenline;

typedef struct	s_ray
{
	double			cameraX;		//Normalizacion de las columnas de pixels de la pantalla (-1 .. 0 .. 1)
	t_vect2		dir;			//vector que indica la direccion a donde va el rayo.
	t_coord			map;			// posición actual en la grid/mapa
	t_vect2		delta_dist;		// distancia a recorrer para pasar a la siguiente línea X o Y
	t_vect2		side_dist;		// distancia acumulada desde el origen del rayo a la próxima línea X o Y
	t_coord			step;			// dirección de incremento en X e Y
	int				side;			// 0 si el muro es vertical, 1 si horizontal
	int				hit;			// 0 si aun no ha chocado con un muro, 1 si ha chocado.
	double			perpWallDist;	// distancia corregida hasta la pared perpendicular a plane.
	t_screenline	draw;			// inicio y final de pintado de una linea de pantalla respecto a la distancia del muro.
}				t_ray;

#endif // STRUCTS_H