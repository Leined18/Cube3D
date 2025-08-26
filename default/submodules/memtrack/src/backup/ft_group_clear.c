/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:03:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:43:23 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_group_clear(t_group **group, bool free_data)
{
	t_group	*current;
	t_group	*next;

	if (!group || !*group)
		return ;
	current = *group;
	while (current)
	{
		next = current->next;
		if (free_data)
			ft_track_clear(&current->head, true);
		ft_group_free(&current, free_data);
		current = next;
	}
	*group = NULL;
}
