/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:29:23 by daniel            #+#    #+#             */
/*   Updated: 2025/07/09 11:37:47 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// #define TILE_SIZE 64
// #define MINIMAP_MAX_SIZE 200

// double ft_compute_minimap_scale(t_map *map) {
//     double map_pixel_width  = map->map_width  * TILE_SIZE;
//     double map_pixel_height = map->map_height * TILE_SIZE;
//     double scale_x = MINIMAP_MAX_SIZE / map_pixel_width;
//     double scale_y = MINIMAP_MAX_SIZE / map_pixel_height;

//     return (scale_x < scale_y) ? scale_x : scale_y;
// }
// Luego en ft_create_minimap:
//     minimap.scale = ft_compute_minimap_scale(map);


double	ft_calc_scale(int map_width, int map_height)
{
	double	map_pixel_width;
	double	map_pixel_height;
	double	max_width;
	double	max_height;
	double	scale_x;
	double	scale_y;

	if (map_width <= 0 || map_height <= 0)
		return (1.0);
	map_pixel_width = map_width * TILE_SIZE;
	map_pixel_height = map_height * TILE_SIZE;
	max_width = SCREEN_WIDTH * MINIMAP_MAX_RATIO;
	max_height = SCREEN_HEIGHT * MINIMAP_MAX_RATIO;
	scale_x = max_width / map_pixel_width;
	scale_y = max_height / map_pixel_height;
	return (fmin(scale_x, scale_y));
}

t_minimap	ft_create_minimap(t_map *map)
{
	t_minimap	minimap;
	double		scale;

	if (!map)
		return ((t_minimap){0});
	ft_bzero(&minimap, sizeof(t_minimap));
	scale = ft_calc_scale(map->map_width, map->map_height);
	minimap.width = ceil(map->map_width * TILE_SIZE * scale) + 1;
	minimap.height = ceil(map->map_height * TILE_SIZE * scale) + 1;
	minimap.scale = scale;
	minimap.enabled = MINIMAP;
	minimap.img = mlx_new_image(
			ft_mtget("mlx")->data,
			minimap.width,
			minimap.height);
	if (!minimap.img)
		return ((t_minimap){0});
	return (minimap);
}