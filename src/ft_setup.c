/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:18:21 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/16 15:46:49 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

mlx_t *ft_create_mlx(t_render render)
{
    mlx_t	*mlx;

    if (render.screen_width <= 0 || render.screen_height <= 0)
        return (NULL);
    mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_set_setting(MLX_FULLSCREEN, true);
    mlx = mlx_init(render.screen_width, render.screen_height, TITLE, true);
    if (!mlx)
        return (NULL);
    return (mlx);
}

int ft_create_render(t_render *render)
{
    int         width;
    int         height;

    ft_bzero(render, sizeof(t_render)); 
    width = *(int *)ft_mtget("map_width")->data;
    height = *(int *)ft_mtget("map_height")->data;
    if (width <= 0 || height <= 0)
        return (0);
    render->screen_width = 1920; // Adjust width based on TILE_SIZE
    render->screen_height = 1080; // Adjust height based on TILE_SIZE
    render->mlx = ft_create_mlx(*render);
    ft_mtnew("config", "render")->data = render;
    return (1);
}

int ft_create_player(t_player *player)
{
	if (!player)
		return (0);
    player->fov_degrees = 60;
    player->fov_factor = ft_calc_fov_factor(player->fov_degrees);
    player->plane = ft_calc_plane(player->dir, player->fov_factor);
    ft_mtnew("entity","player")->data = &player;
    return (1);
}



int	ft_setup(t_game *game, char *map_file)
{
	if (!game || !map_file)
		return (0);
    ft_bzero(game, sizeof(t_game));
	game->backup = ft_backup_static(1, true, false);
	if (!game->backup)
		return (ft_cleanup(game), 0);
	if (!ft_create_map(map_file, &game->map))
		return (ft_cleanup(game), 0);
    ft_init_player(&game->player, &game->map);
	if (!ft_create_player(&game->player))
		return (ft_cleanup(game), 0);
    if (!ft_create_render(&game->render))
		return (ft_cleanup(game), 0);
	if (!game->backup)
		return (ft_cleanup(game), 0);
    ft_mtnew("game", "game_struct")->data = game;
	return (1);
}
