/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:44:06 by danpalac          #+#    #+#             */
<<<<<<< HEAD:src/hooks/ft_key_hook.c
/*   Updated: 2025/08/21 15:30:31 by mvidal-h         ###   ########.fr       */
=======
/*   Updated: 2025/08/06 10:14:47 by danpalac         ###   ########.fr       */
>>>>>>> main:src/hooks/ft_hooks_key.c
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_on_keypress(mlx_key_data_t keydata, void *param)
{
	t_game	*g;
	bool	pressed;

	g = (t_game *)param;
	pressed = (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT);
	if (keydata.key == MLX_KEY_W)
		g->input.move_forward = pressed;
	if (keydata.key == MLX_KEY_S)
		g->input.move_backward = pressed;
	if (keydata.key == MLX_KEY_A)
		g->input.move_left = pressed;
	if (keydata.key == MLX_KEY_D)
		g->input.move_right = pressed;
	if (keydata.key == MLX_KEY_LEFT)
		g->input.rotate_left = pressed;
	if (keydata.key == MLX_KEY_RIGHT)
		g->input.rotate_right = pressed;
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
		process_key(g, keydata);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		process_key(g, keydata);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
<<<<<<< HEAD:src/hooks/ft_key_hook.c
	{
		ft_printf("Bye!\n");
		ft_cleanup(g);
	}
=======
		process_key(g, keydata);
>>>>>>> main:src/hooks/ft_hooks_key.c
}
