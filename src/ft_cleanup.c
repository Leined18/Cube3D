
#include "cube3d.h"



void ft_cleanup_player(t_player *player)
{
	if (!player)
		return;
	(void)player;
}

void ft_cleanup_render(t_render *render)
{
	if (render->mlx)
	{
		if (render->img)
			mlx_delete_image(render->mlx, render->img);
		mlx_close_window(render->mlx);
		mlx_terminate(render->mlx);
	}
}


void ft_cleanup(t_game *game)
{
	ft_cleanup_map(&game->map);
	ft_cleanup_player(&game->player);
	ft_cleanup_render(&game->render);
	ft_backup_static(0, false, true);
	ft_successful("Game cleaned up successfully\n", 1);
}