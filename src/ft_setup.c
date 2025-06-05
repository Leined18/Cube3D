#include "cube3d.h"


t_render *ft_create_render(void)
{
    t_render	*render;

    render = ft_calloc(1, sizeof(t_render));
    if (!render)
        return (NULL);
    render->width = 1920;
    render->height = 1080;
    render->fov = 60;
    render->angle = 0;
    ft_mtnew("render")->data = render;
    return (render);
}

t_player *ft_create_player(void)
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
    ft_mtnew("player")->data = player;
    return (player);
}

mlx_t *ft_create_mlx(void)
{
    mlx_t	*mlx;
    t_render	*render;

    render = (t_render *)ft_mtget("render")->data;
    if (!render)
        return (NULL);
    mlx = mlx_init(render->width, render->height, TITLE, true);
    if (!mlx)
        return (NULL);
    ft_mtnew("mlx")->data = mlx;
    return (mlx);
}

int	ft_setup(t_game **game, char *map_file)
{
	if (!game || !map_file)
		return (0);

	(*game) = ft_calloc(1, sizeof(t_game));
    if (!(*game))
        return (0);
    (*game)->backup = ft_backup_static(1, true, false);
    if (!(*game)->backup)
        return (ft_cleanup(game), 0);
    (*game)->map = ft_create_map(map_file);
    (*game)->player = ft_create_player();
    (*game)->render = ft_create_render();
    (*game)->mlx = ft_create_mlx();
	if (!(*game))
		return (ft_cleanup(game), 0);
	if (!(*game)->map || !(*game)->player || !(*game)->render 
		|| !(*game)->mlx || !(*game)->backup)
		return (ft_cleanup(game), 0);
	return (1);
}
