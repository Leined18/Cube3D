/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:39:44 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/20 11:40:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H


# include "MLX42.h"
# include "libft.h"
# include "methods.h"
# include "mt.h"
# include "utils.h"

typedef struct s_player
{
    char       *name;
    t_cords    pos;
    t_offset   offset;
    int	       angle;
    t_mt       *objs;
    t_backup   *backup;
}	t_player;

typedef struct s_map
{
    char	**map;
    int		width;
    int		height;
    t_mt    *objs;
    t_backup *backup;
}	t_map;

typedef struct s_render
{
    int		width;
    int		height;
    int		fov;
    int		angle;
    int		data_count;
    t_mt    *objs;
    t_backup *backup;
}	t_render;

typedef struct s_game
{
    mlx_t		*mlx;
    t_map		*map;
    t_player	*player;
    t_render    *render;
    t_mt		*objs;
    t_backup    *backup;
} t_game;



#endif /* TYPES_H */
