/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:48:03 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/05 13:29:22 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/**
  * ft_read_map.c
  * @file ft_map.c
  * @brief Functions for reading the map from a file.
  * 
  * This file contains functions to read a map from a file and store it in a 2D array.
*/

char **ft_read_map(int fd, int *width, int *height)
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
            *width = ft_strlen(line);
            (*height)++;
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


char **ft_load_map(const char *path, int *width, int *height)
{
    char	**map;
    int		fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (NULL);
    *width = 0;
    *height = 0;
    map = ft_read_map(fd, width, height);
    if (map == NULL)
        return (close(fd), NULL);
    close(fd);
    if (*width <= 0 || *height <= 0)
        return (free_2d(&map), NULL);
    if (!map)
        return (NULL);
    return (map);
}

/** * Creates a new map structure.
 * 
 * @return A pointer to the newly created map structure, or NULL on failure.
 * @path The path to the map file.
 */

t_map *ft_create_map(const char *path)
{
    t_map	*map;

    map = ft_calloc(1, sizeof(t_map));
    if (!map)
        return (NULL);
    map->width = 0;
    map->height = 0;
    map->path = ft_strdup(path);
    if (!map->path)
        return (free(map), NULL);
    map->map_2d = ft_load_map(path, &map->width, &map->height);
    ft_mtnew("map")->data = map;
    return (map);
}

/** * Cleans up the map structure.
 * 
 * @param map A pointer to the map structure to clean up.
 */

void ft_cleanup_map(t_map **map)
{
    if (!map || !*map)
        return;
    if ((*map)->path)
        free_null((void **)&(*map)->path);
    if ((*map)->map_2d)
        free_2d((*map)->map_2d);
    free_null((void **)map);
}