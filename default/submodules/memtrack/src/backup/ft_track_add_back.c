/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_track_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:29:01 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:35:03 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_track_add_back(t_track **node, t_track *new_node)
{
	t_track	*current;

	if (!node || !new_node)
		return (0);
	if (!*node)
	{
		*node = new_node;
		return (1);
	}
	current = *node;
	while (current->next)
		current = current->next;
	current->next = new_node;
	return (1);
}
