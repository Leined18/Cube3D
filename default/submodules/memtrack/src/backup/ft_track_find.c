/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_track_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:16:17 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:38:27 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_track_find - Busca un nodo en la lista de seguimiento por su clave.
 * @track: Puntero a la lista de seguimiento.
 * @target: Puntero al nodo a buscar.
 *
 * Retorna el nodo encontrado o NULL si no se encuentra.
 */

t_track	*ft_track_find(t_track *track, t_track *target)
{
	t_track	*cur;

	if (!track || !target)
		return (NULL);
	cur = track;
	while (cur)
	{
		if (track == target)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}
