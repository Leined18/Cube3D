
#include "cube3d.h"

void ft_cleanup_player(t_player **player)
{
	if ((*player)->name)
		free_null((void **)&(*player)->name);
	free_null((void **)player);
}

void ft_cleanup_render(t_render **render)
{
	free_null((void **)render);
}


void ft_cleanup(t_game **game)
{
	if ((*game)->mlx)
		mlx_terminate((*game)->mlx);
	if ((*game)->map)
		ft_cleanup_map(&(*game)->map);
	if ((*game)->player)
		ft_cleanup_player(&(*game)->player);
	if ((*game)->render)
		ft_cleanup_render(&(*game)->render);
	if ((*game)->backup)
		ft_backup_static(0, false, true);
	free_null((void **)game);
	ft_successful("Game cleaned up successfully\n", 1);
}