
#include "cube3d.h"

void	ft_free_textures(t_textures *textures)
{
	if (textures->NO)
		free(textures->NO);
	if (textures->SE)
		free(textures->SE);
	if (textures->WE)
		free(textures->WE);
	if (textures->EA)
		free(textures->EA);
	if (textures->F)
		free(textures->F);
	if (textures->C)
		free(textures->C);
	textures->NO = NULL;
	textures->SE = NULL;
	textures->WE = NULL;
	textures->EA = NULL;
	textures->F = NULL;
	textures->C = NULL;
}

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
	if (render->textures.F)
		free_null((void **)&render->textures.F);
	if (render->textures.C)
		free_null((void **)&render->textures.C);
}


void ft_cleanup(t_game *game)
{
	ft_cleanup_map(&game->map);
	ft_cleanup_player(&game->player);
	ft_cleanup_render(&game->render);
	if (game->backup)
		ft_backup_static(0, false, true);
	ft_successful("Game cleaned up successfully\n", 1);
}