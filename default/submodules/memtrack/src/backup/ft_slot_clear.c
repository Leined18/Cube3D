/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:09:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:41:56 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_slot_clear(t_slot **slots, size_t slot_count, bool free_data)
{
	size_t	i;
	t_slot	*current;
	t_slot	*next;

	if (!slots || slot_count == 0)
		return ;
	i = 0;
	while (i < slot_count)
	{
		current = slots[i];
		while (current)
		{
			next = current->top;
			ft_slot_free(&current, free_data);
			current = next;
		}
		slots[i] = NULL;
		i++;
	}
	free(slots);
}
