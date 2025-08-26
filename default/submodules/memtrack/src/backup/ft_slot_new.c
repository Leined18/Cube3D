/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:15:44 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:40:10 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_slot_new - Crea un nuevo slot.
 * @id: ID del slot.
 * @group_id: ID del grupo al que pertenece el slot.
 *
 * Retorna un puntero al nuevo slot o NULL si falla la asignación.
 */

t_slot	*ft_slot_new(const char *id, const char *group_id, t_mt *node)
{
	t_slot	*slot;

	if (!id || !group_id)
		return (NULL);
	slot = ft_calloc(1, sizeof(t_slot));
	if (!slot)
		return (NULL);
	slot->id = ft_strdup(id);
	if (!slot->id)
		return (free(slot), NULL);
	slot->group_id = ft_strdup(group_id);
	if (!slot->group_id)
		return (free(slot->id), free(slot), NULL);
	slot->top = NULL;
	slot->node = node;
	return (slot);
}
