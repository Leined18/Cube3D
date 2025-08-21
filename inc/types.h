/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:39:44 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/21 09:23:35 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "MLX42.h"
# include "libft.h"
# include "mt.h"

# define MAX_TEXTURES 128 // 1 por cada caracter ASCII válido

/**
 *
 */

typedef struct s_vector
{
	double			x;
	double			y;
}					t_vect2;

/**
 *
 */

typedef struct s_coord
{
	int				x;
	int				y;
}					t_coord;

/**
 * texture Textura del muro
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
}					t_screenline;

/**
 * tx_dir id de la textura a usar para pintar el muro.
 * mlx_tx Puntero a la textura que indica tx_dir.
 */

typedef struct s_tex_inf
{
	int				tx_dir;
	mlx_texture_t	*mlx_tx;
	double			wallx;
	t_coord			tx;
	double			tx_step;
	double			tx_pos;
	int				pixel_index;
}					t_tex_inf;

/**
 * cameraX Normalizacion de las columnas de pixels de la pantalla (-1 .. 0 .. 1)
 * dir;vector que indica la direccion a donde va el rayo.
 * pos;posición actual en la grid/mapa
 * delta_dist distancia a recorrer para pasar a la siguiente línea X o Y

	* side_dist distancia acumulada desde el origen del rayo a la próxima línea X o Y
 * step;dirección de incremento en X e Y
 * side;0 si el muro es vertical, 1 si horizontal
 * hit;0 si aun no ha chocado con un muro, 1 si ha chocado.
 * hit_door;0 si no ha chocado con una puerta parcialmente abierta,
 * perpWallDist;distancia corregida hasta la pared perpendicular a plane.

	* draw; inicio y final de pintado de una linea de pantalla respecto a la distancia del muro.
 * tex_info; Información de textura para pintar el muro.
 */

typedef struct s_ray
{
	double			camerax;
	t_vect2			dir;
	t_coord			pos;
	t_vect2			delta_dist;
	t_vect2			side_dist;
	t_coord			step;
	int				side;
	int				hit;
	int				hit_door;
	double			perpwalldist;
	t_screenline	draw;
	t_tex_inf		tex_info;
}					t_ray;

/**
 *
 */

typedef struct s_button
{
	int				x;
	int				y;
	int				width;
	int				height;
	uint32_t		color;
	char			*label;
	void			(*on_click)(void *);
	void			*param;
	mlx_image_t		*label_img;
	mlx_image_t		*img;
	bool			active;
	mlx_t			*mlx;
}					t_button;

/**
 *
 */

typedef struct s_textures
{
	char			symbol;
	char			*path;
	mlx_texture_t	*texture;
	uint32_t		color;
}					t_textures;

/**
 *
 */

typedef struct s_player
{
	t_vect2			pos;
	t_vect2			dir;
	t_vect2			plane;
	double			fov_degrees;
	double			fov_factor;
	t_mt			*objs;
}					t_player;

/**
 * mlx_image_t *img;  // Imagen del minimapa
	int width;         // Ancho del minimapa
	int height;        // Alto del minimapa
	double scale;      // Escala del minimapa respecto al mapa real
	bool enabled;      // Indica si el minimapa está habilitado
	mlx_image_t *text; // Imagen de texto para el minimapa
	int32_t instance;  // ID de la instancia del minimapa
 */

typedef struct s_minimap
{
	mlx_image_t		*img;
	int				width;
	int				height;
	double			scale;
	bool			enabled;
	mlx_image_t		*text;
	int32_t			instance;
}					t_minimap;

/**
 *
 */

typedef struct s_door
{
	int				x;
	int				y;
	bool			open;
	double			anim_state;
	double			anim_elapsed;
	double			timer;
}					t_door;

/**
 *
 */

typedef struct s_doors
{
	t_door			*doors_array;
	size_t			doors_count;
}					t_doors;

/**
 *
 */

typedef struct s_map
{
	size_t			map_width;
	size_t			map_height;
	int				player_count;
	t_list			*map_list;
	char			**matrix;
	t_minimap		minimap;
	t_doors			doors_info;
	t_textures		textures[MAX_TEXTURES];
	t_mt			*objs;
}					t_map;

/**
 *
 */

typedef struct s_render
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				screen_width;
	int				screen_height;
	t_button		buttons[10];
	int				button_count;
	int32_t			instance;
	t_mt			*objs;
}					t_render;

/**
 * 
 */

typedef struct s_input
{
	bool			move_forward;
	bool			move_backward;
	bool			move_left;
	bool			move_right;
	bool			rotate_left;
	bool			rotate_right;
}					t_input;

/**
 * 
 */

typedef struct s_game
{
	bool			running;
	t_map			map;
	t_player		player;
	t_render		render;
	t_input			input;
	bool			cursor_hidden;
	t_backup		*backup;
}					t_game;

#endif /* TYPES_H */
