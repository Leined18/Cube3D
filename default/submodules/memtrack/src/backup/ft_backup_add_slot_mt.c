/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_add_slot_mt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:39:39 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:47:06 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_add_slot_mt - Agrega un nodo a la lista de seguimiento del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @node: Puntero al nodo a agregar.
 *
 * Esta función agrega un nodo a la lista de seguimiento del backup,
 * asegurándose de que el nodo no esté ya presente en el backup.
 */

void	ft_backup_add_slot_mt(t_backup **backup, t_mt *node)
{
	t_slot	*slot;

	if (!backup || !*backup || !node)
		return ;
	if (!node->group_id || !node->id)
		return ;
	slot = ft_slot_hash_search((*backup)->slots, (*backup)->slot_count,
			node->id);
	if (slot)
		return ;
	ft_backup_add_slot(backup, ft_slot_new(node->id, node->group_id, node));
}
