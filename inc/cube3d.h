/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:48:59 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/21 16:13:42 by mvidal-h         ###   ########.fr       */
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

# define TITLE "Cube3D"
# define TILE_SIZE 64
# define FPS 60

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

#endif