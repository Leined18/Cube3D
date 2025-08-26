/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:44:41 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/21 16:24:50 by mvidal-h         ###   ########.fr       */
=======
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:01:01 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 11:01:06 by danpalac         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_cleanup_player(t_player *player)
{
	if (!player)
		return ;
	(void)player;
}

void	ft_cleanup_render(t_render *render)
{
	if (render->mlx)
	{
		if (render->img)
			mlx_delete_image(render->mlx, render->img);
		ft_free_all_buttons(render->mlx, render);
		mlx_close_window(render->mlx);
		mlx_terminate(render->mlx);
	}
}

void	ft_cleanup(t_game *game)
{
	ft_cleanup_map(&game->map);
	ft_cleanup_player(&game->player);
	ft_cleanup_render(&game->render);
	ft_backup_static(0, false, true);
	ft_successful("Game cleaned up successfully\n", 1);
}
