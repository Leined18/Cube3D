/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:14:57 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:36:44 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_slot_search - Busca un slot en la lista de slots por su clave.
 * @slots: Doble puntero a la lista de slots.
 * @slot_count: Número de slots en la lista.
 * @key: Clave del slot a buscar.
 *
 * Retorna el slot encontrado o NULL si no se encuentra.
 */

t_slot	*ft_slot_search(t_slot *slot, const char *key)
{
	t_slot	*found;

	if (!slot || !key)
		return (NULL);
	found = slot;
	while (found)
	{
		if (ft_strequ(found->id, key))
			return (found);
		found = found->top;
	}
	return (NULL);
}
