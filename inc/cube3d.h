/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:48:59 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/27 23:12:06 by daniel           ###   ########.fr       */
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

# define    TITLE "Cube3D"
# define    TILE_SIZE 64
# define    FPS 60

//configuration 
# define    TEXTURES true
# define    MINIMAP false
# define    DEBUG false
# define    MAX_BUTTONS 10


//window configuration
# define	STRETCH_IMAGE	true
# define	FULLSCREEN		false

// Player configuration
# define	PLAYER_SPEED 3.0
# define	PLAYER_ROTATION_SPEED 1.5
# define	MOUSE_ROTATION_SPEED 0.05
# define    FOV_DEGREES 77.0
# define	MARGIN_WALL 0.2 // Margin representing the body space of the player, used to avoid collisions with walls

// Raycasting configuration
#define     screenWidth 1920
#define     screenHeight 1080
#define     MAX_PITCH PI / 2
# define    MIN_PITCH -PI / 2


# define    ASSESTS_PATH "./assets/"
# define    TEXTURE_NO ASSESTS_PATH "textures/no.png"
# define    TEXTURE_SE ASSESTS_PATH "textures/se.png"
# define    TEXTURE_WE ASSESTS_PATH "textures/we.png"
# define    TEXTURE_EA ASSESTS_PATH "textures/ea.png"
# define    TEXTURE_F  ASSESTS_PATH "textures/f.png"
# define    TEXTURE_C  ASSESTS_PATH "textures/c.png"


#endif