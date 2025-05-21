#include "cube3d.h"


t_render *create_render(t_backup *backup)
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
    render->backup = backup;
    return (render);
}

t_map *create_map(t_backup *backup)
{
    t_map	*map;

    map = ft_calloc(1, sizeof(t_map));
    if (!map)
        return (NULL);
    map->width = 0;
    map->height = 0;
    map->backup = backup;
    return (map);
}

t_player *create_player(t_backup *backup)
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
    player->backup = backup;
    return (player);
}

mlx_t *create_mlx(t_render *render, char *title)
{
    mlx_t	*mlx;

    mlx = mlx_init(render->width, render->height, title, true);
    if (!mlx)
        return (NULL);
    free(render);
    return (mlx);
}

int	setup(t_game **game, char *map)
{
	if (!game || !map)
		return (0);
    t_backup *backup;

    backup = ft_backup_new(10);
	(*game) = constructor(c_game, "map%render%mlx%player%backup",
        create_map(backup),
        create_render(backup),
        create_mlx(create_render(backup), "Cube3D"),
        create_player(backup), backup);
	if (!(*game))
		return (ft_backup_clear(&backup), 0);
	if (!(*game)->map || !(*game)->player || !(*game)->render 
		|| !(*game)->mlx || !(*game)->backup)
		return (cleanup(game), 0);
	return (1);
}
