/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:59:10 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:43:02 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_group_free(t_group **group, bool free_data)
{
	t_group	*current;

	if (!group || !*group)
		return ;
	current = *group;
	if (current->id)
		free(current->id);
	if (current->head && free_data)
		ft_track_clear(&current->head, true);
	free(current);
	*group = NULL;
}
