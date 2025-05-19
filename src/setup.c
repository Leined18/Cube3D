#include "cube3d.h"


t_render *create_render(t_game *game)
{
    t_render	*render;

    render = ft_calloc(1, sizeof(t_render));
    if (!render)
        return (NULL);
    render->width = 1920;
    render->height = 1080;
    render->fov = 60;
    render->angle = 0;
    render->data_count = 0;
    render->backup = game->backup;
    return (render);
}

t_map *create_map(t_game *game)
{
    t_map	*map;

    map = ft_calloc(1, sizeof(t_map));
    if (!map)
        return (NULL);
    map->width = 0;
    map->height = 0;
    map->backup = game->backup;
    return (map);
}

t_player *create_player(t_game *game)
{
    t_player	*player;

    player = ft_calloc(1, sizeof(t_player));
    if (!player)
        return (NULL);
    player->name = NULL;
    player->pos.x = 0;
    player->pos.y = 0;
    player->pos.z = 0;
    player->angle = 0;
    player->backup = game->backup;
    return (player);
}

mlx_t *create_mlx(t_render *render, char *title)
{
    mlx_t	*mlx;

    mlx = mlx_init(render->width, render->height, title, true);
    if (!mlx)
        return (NULL);
    return (mlx);
}

int	setup(t_game **game, char *map)
{
	if (!game || !map)
		return (0);
	(*game) = ft_calloc(1, sizeof(t_game));
	if (!(*game))
		return (cleanup(game), 0);
    (*game)->backup = ft_backup_new(70);
    (*game)->objs = ft_mtnew2("game", *game, &(*game)->backup);
	(*game)->map = create_map(*game);
    (*game)->player = create_player(*game);
    (*game)->render = create_render(*game);
    (*game)->mlx = create_mlx((*game)->render, "Cube3D");
	if (!(*game)->map || !(*game)->player || !(*game)->render 
		|| !(*game)->mlx || !(*game)->objs || !(*game)->backup)
		return (cleanup(game), 0);
	return (1);
}
