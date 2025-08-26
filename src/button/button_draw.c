/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:src/hooks/ft_hooks_utils.c
/*   Created: 2025/06/09 11:04:11 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/21 15:34:47 by mvidal-h         ###   ########.fr       */
=======
/*   Created: 2025/06/27 13:18:46 by daniel            #+#    #+#             */
/*   Updated: 2025/08/06 10:10:55 by danpalac         ###   ########.fr       */
>>>>>>> main:src/button/button_draw.c
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

<<<<<<< HEAD:src/hooks/ft_hooks_utils.c
void	ft_handle_input(t_game *g, double moveSpeed, double rotSpeed)
{
	if (g->input.move_forward)
		move_player_forward(g, moveSpeed);
	if (g->input.move_backward)
		move_player_backward(g, moveSpeed);
	if (g->input.move_left)
		strafe_player_left(g, moveSpeed);
	if (g->input.move_right)
		strafe_player_right(g, moveSpeed);
	if (g->input.rotate_left)
		rotate_player(g, -rotSpeed);
	if (g->input.rotate_right)
		rotate_player(g, rotSpeed);
=======
/**
 * funtion to draw a single button.
 */

void	ft_draw_button(mlx_t *mlx, t_button *btn)
{
	int	x;
	int	y;

	if (!mlx || !btn || !btn->img)
		return ;
	x = btn->x + btn->width / 2;
	y = btn->y + btn->height / 2;
	if (btn->img)
	{
		mlx_image_to_window(mlx, btn->img, btn->x, btn->y);
		if (btn->label)
			btn->label_img = mlx_put_string(mlx, btn->label, x
					- (ft_strlen(btn->label) * 5), y - 10);
	}
	btn->active = true;
>>>>>>> main:src/button/button_draw.c
}
