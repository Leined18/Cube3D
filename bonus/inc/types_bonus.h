/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:39:44 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/26 13:19:06 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_BONUS_H
# define TYPES_BONUS_H

# include "MLX42.h"
# include "libft.h"
# include "mt.h"

# define MAX_TEXTURES 128 // 1 por cada caracter ASCII válido

/**
 * t_vect2 Struct that represents a double 2D vector.
 */
typedef struct s_vector
{
	double			x;
	double			y;
}					t_vect2;

/**
 * t_coord Struct that represents a 2D integer coordinate.
 */
typedef struct s_coord
{
	int				x;
	int				y;
}					t_coord;

/**
 * Struct that represents a screen line for rendering.
 * @start: starting pixel of the line
 * @end: ending pixel of the line
 * @lineheight: height of the line
 * @color_wall: color of the wall
 * @color_floor: color of the floor
 * @color_ceiling: color of the ceiling
 * @texture: texture of the wall
 * @texture_floor: texture of the floor
 * @texture_ceiling: texture of the ceiling
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
 * t_tex_inf Struct that represents texture information for rendering.
 * @tx_dir: id of the texture to use for rendering.
 * @mlx_tx: pointer to the texture that corresponds to tx_dir.
 * @wallx: x-coordinate of the wall hit by the ray.
 * @tx: coordinate equivalent to wallx in the texture.
 * @tx_step: step size for texture mapping.
 * @tx_pos: current position within the texture.
 * @pixel_index: index of the pixel being rendered.
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
 * @camerax: Normalizacion de las columnas de pixels 
 * 	de la pantalla (-1 .. 0 .. 1)
 * @dir: vector que indica la direccion a donde va el rayo.
 * @pos: posición actual en la grid/mapa
 * @delta_dist: distancia a recorrer para pasar a la siguiente línea X o Y

 * @side_dist: distancia acumulada desde el origen del rayo a la próxima
 *	línea X o Y
 * @step: dirección de incremento en X e Y
 * @side: 0 si el muro es vertical, 1 si horizontal
 * @hit: 0 si aun no ha chocado con un muro, 1 si ha chocado.
 * @hit_door: 0 si no ha chocado con una puerta parcialmente abierta,
 * @perpwalldist: distancia corregida hasta la pared perpendicular a plane.
 * @draw: inicio y final de pintado de una linea de pantalla respecto a la
 *	distancia del muro.
 * @tex_info: Información de textura para pintar el muro.
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
 * Button struct for interactive elements in the game UI.
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
 *  Struct that represents texture information with symbol in map
 * and its corresponding texture.
 */
typedef struct s_textures
{
	char			symbol;
	char			*path;
	mlx_texture_t	*texture;
	uint32_t		color;
}					t_textures;

/**
 * Struct that represents the player in the game.
 * @pos: Position of the player in the map.
 * @dir: Direction the player is facing.
 * @plane: Camera plane vector.
 * @fov_degrees: Field of view in degrees.
 * @fov_factor: Field of view factor for raycasting.
 * @objs: auxiliary pointer to the game objects.
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
 * @img: Imagen del minimapa
 * @width: Ancho del minimapa
 * @height: Alto del minimapa
 * @scale: Escala del minimapa respecto al mapa real
 * @enabled: Indica si el minimapa está habilitado
 * @text: Imagen de texto para el minimapa
 * @instance: Instancia de la imagen en MLX
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
 * Struct that represents a door in the game.
 * @x: x-coordinate of the door in the map grid.
 * @y: y-coordinate of the door in the map grid.
 * @open: boolean indicating if the door is open (true) or closed (false).
 * @anim_state: current animation state of the door.
 * @anim_elapsed: time elapsed since the animation started.
 * @timer: timer for the door's open/close duration.
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
 * Struct that represents all doors in the game.
 * @doors_array: array of door structures.
 * @doors_count: number of doors in the array.
 */
typedef struct s_doors
{
	t_door			*doors_array;
	size_t			doors_count;
}					t_doors;

/**
 * Struct that represents the map in the game.
 * @map_width: width of the map in grid units.
 * @map_height: height of the map in grid units.
 * @player_count: number of player starting positions found in the map.
 * @map_list: linked list containing the map lines as strings.
 * 	To check if all necessary textures are present before map line appearance.
 * @matrix: 2D array representing the map layout.
 * @doors_info: structure containing information about doors in the map.
 * @textures: array of texture information.
 * 	It can contain a texture for every Ascii carater
 * @objs: auxiliary pointer to the game objects.
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
 * Struct that represents the rendering context of MLX library,
 * and interface with buttons.
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
 * Struct that represents the movements of the player and indicates
 * what movement is "active".
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
 * Struct that represents the game state and logic.
 * @running: boolean indicating if the game is running.
 * @map: structure containing the map information.
 * @player: structure containing the player information.
 * @render: structure containing the rendering MLX information.
 * @input: structure containing the player input movements information.
 * @cursor_hidden: boolean indicating if the cursor is hidden.
 * @backup: pointer to a backup structure for memory tracking.
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
