/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:48:59 by danpalac          #+#    #+#             */
/*   Updated: 2025/07/16 15:37:54 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft.h"
# include "methods.h"
# include "MLX42.h"
# include "mt.h"
# include "types.h"
# include "utils.h"
#include <sys/time.h>

# define    TITLE "Cube3D"
# define    TILE_SIZE 64
# define    FPS 60

// Macros
# define TOGGLE(x) ((x) = !(x))

//configuration 
# define    TEXTURES true
# define    MINIMAP true
# define    DEBUG false
# define    MAX_BUTTONS 10
# define    MINIMAP_SCALE 0.2  // escala respecto al mapa real
# define    MINIMAP_WIDTH_OFFSET 550 // ancho extra para el minimapa
# define    MINIMAP_HEIGHT_OFFSET 550 // alto extra para el minimapa
# define    MINIMAP_MAX_RATIO 0.25 // ratio máximo del minimapa respecto al tamaño del mapa


//window configuration
# define	STRETCH_IMAGE	true
# define	FULLSCREEN		false

// Player configuration
# define	PLAYER_SPEED 3.0
# define	PLAYER_RUN_SPEED 2.0 * PLAYER_SPEED
# define	PLAYER_ROTATION_SPEED 1.5
# define	MOUSE_ROTATION_SPEED 0.05
# define    FOV_DEGREES 77.0
# define	MARGIN_WALL 0.2 // Margin representing the body space of the player, used to avoid collisions with walls

// Door configuration
# define	DOOR_SYMBOL 'D' // Symbol representing a door in the map
# define    DOOR_ANIM_TIME 3 // segundos
# define    DOOR_OPEN_TIME 5.0 // segundos

// Raycasting configuration
#define     SCREEN_WIDTH 1920
#define     SCREEN_HEIGHT 1080
#define     MAX_PITCH PI / 2
# define    MIN_PITCH -PI / 2

// Macros
# define TOGGLE(x) ((x) = !(x))

# define    ASSESTS_PATH "./assets/"
# define    TEXTURE_NO ASSESTS_PATH "textures/no.png"
# define    TEXTURE_SE ASSESTS_PATH "textures/se.png"
# define    TEXTURE_WE ASSESTS_PATH "textures/we.png"
# define    TEXTURE_EA ASSESTS_PATH "textures/ea.png"
# define    TEXTURE_F  ASSESTS_PATH "textures/f.png"
# define    TEXTURE_C  ASSESTS_PATH "textures/c.png"


#endif