/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:48:59 by danpalac          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/22 15:25:48 by mvidal-h         ###   ########.fr       */
=======
/*   Updated: 2025/08/21 10:35:33 by mvidal-h         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "MLX42.h"
# include "libft.h"
# include "methods.h"
# include "mt.h"
# include "types.h"
<<<<<<< HEAD
=======
# include <sys/time.h>
>>>>>>> main

# define TITLE "Cube3D"
# define TILE_SIZE 64
# define FPS 60

<<<<<<< HEAD
//configuration
# define TEXTURES true
# define MINIMAP false
# define DEBUG false

// Player configuration
# define PLAYER_SPEED 4.3
# define PLAYER_ROTATION_SPEED 2.05
# define FOV_DEGREES 77.0
# define MARGIN_WALL 0.2

// Raycasting configuration
# define SCRWIDTH 1920
# define SCRHEIGHT 1080

# define TEXTURE_NO "./assets/textures/no.png"
# define TEXTURE_SE "./assets/textures/se.png"
# define TEXTURE_WE "./assets/textures/we.png"
# define TEXTURE_EA "./assets/textures/ea.png"
# define TEXTURE_F "./assets/textures/f.png"
# define TEXTURE_C "./assets/textures/c.png"
=======
// configuration
# define TEXTURES true
# define MINIMAP true
# define DEBUG false
# define MAX_BUTTONS 10
# define MINIMAP_SCALE 0.2         // escala respecto al mapa real
# define MINIMAP_WIDTH_OFFSET 550  // ancho extra para el minimapa
# define MINIMAP_HEIGHT_OFFSET 550 // alto extra para el minimapa
# define MINIMAP_MAX_RATIO 0.25
// ratio máximo del minimapa respecto al tamaño del mapa

// window configuration
# define STRETCH_IMAGE true
# define FULLSCREEN false

// Player configuration
# define PLAYER_SPEED 3.0
# define PLAYER_RUN_SPEED 6.0
# define PLAYER_ROTATION_SPEED 1.5
# define MOUSE_ROTATION_SPEED 0.05
# define FOV_DEGREES 77.0
# define MARGIN_WALL 0.2 // Margin representing the body space of the player
// used to avoid collisions with walls

// Door configuration
# define DOOR_SYMBOL 'D'    // Symbol representing a door in the map
# define DOOR_ANIM_TIME 3   // segundos
# define DOOR_OPEN_TIME 5.0 // segundos

// MINIMAP
# define MINIMAP_MAX_RATIO 0.25
// ratio máximo del minimapa respecto al tamaño del mapa
# define MINIMAP_THICKNESS 1
// Grosor de los rayos del minimapa
# define MINIMAP_GRANULARITY_LINE 5
// Espacio entre líneas del minimapa
# define MINIMAP_COLOR_LINE 0xE5E8E8FF
// Color of the minimap lines
# define MINIMAP_COLOR_PLAYER 0x9B59B6FF
// Color of the minimap player
# define MINIMAP_COLOR_WALL 0x17202AFF
// Color of the minimap walls
# define MINIMAP_COLOR_DOOR 0xD4AC0DFF
// Color of the minimap doors
# define MINIMAP_COLOR_EMPTY 0x000000
// Color of the minimap empty spaces (' ')
# define MINIMAP_COLOR_FLOOR 0x707B7CFF
// Color of the minimap floors ('0')

// Button configuration
# define BUTTON_COLOR_EXIT 0xF0000FFF
// color of the exit button
# define BUTTON_COLOR_START 0x00FF00FF
// color of the start button
# define BUTTON_COLOR_MINIMAP 0x0000FFFF
// color of the minimap button

// Raycasting configuration
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
>>>>>>> main

#endif