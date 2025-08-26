/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:41:22 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:41:27 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_slot_search - Busca un slot en la lista de slots por su clave.
 * @slot: Puntero al primer nodo de la lista de slots.
 * @key: Clave del slot a buscar.
 *
 * Retorna el slot encontrado o NULL si no se encuentra.
 */

t_slot	*ft_slot_search(t_slot *slot, const char *key)
{
	if (!slot || !key)
		return (NULL);
	while (slot)
	{
		if (ft_strequ(slot->id, key) || (slot->node && ft_strequ(slot->node->id,
					key)))
			return (slot);
		slot = slot->top;
	}
	return (NULL);
}
