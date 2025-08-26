/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_search_mt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:08:54 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:36:39 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_slot_search_mt - Busca un nodo en los slots por su clave.
 * @slots: Doble puntero a la lista de slots.
 * @slot_count: Número de slots en la lista.
 * @key: Clave del nodo a buscar.
 *
 * Retorna el nodo encontrado o NULL si no se encuentra.
 */

t_mt	*ft_slot_search_mt(t_slot **slots, size_t slot_count, const char *key)
{
	size_t	i;
	t_slot	*slot;
	t_slot	*found;

	if (!slots || slot_count == 0 || !key)
		return (NULL);
	i = 0;
	while (i < slot_count)
	{
		slot = slots[i];
		while (slot)
		{
			found = ft_slot_search(slot, key);
			if (found)
				return (found->node);
			slot = slot->top;
		}
		i++;
	}
	return (NULL);
}
