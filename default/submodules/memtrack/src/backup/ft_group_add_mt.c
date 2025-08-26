/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group_add_mt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:18:30 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:43:35 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_group_add_mt - Agrega un nodo a un grupo.
 * @group: Doble puntero al grupo al que se agregará el nodo.
 * @node: Puntero al nodo a agregar.
 *
 * Esta función agrega un nodo a un grupo, asegurándose de que el grupo
 * exista y que el nodo no esté ya presente en el grupo.
 */

int	ft_group_add_mt(t_group **group, t_mt *node)
{
	t_track	*track;

	if (!group || !*group || !node || !node->group_id || !node->id)
		return (0);
	track = ft_track_new(node->group_id, node->id, node);
	if (!track)
		return (0);
	ft_track_add_back(&(*group)->head, track);
	(*group)->track_count++;
	return (1);
}
