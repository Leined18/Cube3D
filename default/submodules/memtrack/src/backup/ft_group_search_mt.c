/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group_search_mt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:07:07 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:42:38 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_group_search_mt - Busca un grupo en la lista de grupos por su ID.
 * @groups: Doble puntero a la lista de grupos.
 * @id: ID del grupo a buscar.
 *
 * Retorna el grupo encontrado o NULL si no se encuentra.
 */

t_mt	*ft_group_search_mt(t_group *groups, const char *id)
{
	t_group	*group;
	t_track	*found;

	if (!groups || !id || ft_strlen(id) == 0)
		return (NULL);
	group = groups;
	while (group)
	{
		found = ft_track_search(group->head, id);
		if (found)
			return (found->node);
		group = group->next;
	}
	return (NULL);
}
