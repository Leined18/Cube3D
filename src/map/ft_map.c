/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:48:03 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/25 11:18:00 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

size_t ft_get_width(char **map, size_t height)
{
    size_t	width;
    size_t length;
    size_t	i;

    if (!map || height <= 0)
        return (0);
    i = 0;
    width = 0;
    while (i < height && map[i])
    {
        length = ft_strlen(map[i]);
        if (length > width)
            width = length;
        i++;
    }
    return (width);
}

/**
  * ft_read_map.c
  * @file ft_map.c
  * @brief Functions for reading the map from a file.
  * 
  * This file contains functions to read a map from a file and store it in a 2D array.
*/

char **ft_read_map(int fd, size_t *height)
{
    char	**map;
    char	*line;
    
    map = NULL;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        if (ft_strlen(line) > 0 && line[0] != '\n')
        {
            map = ft_realloc(map, (*height) * sizeof(char *),
            ((*height) + 2) * sizeof(char *));
            if (!map)
                return (free(line), NULL);
            map[(*height)] = ft_strdup(line);
            map[(*height)][ft_strlen(map[(*height)]) - 1] = '\0'; // Remove newline character
            (*height) += 1;
            free(line);
        }
        else
            free(line);
    }
    map[*height] = NULL;
    return (map);
}



/**
    * ft_load_map.c
    * @file ft_map.c
    * @brief Functions for managing the map structure in the Cube3D game.
    * * This file contains functions to load a map from a file, create a new map structure,
*/


char **ft_load_map(const char *path, size_t *width, size_t *height)
{
    char	**map;
    int		fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (NULL);
    map = ft_read_map(fd, height);
    *width = ft_get_width(map, *height);
    return (close(fd), map);
}

/** * Creates a new map structure.
 * 
 * @return A pointer to the newly created map structure, or NULL on failure.
 * @path The path to the map file.
 */

int ft_set_map(t_map *map)
{
    // ft_bzero(map, sizeof(t_map));
    // map->matrix = ft_load_map(path, &map->map_width, &map->map_height);
    // if (!map->matrix)
    //     return (0);
    if (!ft_init_textures(map))
        return (ft_cleanup_map(map), 0);
    ft_mtnew("map", "map_width")->data = &map->map_width;
    ft_mtnew("map", "map_height")->data = &map->map_height;
    ft_mtnew("map", "map_struct")->data = &map;
    return (1);
}


