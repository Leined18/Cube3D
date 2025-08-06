/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:18:21 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:26:34 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

mlx_t	*ft_create_mlx(t_render render)
{
	mlx_t	*mlx;

	if (render.screen_width <= 0 || render.screen_height <= 0)
		return (NULL);
	mlx_set_setting(MLX_STRETCH_IMAGE, STRETCH_IMAGE);
	mlx_set_setting(MLX_FULLSCREEN, FULLSCREEN);
	mlx = mlx_init(render.screen_width, render.screen_height, TITLE, true);
	if (!mlx)
		return (NULL);
	return (mlx);
}

int	ft_create_render(t_render *render)
{
	if (!render)
		return (0);
	ft_bzero(render, sizeof(t_render));
	render->screen_width = 1920;
	render->screen_height = 1080;
	render->mlx = ft_create_mlx(*render);
	ft_mtnew("config", "render")->data = render;
	ft_mtnew("config", "mlx")->data = render->mlx;
	return (1);
}

int	ft_create_player(t_player *player, t_map *map)
{
	if (!player)
		return (0);
	ft_init_player(player, map);
	player->fov_degrees = FOV_DEGREES;
	player->fov_factor = ft_calc_fov_factor(player->fov_degrees);
	player->plane = ft_calc_plane(player->dir, player->fov_factor);
	ft_mtnew("entity", "player")->data = &player;
	return (1);
}

int	ft_setup(t_game *game, char *map_file)
{
	if (!game || !map_file)
		return (0);
	ft_bzero(game, sizeof(t_game));
	if (parse_file(map_file, game) < 0)
		return (ft_printf("Error parsing %s\n", map_file), 0);
	if (init_doors(&game->map, &game->map.doors_info) < 0)
	{
		ft_printf("Error parsing doors\n");
		return (ft_cleanup(game), 0);
	}
	game->backup = ft_backup_static(1, true, false);
	if (!game->backup)
		return (ft_cleanup(game), 0);
	if (!ft_create_render(&game->render))
		return (ft_cleanup(game), 0);
	if (!ft_create_player(&game->player, &game->map))
		return (ft_cleanup(game), 0);
	if (!game->backup)
		return (ft_cleanup(game), 0);
	ft_mtnew("game", "game_struct")->data = game;
	if (!ft_create_buttons(&game->render))
		return (ft_cleanup(game), 0);
	if (!ft_set_map(&game->map))
		return (ft_cleanup(game), 0);
	return (1);
}
