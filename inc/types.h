/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:39:44 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/18 17:40:55 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H


# include "MLX42.h"
# include "libft.h"
# include "methods.h"
# include "mt.h"
# include "utils.h"

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
    double  	x;
    double  	y;
}	t_vector;

typedef struct	s_screenline
{
	int			    start;
	int			    end;
	uint32_t	    color_wall;
	uint32_t	    *color_floor;
	uint32_t	    *color_ceiling;
    mlx_texture_t	*texture;	// Textura del muro
    mlx_texture_t	*texture_floor; // Textura del suelo
    mlx_texture_t	*texture_ceiling; // Textura del techo
}				t_screenline;

typedef struct	s_ray
{
	double			cameraX;		//Normalizacion de las columnas de pixels de la pantalla (-1 .. 0 .. 1)
	t_vector		dir;			//vector que indica la direccion a donde va el rayo.
    t_vector		map;			// posición actual en la grid/mapa
	t_vector		delta_dist;		// distancia a recorrer para pasar a la siguiente línea X o Y
	t_vector		side_dist;		// distancia acumulada desde el origen del rayo a la próxima línea X o Y
    t_vector		step;			// dirección de incremento en X e Y
	int				side;			// 0 si el muro es vertical, 1 si horizontal
	int				hit;			// 0 si aun no ha chocado con un muro, 1 si ha chocado.
	double			perpWallDist;	// distancia corregida hasta la pared perpendicular a plane.
	t_screenline	draw;			// inicio y final de pintado de una linea de pantalla respecto a la distancia del muro.
}				t_ray;


typedef struct	s_textures
{
	char	        *path;
    mlx_texture_t 	*texture;
    uint32_t	    color;
}				t_textures;

typedef struct s_player
{
    t_vector            pos;
    t_vector            dir;
    t_vector            plane;
    double		        fov_degrees;
	double		        fov_factor;
    double		        movspeed;
    double		        rotspeed;
    t_mt       *objs;
}	t_player;

typedef struct s_map
{
    size_t		    map_width;
    size_t		    map_height;
    int			    player_count;
	t_list		    *map_list;
    char	        **matrix;
    bool		minimap_bool;
    t_textures      textures[TEXTURE_COUNT];
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
    t_backup	*backup;
} t_game;



#endif /* TYPES_H */
