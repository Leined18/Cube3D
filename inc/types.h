/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:39:44 by danpalac          #+#    #+#             */
/*   Updated: 2025/07/08 11:16:58 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "MLX42.h"
# include "libft.h"
# include "mt.h"
# include "utils.h"

// typedef enum e_texture
// {
//     NO,
//     SO,
//     WE,
//     EA,
//     F,
//     C,
//     TEXTURE_COUNT
// }	t_texture;

# define MAX_TEXTURES 128 // 1 por cada caracter ASCII válido

typedef struct s_vector
{
    double  	x;
    double  	y;
}	t_vect2;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_screenline
{
	int			            start;
	int			            end;
    int			            lineheight;
	uint32_t	            color_wall;
	uint32_t	            *color_floor;
	uint32_t	            *color_ceiling;
    mlx_texture_t	        *texture;	// Textura del muro
    mlx_texture_t	        *texture_floor; // Textura del suelo
    mlx_texture_t	        *texture_ceiling; // Textura del techo
    // t_vect2                 wall;	// Coordenada del muro en el espacio de la textura
    // t_vect2                 step;		// Paso de textura
    // t_vect2                 tex;	// Posición de la textura
}				t_screenline;

typedef struct	s_tex_inf
{
	int				tx_dir;		// id de la textura a usar para pintar el muro.
	mlx_texture_t	*mlx_tx;	// Puntero a la textura que indica tx_dir.
	double			wallX;		// Punto exacto de impacto del rayo dentro de la celda del muro (0.0 - 1.0)
	t_coord			tx;			// Columna de textura que se usará para esta franja vertical
	double			tx_step;	// Cuántos píxeles de textura avanzamos por cada píxel vertical en pantalla
	double			tx_pos;		// Posición inicial en la textura.
	int				pixel_index; // Índice del píxel en la textura (para acceder a los colores)
}				t_tex_inf;

typedef struct	s_ray
{
	double			cameraX;		//Normalizacion de las columnas de pixels de la pantalla (-1 .. 0 .. 1)
	t_vect2		    dir;			//vector que indica la direccion a donde va el rayo.
    t_coord		    pos;			// posición actual en la grid/mapa
	t_vect2		    delta_dist;		// distancia a recorrer para pasar a la siguiente línea X o Y
	t_vect2		    side_dist;		// distancia acumulada desde el origen del rayo a la próxima línea X o Y
    t_coord		    step;			// dirección de incremento en X e Y
	int				side;			// 0 si el muro es vertical, 1 si horizontal
	int				hit;			// 0 si aun no ha chocado con un muro, 1 si ha chocado.
    int				hit_door;		// 0 si no ha chocado con una puerta parcialmente abierta, 1 si ha chocado.
	double			perpWallDist;	// distancia corregida hasta la pared perpendicular a plane.
	t_screenline	draw;			// inicio y final de pintado de una linea de pantalla respecto a la distancia del muro.
    t_tex_inf		tex_info;		// Información de textura para pintar el muro.
}				t_ray;


typedef struct	s_textures
{
    char			symbol;
	char	        *path;
    mlx_texture_t 	*texture;
    uint32_t	    color;
}				t_textures;

typedef struct s_player
{
    t_vect2            pos;
    t_vect2            dir;
    t_vect2            plane;
    double		        fov_degrees;
	double		        fov_factor;
    double		        movspeed;
    double		        rotspeed;
    t_mt       *objs;
}	t_player;

typedef struct	s_door
{
	int			x;
	int			y;
	bool		open; // false = cerrada, true = abierta
	double		anim_state;
	double		timer;
}				t_door;

typedef struct	s_doors
{
	t_door		*doors_array; // Lista de puertas
	size_t		doors_count; // Número de puertas en el mapa
}               t_doors;

typedef struct s_map
{
    size_t		    map_width;
    size_t		    map_height;
    int			    player_count;
	t_list		    *map_list;
    char	        **matrix;
    bool		minimap_bool;
    t_doors     doors_info;
    t_textures      textures[MAX_TEXTURES];
    t_mt    *objs;
}	t_map;

typedef struct s_render
{
    mlx_t		    *mlx;
    mlx_image_t		*img;
    int		        screen_width;
    int		        screen_height;
    // int		        angle;
	// int		        fps;
    t_mt	*objs;
}	t_render;

typedef struct	s_input
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
    t_render    render;
    t_input		input;
    bool		cursor_hidden;
    t_backup	*backup;
} t_game;



#endif /* TYPES_H */
