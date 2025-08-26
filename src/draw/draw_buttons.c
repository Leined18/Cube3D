/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD:src/check/check_ok.c
/*   check_ok.c                                         :+:      :+:    :+:   */
=======
/*   draw_buttons.c                                     :+:      :+:    :+:   */
>>>>>>> main:src/draw/draw_buttons.c
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:src/check/check_ok.c
/*   Created: 2025/05/29 10:13:20 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/21 15:16:11 by mvidal-h         ###   ########.fr       */
=======
/*   Created: 2025/08/06 09:51:08 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 11:00:11 by danpalac         ###   ########.fr       */
>>>>>>> main:src/draw/draw_buttons.c
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_draw_buttons(t_game *game)
{
<<<<<<< HEAD:src/check/check_ok.c
	if (strlen(dir) == 1
		&& (dir[0] == 'N'
			|| dir[0] == 'S'
			|| dir[0] == 'E'
			|| dir[0] == 'W'))
		return (1);
	return (0);
=======
	int	i;

	if (!game)
		return (0);
	i = -1;
	while (++i < 2)
		ft_draw_button(game->render.mlx, &game->render.buttons[i]);
	return (1);
>>>>>>> main:src/draw/draw_buttons.c
}
