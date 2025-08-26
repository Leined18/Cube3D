/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_track_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:34:40 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:34:33 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_track_remove(t_track **tracker, t_track *track, bool free_target)
{
	t_track	*current;
	t_track	*prev;

	if (!tracker || !*tracker)
		return (0);
	current = *tracker;
	prev = NULL;
	while (current)
	{
		if (current == track)
		{
			if (prev)
				prev->next = current->next;
			else
				*tracker = current->next;
			if (free_target)
				ft_track_free(&current, free_target);
			else
				current->next = NULL;
			return (1);
		}
		prev = current;
		current = current->next;
	}
	return (0);
}
