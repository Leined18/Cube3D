/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_track_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:36:14 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:34:48 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_track_free(t_track **track, bool free_node)
{
	t_track	*current;

	if (!track || !*track)
		return ;
	current = *track;
	if (current->group_id)
		free(current->group_id);
	if (current->id)
		free(current->id);
	if (current->node && free_node)
		ft_mtfree(current->node);
	free(current);
	*track = NULL;
}
