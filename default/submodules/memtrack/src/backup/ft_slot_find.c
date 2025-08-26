/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:17:56 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:41:40 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_slot_find - Busca un nodo en los slots del backup.
 * @slots: Puntero a la lista de slots.
 * @slot_count: Número de slots.
 * @target: Puntero al nodo a buscar.
 *
 * Retorna el nodo encontrado o NULL si no se encuentra.
 */

t_slot	*ft_slot_find(t_slot **slots, size_t slot_count, t_slot *target)
{
	size_t	i;
	t_slot	*cur;

	if (!slots || slot_count == 0 || !target)
		return (NULL);
	i = 0;
	while (i < slot_count)
	{
		cur = slots[i];
		while (cur)
		{
			if (cur == target)
				return (cur);
			cur = cur->top;
		}
		i++;
	}
	return (NULL);
}
