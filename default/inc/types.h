/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:39:44 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/26 11:01:05 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "MLX42.h"
# include "libft.h"
# include "mt.h"

typedef enum e_texture
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	TEXTURE_COUNT
}	t_texture;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vect2;

/*	t_screenline
	start: inicio de la línea en la pantalla
	end: fin de la línea en la pantalla
	lineheight: altura de la línea a dibujar
	color_wall: color del muro
	color_floor: color del suelo
	color_ceiling: color del techo
	texture: textura del muro
	texture_floor: textura del suelo
	texture_ceiling: textura del techo
	wall: coordenadas del muro en el espacio de la textura
	step: paso de textura
	tex: posición de la textura
*/
typedef struct s_screenline
{
	int				start;
	int				end;
	int				lineheight;
	uint32_t		color_wall;
	uint32_t		*color_floor;
	uint32_t		*color_ceiling;
	mlx_texture_t	*texture;
	mlx_texture_t	*texture_floor;
	mlx_texture_t	*texture_ceiling;
	t_vect2			wall;
	t_vect2			step;
	t_vect2			tex;
}				t_screenline;

/*	t_tex_inf
	tx_dir: id de la textura a usar para pintar el muro.
	mlx_tx: puntero a la textura que indica tx_dir.
	wallx: Punto exacto de impacto del rayo dentro de la celda 
		del muro (0.0-1.0)
	tx: Columna de textura que se usará para esta franja vertical
	tx_step: Cuántos píxeles de textura avanzamos por cada píxel 
		vertical en pantalla
	tx_pos: Posición inicial en la textura.
	pixel_index: Índice del píxel en la textura (para acceder a los colores)
*/
typedef struct s_tex_inf
{
	int				tx_dir;
	mlx_texture_t	*mlx_tx;
	double			wallx;
	t_vect2			tx;
	double			tx_step;
	double			tx_pos;
	int				pixel_index;
}				t_tex_inf;

/*	s_ray
	cameraX:Normalización de las columnas de pixels de la 
		pantalla (-1 .. 0 .. 1)
	dir: vector que indica la direccion a donde va el rayo.
	pos: posición actual en la grid/mapa
	delta_dist: distancia a recorrer para pasar a la siguiente línea X o Y
	side_dist: distancia acumulada desde el origen del rayo a la 
		próxima línea X o Y
	step: dirección de incremento en X e Y
	hit: 0 si aun no ha chocado con un muro, 1 si ha chocado.
	perpWallDist: distancia corregida hasta la pared perpendicular a plane.
	draw: inicio y final de pintado de una linea de pantalla respecto a la
		distancia del muro.
	tex_info: Información de textura para pintar el muro.
*/
typedef struct s_ray
{
	double			camerax;
	t_vect2			dir;
	t_vect2			pos;
	t_vect2			delta_dist;
	t_vect2			side_dist;
	t_vect2			step;
	int				side;
	int				hit;
	double			perpwalldist;
	t_screenline	draw;
	t_tex_inf		tex_info;
}				t_ray;

typedef struct s_textures
{
	char			*path;
	mlx_texture_t	*texture;
	uint32_t		color;
}				t_textures;

typedef struct s_player
{
	t_vect2	pos;
	t_vect2	dir;
	t_vect2	plane;
	double	fov_degrees;
	double	fov_factor;
	double	movspeed;
	double	rotspeed;
	t_mt	*objs;
}	t_player;

typedef struct s_map
{
	size_t		map_width;
	size_t		map_height;
	int			player_count;
	t_list		*map_list;
	char		**matrix;
	bool		minimap_bool;
	t_textures	textures[TEXTURE_COUNT];
	t_mt		*objs;
}	t_map;

typedef struct s_render
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			screen_width;
	int			screen_height;
	t_mt		*objs;
}	t_render;

typedef struct s_input
{
	bool	move_forward;
	bool	move_backward;
	bool	move_left;
	bool	move_right;
	bool	rotate_left;
	bool	rotate_right;
}				t_input;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	t_render	render;
	t_input		input;
	t_backup	*backup;
}				t_game;

#endif /* TYPES_H */
