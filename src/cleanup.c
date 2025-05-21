
#include "cube3d.h"

void cleanup_map(t_map **map)
{
	if ((*map)->map)
		free_2d(&(*map)->map);
	free_null((void **)map);
}

void cleanup_player(t_player **player)
{
	if ((*player)->name)
		free_null((void **)&(*player)->name);
	free_null((void **)player);
}

void cleanup_render(t_render **render)
{
	free_null((void **)render);
}

void cleanup_backup(t_backup **backup)
{
    t_backup *backup_copy;

    backup_copy = *backup;
	ft_backup_clear(&backup_copy);
}


void cleanup(t_game **game)
{
	if ((*game)->mlx)
		mlx_terminate((*game)->mlx);
	if ((*game)->map)
		cleanup_map(&(*game)->map);
	if ((*game)->player)
		cleanup_player(&(*game)->player);
	if ((*game)->render)
		cleanup_render(&(*game)->render);
	if ((*game)->backup)
		cleanup_backup(&(*game)->backup);
	free_null((void **)game);
}