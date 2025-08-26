/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_track_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:36:04 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:38:22 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_search_track
	- Obtiene un nodo de la lista de seguimiento del backup.
 * @track: Puntero a la lista de seguimiento del backup.
 * @key: Clave del nodo a buscar.
 *
 * Retorna el nodo encontrado o NULL si no se encuentra.
 */

t_track	*ft_track_search(t_track *track, const char *key)
{
	t_track	*cur;

	if (!track || !key)
		return (NULL);
	cur = track;
	while (cur)
	{
		if (cur->group_id && ft_strequ(cur->group_id, key))
			return (cur);
		else if (cur->id && ft_strequ(cur->id, key))
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}
