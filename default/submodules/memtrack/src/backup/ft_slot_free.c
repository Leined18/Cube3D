/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:57:30 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:41:37 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_slot_free(t_slot **slot, bool free_data)
{
	t_slot	*current;

	if (!slot || !*slot)
		return ;
	current = *slot;
	if (current->id)
		free(current->id);
	if (current->group_id)
		free(current->group_id);
	if (current->node && free_data)
		ft_mtfree(current->node);
	free(current);
	*slot = NULL;
}
