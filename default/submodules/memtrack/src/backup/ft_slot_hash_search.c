/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_hash_search.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:42:01 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:41:11 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_slot_hash_search - Busca un slot en la lista de slots por su clave.
 * @slots: Doble puntero a la lista de slots.
 * @slot_count: Número de slots en la lista.
 * @key: Clave del slot a buscar.
 *
 * Retorna el slot encontrado o NULL si no se encuentra.
 */

t_slot	*ft_slot_hash_search(t_slot **slots, size_t slot_count, const char *key)
{
	size_t	i;
	t_slot	*found;

	if (!slots || slot_count == 0 || !key)
		return (NULL);
	i = 0;
	found = NULL;
	while (i < slot_count)
	{
		found = ft_slot_search(slots[i], key);
		if (found)
			return (found);
		i++;
	}
	return (NULL);
}
