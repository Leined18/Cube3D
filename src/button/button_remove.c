/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:56:47 by daniel            #+#    #+#             */
/*   Updated: 2025/08/06 11:00:50 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/**
 * Frees the button structure and its associated images.
 * This function does not remove the button from the render,
	it just frees its resources.
 * If you want to reuse the button, you need to create a new image.
 *
 * @param mlx The mlx instance.
 * @param btn The button to free.
 */

void	ft_free_button(mlx_t *mlx, t_button *btn)
{
	if (!mlx || !btn || !btn->img)
		return ;
	if (btn->label)
		free(btn->label);
	if (btn->img)
		mlx_delete_image(mlx, btn->img);
	if (btn->label_img)
		mlx_delete_image(mlx, btn->label_img);
	ft_bzero(btn, sizeof(t_button));
}

void	ft_remove_button(mlx_t *mlx, t_button *btn)
{
	if (!mlx || !btn || !btn->img)
		return ;
	if (btn->img)
		mlx_delete_image(mlx, btn->img);
	if (btn->label_img)
		mlx_delete_image(mlx, btn->label_img);
	btn->img = NULL;
	btn->label_img = NULL;
	get_button_image(mlx, btn);
	btn->active = false;
}

/**
 * Removes all buttons from the render, freeing their resources.
 * This function does not free the button structure itself,
	it just frees its resources.
 * If you want to reuse the buttons, you need to draw them again.
 *
 * @param mlx The mlx instance.
 * @param render The render structure containing the buttons.
 */

void	ft_remove_all_buttons(mlx_t *mlx, t_render *render)
{
	int	i;

	if (!mlx || !render)
		return ;
	i = -1;
	while (++i < render->button_count)
		ft_remove_button(mlx, &render->buttons[i]);
}

/**
 * Frees all buttons in the render, including their images and labels.

	* This function iterates through all buttons
 * for each one, then resets the button count to 0.
 *
 * @param mlx The mlx instance.
 * @param render The render structure containing the buttons.
 */

void	ft_free_all_buttons(mlx_t *mlx, t_render *render)
{
	int	i;

	if (!mlx || !render)
		return ;
	i = -1;
	while (++i < render->button_count)
		ft_free_button(mlx, &render->buttons[i]);
	render->button_count = 0;
}
