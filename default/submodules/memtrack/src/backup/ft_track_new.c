/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_track_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:41:27 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:34:35 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_track_new - Crea un nuevo nodo de seguimiento para el backup.
 * @group_id: Clave del nodo.
 * @node: Puntero al nodo a agregar.
 * @return : puntero al t_track o NULL si no se puede crear.
 */

t_track	*ft_track_new(const char *group_id, const char *node_id, t_mt *node)
{
	t_track	*track;

	if (!group_id || !node)
		return (NULL);
	track = ft_calloc(1, sizeof(t_track));
	if (!track)
		return (NULL);
	track->group_id = ft_strdup(group_id);
	if (!track->group_id)
		return (free(track), NULL);
	track->id = ft_strdup(node_id);
	if (!track->id)
	{
		free(track->group_id);
		return (free(track), NULL);
	}
	track->node = node;
	track->next = NULL;
	return (track);
}
